#ifndef PHONE_RECORD_H
#define PHONE_RECORD_H

/*
 * phone_record_t
 *
 * Represents a single phone directory entry, including the
 * subscriber’s number, country code, creation year, and name.
 *
 * Fields:
 *   phone_number  – the subscriber’s phone number (digits only, no separators)
 *   country_code  – the international dialling code for the number
 *   year_created  – four-digit year when this record was created
 *   full_name     – pointer to a dynamically allocated, null-terminated
 *                    string holding the subscriber’s full name
 */
typedef struct {
    unsigned long long phone_number;
    unsigned short      country_code;
    unsigned short      year_created;
    char               *full_name;
} phone_record_t;

#endif  /* PHONE_RECORD_H */
