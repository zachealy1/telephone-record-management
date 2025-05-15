#include <stdio.h>
#include <stdlib.h>
#include "../include/analysis.h"
#include "../include/file_io.h"
#include "../include/phone_record.h"

int main(void) {
    // Task 2
    phone_record_t *book = nullptr;
    const unsigned long long count = load_phone_records(
        "/Users/zachealy/development/repositories/telephone-record-management/P2-input-2.txt",
        &book
    );

    if (!book && count == 0) {
        fprintf(stderr, "Failed to load records\n");
        return EXIT_FAILURE;
    }

    printf("Loaded %llu records\n\n", count);

    for (unsigned long long i = 0; i < count; ++i) {
        printf("%hu %hu %llu  %s\n",
            book[i].year_created,
            book[i].country_code,
            book[i].phone_number,
            book[i].full_name
        );
    }

    // Task 3
    printf("\n");
    printf("---------Task 3---------\n");
    const unsigned short top = country_with_most_records(book, 50);
    printf("Most popular country code is %hu\n", top);

    // Free book
    for (unsigned long long i = 0; i < count; ++i) {
        free(book[i].full_name);
    }
    free(book);

    return 0;
}
