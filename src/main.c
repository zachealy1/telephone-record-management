#include <stdio.h>
#include <stdlib.h>
#include "../include/analysis.h"
#include "../include/file_io.h"
#include "../include/phone_record.h"

int main(void) {
    // Task 1
    phone_record_t *book = load_phone_records("/Users/zachealy/development/repositories/telephone-record-management/P1-input-1.txt");
    if (!book) {
        fprintf(stderr, "Error: failed to load phone records from file.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 50; i++) {
        printf("%hu %hu %u %s\n",
            book[i].year_created,
            book[i].country_code,
            book[i].phone_number,
            book[i].full_name);
    }

    // Task 3
    printf("\n");
    printf("---------Task 3---------\n");
    const unsigned short top = country_with_most_records(book, 50);
    printf("Most popular country code is %hu\n", top);

    // Free book
    for (int i = 0; i < 50; ++i) {
        free(book[i].full_name);
    }

    free(book);

    return 0;
}
