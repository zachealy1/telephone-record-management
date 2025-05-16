#include "../include/file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long load_phone_records(const char *filepath,
                                      phone_record_t **out_records) {
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        *out_records = NULL;
        return EXIT_FAILURE;
    }

    // Read the count
    unsigned long long n;
    if (fscanf(fp, "%llu\n", &n) != 1) {
        fclose(fp);
        *out_records = NULL;
        return EXIT_FAILURE;
    }

    // Allocate array
    phone_record_t *records = NULL;
    if (n > 0) {
        records = malloc(n * sizeof(phone_record_t));
        if (!records) {
            fclose(fp);
            *out_records = NULL;
            return EXIT_FAILURE;
        }

        // Parse each record line
        for (unsigned long long i = 0; i < n; ++i) {
            unsigned short year, country;
            unsigned long long phone;
            char name_buf[981];

            if (fscanf(fp, "%hu %hu %llu %980s\n",
                       &year, &country, &phone, name_buf) != 4) {
                // cleanup on parse error
                for (unsigned long long j = 0; j < i; ++j) {
                    free(records[j].full_name);
                }
                free(records);
                fclose(fp);
                *out_records = NULL;
                return EXIT_FAILURE;
            }

            records[i].year_created = year;
            records[i].country_code = country;
            records[i].phone_number = phone;

            // strdup the owner’s name
            unsigned long long len = strlen(name_buf) + 1;
            records[i].full_name = malloc(len);
            if (!records[i].full_name) {
                for (unsigned long long j = 0; j < i; ++j) {
                    free(records[j].full_name);
                }
                free(records);
                fclose(fp);
                *out_records = NULL;
                return EXIT_FAILURE;
            }
            memcpy(records[i].full_name, name_buf, len);
        }
    }

    fclose(fp);
    *out_records = records;
    return n;
}
