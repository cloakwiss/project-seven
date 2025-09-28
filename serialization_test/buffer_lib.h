#ifndef BUFFER_LIB_H
#define BUFFER_LIB_H

#include "geometry.h"
#include "sugars.h"

// Function declarations
u8 *get_buffer(u64 *len);
void free_buffer(u8 *buffer);

#endif
