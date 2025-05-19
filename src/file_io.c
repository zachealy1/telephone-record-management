#include "../include/file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * load_phone_records
 *
 * Load phone records from a text file into a dynamically allocated array.
 *
 * Parameters:
 *   filepath    – path to the file containing phone records
 *   out_records – pointer to a phone_record_t*; *out_records
 *                 will be set to point at the allocated array
 *
 * Returns:
 *   Number of records loaded on success.
 */
unsigned long long load_phone_records(const char *filepath,
                                      phone_record_t **out_records) {
    /* Open the file for reading */
    FILE *fp = fopen(filepath, "r");

    /* Read number of records */
    unsigned long long n;
    fscanf(fp, "%llu\n", &n);

    /* Allocate array of records */
    phone_record_t *records = malloc(n * sizeof(phone_record_t));

    /* Read each record assuming well-formed input */
    for (unsigned long long i = 0; i < n; ++i) {
        unsigned short year;
        unsigned short country;
        unsigned long long phone;
        char name_buf[981];

        /* Format: <year> <country> <phone> <name> */
        fscanf(fp, "%hu %hu %llu %980s\n",
               &year, &country, &phone, name_buf);

        records[i].year_created = year;
        records[i].country_code = country;
        records[i].phone_number = phone;

        /* Duplicate the name into heap memory */
        unsigned short len = strlen(name_buf) + 1;
        records[i].full_name = malloc(len);
        memcpy(records[i].full_name, name_buf, len);
    }

    fclose(fp);

    *out_records = records;
    return n;
}
