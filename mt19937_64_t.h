#ifndef _MT19937_64_H_
#define _MT19937_64_H_

#include <stddef.h>
#include <stdint.h>

typedef struct _mt19937_64_t mt19937_64_t;
typedef struct {
    int success;
    uint64_t number;
} mt19937_64_result_t;

mt19937_64_t* mt19937_64_new();
void mt19937_64_init(mt19937_64_t* generator, uint64_t seed);
void mt19937_64_init_array(mt19937_64_t* generator, uint64_t* seeds, size_t seeds_len);
mt19937_64_result_t mt19937_64_generate(mt19937_64_t* generator);

#endif
