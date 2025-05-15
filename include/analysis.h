#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "phone_record.h"

unsigned short country_with_most_records(const phone_record_t *records, unsigned long long count);

bool phone_number_exists(const phone_record_t *records,
                         unsigned long long count,
                         unsigned short country_code,
                         unsigned int phone_number);

#endif
