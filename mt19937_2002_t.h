#ifndef _MT19937_2002_H_
#define _MT19937_2002_H_

#include <stddef.h>
#include <stdint.h>

typedef struct _mt19937_2002_t mt19937_2002_t;
typedef struct {
    int success;
    uint32_t number;
} mt19937_2002_result_t;

mt19937_2002_t* mt19937_2002_new();
void mt19937_2002_init(mt19937_2002_t* generator, uint32_t seed);
void mt19937_2002_init_array(mt19937_2002_t* generator, uint32_t* seeds, size_t seeds_len);
mt19937_2002_result_t mt19937_2002_generate(mt19937_2002_t* generator);

#endif
