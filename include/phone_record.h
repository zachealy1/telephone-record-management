#ifndef PHONE_RECORD_H
#define PHONE_RECORD_H

#include <stdint.h>

typedef struct {
    uint64_t phone_number;
    uint16_t country_code;
    uint16_t year_created;
    char *full_name;
} phone_record_t;

#endif
