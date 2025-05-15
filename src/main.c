#include <stdio.h>
#include <stdlib.h>
#include "../include/file_io.h"
#include "../include/phone_record.h"

int main(void) {
    phone_record_t *book = load_phone_records("/Users/zachealy/development/repositories/telephone-record-management/P1-input-1.txt");
    if (!book) {
        fprintf(stderr, "Error: failed to load phone records from file.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 50; i++) {
        printf("%u %u %llu %s\n",
            book[i].year_created,
            book[i].country_code,
            book[i].phone_number,
            book[i].full_name);
    }

    for (int i = 0; i < 50; ++i) {
        free(book[i].full_name);
    }

    free(book);
    return 0;
}
