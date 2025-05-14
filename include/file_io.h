#ifndef FILE_IO_H
#define FILE_IO_H

#include "phone_record.h"

/**
 * Load exactly 50 phone_record_t structs from the text file at `filepath`.
 * Returns a malloc’d array of 50 records (or NULL on failure).
 */
phone_record_t *load_phone_records(const char *filepath);

#endif
