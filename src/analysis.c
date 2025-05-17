#include "analysis.h"

/*
 * country_with_most_records
 *
 * Determine which country code appears most frequently in the given
 * array of phone records.
 *
 * Parameters:
 *   records – pointer to an array of phone_record_t entries
 *   count   – number of entries in the array
 *
 * Returns:
 *   The country code (0–999) that has the highest number of records.
 *   If the array is empty, behaviour is undefined (returns 0).
 */
unsigned short country_with_most_records(const phone_record_t *records, const unsigned long long count) {
    // Array to tally occurrences for country codes 0 through 999
    int counts[1000] = {0};

    // Increment the count for each record's country code
    for (unsigned long long i = 0; i < count; ++i) {
        const unsigned short code = records[i].country_code;
        counts[code]++;
    }

    // Identify which code has the greatest tally
    unsigned short best_code = 0;
    int best_count = counts[0];
    for (int code = 1; code < 1000; ++code) {
        if (counts[code] > best_count) {
            best_count = counts[code];
            best_code = code;
        }
    }

    return best_code;
}

/*
 * phone_number_exists
 *
 * Check whether a specified phone number (including its country code)
 * exists within the array of phone records.
 *
 * Parameters:
 *   records      – pointer to an array of phone_record_t entries
 *   count        – number of entries in the array
 *   country_code – the country code to search for
 *   phone_number – the local phone number to search for
 *
 * Returns:
 *   true if a matching record is found; false otherwise.
 */
bool phone_number_exists(const phone_record_t *records,
                         const unsigned long long count,
                         const unsigned short country_code,
                         const unsigned long long phone_number) {
    // Iterate through each record and compare both fields
    for (unsigned long long i = 0; i < count; ++i) {
        if (records[i].country_code == country_code &&
            records[i].phone_number == phone_number) {
            return true; // Match found
        }
    }

    return false; // No matching record in the array
}
