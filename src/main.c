#include <stdio.h>
#include <stdlib.h>

#include "../include/trie.h"
#include "../include/analysis.h"
#include "../include/file_io.h"
#include "../include/phone_record.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *filepath = argv[1];

    // Task 2 and 4
    printf("---------Task 2 and 4---------\n");
    phone_record_t *book = nullptr;
    const unsigned long long count = load_phone_records(filepath, &book);

    if (!book && count == 0) {
        fprintf(stderr, "Failed to load records\n");
        return EXIT_FAILURE;
    }

    printf("Loaded %llu records\n", count);

    // for (unsigned long long i = 0; i < count; ++i) {
    //     printf("%hu %hu %llu  %s\n",
    //            book[i].year_created,
    //            book[i].country_code,
    //            book[i].phone_number,
    //            book[i].full_name
    //     );
    // }

    // Task 3
    printf("\n");
    printf("---------Task 3---------\n");
    const unsigned short top = country_with_most_records(book, count);
    printf("Most popular country code is %hu\n", top);

    // Task 5
    printf("\n");
    printf("---------Task 3---------\n");
    printf("---------Unregistered number---------\n");
    if (phone_number_exists(book, count, 44, 1792305678ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    printf("\n");
    printf("---------Registered number---------\n");
    if (phone_number_exists(book, count, 1, 1361821878280ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    // Task 6
    printf("\n");
    printf("---------Task 6---------\n");
    trie_node_t *root = calloc(1, sizeof *root);

    trie_insert(root, 9, 80423902ULL);
    trie_insert(root, 44, 1792305678ULL);

    printf("---------Checking first number via Trie---------\n");
    if (trie_search(root, 9, 80423902ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    printf("\n---------Checking second number via Trie---------\n");
    if (trie_search(root, 44, 1792305678ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    // Free trie
    trie_free(root);

    // Free book
    for (unsigned long long i = 0; i < count; ++i) {
        free(book[i].full_name);
    }
    free(book);

    return 0;
}
