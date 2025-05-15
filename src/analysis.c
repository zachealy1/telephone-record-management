#include "analysis.h"

unsigned short country_with_most_records(const phone_record_t *records, const size_t count) {
    int counts[1000] = {0};

    for (size_t i = 0; i < count; ++i) {
        const unsigned short code = records[i].country_code;
        counts[code]++;
    }

    unsigned short best_code = 0;
    int best_count = counts[0];
    for (int code = 1; code < 1000; ++code) {
        if (counts[code] > best_count) {
            best_count = counts[code];
            best_code  = (unsigned short)code;
        }
    }

    return best_code;
}