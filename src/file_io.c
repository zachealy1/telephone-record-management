#include "../include/file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define RECORD_COUNT 50

phone_record_t *load_phone_records(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (!fp) return NULL;

    phone_record_t *records = malloc(RECORD_COUNT * sizeof *records);
    if (!records) {
        fclose(fp);
        return NULL;
    }

    for (size_t i = 0; i < RECORD_COUNT; ++i) {
        unsigned    year, country;
        unsigned long long phone;
        char        name_buf[1001];

        if (fscanf(fp, "%u %u %llu %1000s",
                   &year, &country, &phone, name_buf) != 4) {
            // parse error: clean up and abort
            for (size_t j = 0; j < i; ++j) free(records[j].full_name);
            free(records);
            fclose(fp);
            return NULL;
                   }

        records[i].year_created  = (uint16_t) year;
        records[i].country_code  = (uint16_t) country;
        records[i].phone_number  = (uint64_t) phone;

        // allocate and copy the owner’s name
        size_t len = strlen(name_buf) + 1;
        records[i].full_name = malloc(len);
        if (!records[i].full_name) {
            for (size_t j = 0; j < i; ++j) free(records[j].full_name);
            free(records);
            fclose(fp);
            return NULL;
        }
        memcpy(records[i].full_name, name_buf, len);
    }

    fclose(fp);
    return records;
}
