#ifndef PHONE_RECORD_H
#define PHONE_RECORD_H

typedef struct {
    unsigned int phone_number;
    unsigned short country_code;
    unsigned short year_created;
    char *full_name;
} phone_record_t;

#endif
