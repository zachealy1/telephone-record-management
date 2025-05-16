#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "phone_record.h"

/*
 * country_with_most_records
 *
 * Determine which country code has the greatest number of phone records
 * in the provided array.
 *
 * Parameters:
 *   records - pointer to an array of phone_record_t entries
 *   count   - number of entries in the array
 *
 * Returns:
 *   The country code (unsigned short) that appears most frequently
 *   among the records. If the array is empty, behaviour is undefined.
 */
unsigned short country_with_most_records(const phone_record_t *records,
                                         unsigned long long count);

/*
 * phone_number_exists
 *
 * Check whether a particular phone number exists within the records
 * for a specified country code.
 *
 * Parameters:
 *   records      - pointer to an array of phone_record_t entries
 *   count        - number of entries in the array
 *   country_code - the country code to search within
 *   phone_number - the phone number to look for
 *
 * Returns:
 *   true  if a record matches both the given country code and phone number;
 *   false otherwise.
 */
bool phone_number_exists(const phone_record_t *records,
                         unsigned long long count,
                         unsigned short country_code,
                         unsigned long long phone_number);

#endif  /* ANALYSIS_H */
