#ifndef FILE_IO_H
#define FILE_IO_H

#include "phone_record.h"

/*
 * load_phone_records
 *
 * Load phone records from the specified file into dynamically allocated memory.
 *
 * Parameters:
 *   filepath    - path to the input file containing phone record entries
 *   out_records - pointer to a phone_record_t*; on success, will point to
 *                 an array of records allocated on the heap
 *
 * Returns:
 *   The number of records successfully loaded. On failure (e.g. file I/O
 *   error or memory allocation failure), returns 0 and sets *out_records to NULL.
 */
unsigned long long load_phone_records(const char *filepath,
                                      phone_record_t **out_records);

#endif  /* FILE_IO_H */
