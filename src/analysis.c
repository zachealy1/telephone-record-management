#include "analysis.h"

unsigned short country_with_most_records(const phone_record_t *records, const unsigned long long count) {
    int counts[1000] = {0};

    for (unsigned long long i = 0; i < count; ++i) {
        const unsigned short code = records[i].country_code;
        counts[code]++;
    }

    unsigned short best_code = 0;
    int best_count = counts[0];
    for (int code = 1; code < 1000; ++code) {
        if (counts[code] > best_count) {
            best_count = counts[code];
            best_code = (unsigned short) code;
        }
    }

    return best_code;
}

bool phone_number_exists(const phone_record_t *records,
                         const unsigned long long count,
                         const unsigned short country_code,
                         const unsigned long long phone_number) {
    for (unsigned long long i = 0; i < count; ++i) {
        if (records[i].country_code == country_code &&
            records[i].phone_number == phone_number) {
            return true;
        }
    }
    return false;
}
