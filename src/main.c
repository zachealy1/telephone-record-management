#include <stdio.h>
#include <stdlib.h>

#include "../include/trie.h"
#include "../include/analysis.h"
#include "../include/file_io.h"
#include "../include/phone_record.h"

int main(int argc, char *argv[]) {
    // Verify that an input file has been provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *filepath = argv[1];

    // Task 2 and 4: load records from file and report how many were loaded
    printf("---------Task 2 and 4---------\n");
    phone_record_t *book = NULL;
    const unsigned long long count = load_phone_records(filepath, &book);

    // Ensure records were loaded successfully
    if (!book || count == 0) {
        fprintf(stderr, "Failed to load records\n");
        return EXIT_FAILURE;
    }
    printf("Number of records loaded: %llu\n", count);

    // Uncomment to print every loaded record:
    // for (unsigned long long i = 0; i < count; ++i) {
    //     printf("%hu %hu %llu  %s\n",
    //            book[i].year_created,
    //            book[i].country_code,
    //            book[i].phone_number,
    //            book[i].full_name);
    // }

    printf("Last record in file: %hu %hu %llu  %s\n",
           book[count - 1].year_created,
           book[count - 1].country_code,
           book[count - 1].phone_number,
           book[count - 1].full_name);

    // Task 3: determine the most common country code
    printf("\n");
    printf("---------Task 3---------\n");
    const unsigned short top = country_with_most_records(book, count);
    printf("Most popular country code is %hu\n", top);

    // Task 5: check if specific numbers are already registered (linear search)
    printf("\n");
    printf("---------Task 5---------\n");
    printf("---------Unregistered number---------\n");
    if (phone_number_exists(book, count, 44, 1792305678ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    printf("\n");
    printf("---------Registered number---------\n");
    if (phone_number_exists(book, count, 8, 2822773326448ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    // Task 6: use a trie for efficient lookups
    printf("\n");
    printf("---------Task 6---------\n");
    trie_node_t *root = calloc(1, sizeof(trie_node_t));

    // Insert two sample numbers into the trie
    trie_insert(root, 9, 80423902ULL);
    trie_insert(root, 44, 1792305678ULL);

    // Search for the first number in the trie
    printf("---------Checking first number via Trie---------\n");
    if (trie_search(root, 9, 80423902ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    // Search for the second number in the trie
    printf("\n---------Checking second number via Trie---------\n");
    if (trie_search(root, 44, 1792305678ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    // Search for non-existent number in the trie
    printf("\n---------Checking second number via Trie---------\n");
    if (trie_search(root, 44, 1792305679ULL)) {
        printf("That number is already registered!\n");
    } else {
        printf("Number is free to register.\n");
    }

    // Release all memory used by the trie
    trie_free(root);

    // Free the phone book: each name, then the array itself
    for (unsigned long long i = 0; i < count; ++i) {
        free(book[i].full_name);
    }
    free(book);

    return 0;
}
