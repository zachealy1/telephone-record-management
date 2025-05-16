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
 *   out_records – pointer to a phone_record_t*; on success, *out_records
 *                 will be set to point at the allocated array
 *
 * Returns:
 *   Number of records loaded on success.
 *   0 on failure (invalid arguments, I/O error, parse error or memory failure),
 *   and *out_records is set to NULL.
 */
unsigned long long load_phone_records(const char *filepath,
                                      phone_record_t **out_records) {
    /* Validate output pointer */
    if (!out_records) {
        return EXIT_FAILURE;
    }

    /* Attempt to open the file for reading */
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        *out_records = NULL;
        return EXIT_FAILURE;
    }

    /* Read number of records (first line of the file) */
    unsigned long long n;
    if (fscanf(fp, "%llu\n", &n) != 1) {
        /* Failed to read count */
        fclose(fp);
        *out_records = NULL;
        return EXIT_FAILURE;
    }

    phone_record_t *records = NULL;

    /* Only allocate if there is at least one record */
    if (n > 0) {
        records = malloc(n * sizeof(phone_record_t));
        if (!records) {
            /* Memory allocation failed */
            fclose(fp);
            *out_records = NULL;
            return EXIT_FAILURE;
        }

        /* Parse each record line by line */
        for (unsigned long long i = 0; i < n; ++i) {
            unsigned short year, country;
            unsigned long long phone;
            char name_buf[981]; /* Buffer for the full name (up to 980 chars) */

            /* Expect format: <year> <country> <phone> <name> */
            if (fscanf(fp, "%hu %hu %llu %980s\n",
                       &year, &country, &phone, name_buf) != 4) {
                /* Parse error: clean up any previously allocated names */
                for (unsigned long long j = 0; j < i; ++j) {
                    free(records[j].full_name);
                }
                free(records);
                fclose(fp);
                *out_records = NULL;
                return EXIT_FAILURE;
            }

            /* Populate record fields */
            records[i].year_created = year;
            records[i].country_code = country;
            records[i].phone_number = phone;

            /* Duplicate the name into heap memory */
            size_t len = strlen(name_buf) + 1;
            records[i].full_name = malloc(len);
            if (!records[i].full_name) {
                /* Allocation failure: clean up earlier allocations */
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

    /* Close file and hand back allocated records */
    fclose(fp);
    *out_records = records;
    return n;
}
