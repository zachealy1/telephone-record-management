#ifndef FILE_IO_H
#define FILE_IO_H

#include "phone_record.h"

/*
 * load_phone_records
 *
 * Load phone records from a text file into a dynamically allocated array.
 *
 * Parameters:
 *   filepath    – path to the file containing phone records
 *   out_records – pointer to a phone_record_t*; *out_records
 *                 will be set to point at the allocated array
 *
 * Returns:
 *   Number of records loaded on success.
 */
unsigned long long load_phone_records(const char *filepath,
                                      phone_record_t **out_records);

#endif  /* FILE_IO_H */
