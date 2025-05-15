#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <stdio.h>

#include "phone_record.h"

unsigned short country_with_most_records(const phone_record_t *records, size_t count);

#endif
