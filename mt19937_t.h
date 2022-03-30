#ifndef _MT19937_H_
#define _MT19937_H_

#include <stdint.h>

typedef struct _mt19937_t mt19937_t;
typedef struct {
    int success;
    uint32_t number;
} mt19937_result_t;

mt19937_t* mt19937_new();
void mt19937_init(mt19937_t* generator, uint32_t seed);
mt19937_result_t mt19937_generate(mt19937_t* generator);

#endif
