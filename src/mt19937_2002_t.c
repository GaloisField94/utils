#define N 624
#define M 397
#define WORD_A 0x9908B0DFUL
#define L_MASK 0x80000000UL
#define R_MASK 0x7FFFFFFFUL
#define B_MASK 0x9D2C5680UL
#define C_MASK 0xEFC60000UL
#define U_SHIFT(x) (x >> 11)
#define S_SHIFT(x) (x << 7)
#define T_SHIFT(x) (x << 15)
#define L_SHIFT(x) (x >> 18)
#define INIT_PARAM_1 1812433253UL
#define INIT_PARAM_2 19650218UL
#define INIT_PARAM_3 1664525UL
#define INIT_PARAM_4 1566083941UL
#define XORSHIFT (generator->state[generator->iter - 1] ^ (generator->state[generator->iter - 1] >> 30))

#include "mt19937_2002_t.h"

#include <stdlib.h>

static uint32_t a_value[2] = {0, WORD_A};

struct _mt19937_2002_t {  
    uint32_t *state;
    size_t iter;
};

mt19937_2002_t* mt19937_2002_new() {
    mt19937_2002_t* result = malloc(sizeof(mt19937_2002_t));
    result->state = malloc(sizeof(uint32_t) * N);
    result->iter = N + 1;
    return result;
}

void mt19937_2002_init(mt19937_2002_t *generator, uint32_t seed) {
    generator->state[0] = seed;
    for(generator->iter = 1; generator->iter < N; generator->iter++) {
        generator->state[generator->iter] = (XORSHIFT + generator->iter) * INIT_PARAM_1;
    }
}

void mt19937_2002_init_array(mt19937_2002_t* generator, uint32_t* seeds, size_t seeds_len) {
    mt19937_2002_init(generator, INIT_PARAM_2);
    size_t i = 1;
    for(generator->iter = 1; generator->iter < N; generator->iter++) {
        generator->state[generator->iter] = (generator->state[generator->iter] ^ (XORSHIFT * INIT_PARAM_3)) + seeds[i] + i;
        i++;
        i -= seeds_len * (i == seeds_len);
    }
    generator->state[0] = generator->state[N - 1];
    for(generator->iter = 1; generator->iter < N; generator->iter++) {
        generator->state[generator->iter] = (generator->state[generator->iter] ^ (XORSHIFT * INIT_PARAM_4)) - generator->iter;
    }
    generator->state[0] |= L_MASK;
}

mt19937_2002_result_t mt19937_2002_generate(mt19937_2002_t *generator) {
    if(generator->iter == N + 1) {
        return (mt19937_2002_result_t){};
    }
    mt19937_2002_result_t result = {.success = 1};
    if(generator->iter >= N) {
        size_t i;
        for(i = 0; i < N - M; i++) {
            result.number = (generator->state[i] & L_MASK) | (generator->state[i + 1] & R_MASK);
            generator->state[i] = generator->state[i + M] ^ (result.number >> 1) ^ a_value[result.number & 1];
        }
        for(; i < N - 1; i++) {
            result.number = (generator->state[i] & L_MASK) | (generator->state[i + 1] & R_MASK);
            generator->state[i] = generator->state[i + M - N] ^ (result.number >> 1) ^ a_value[result.number & 1];
        }
        result.number = (generator->state[N - 1] & L_MASK) | (generator->state[0] & R_MASK);
        generator->state[N - 1] = generator->state[M - 1] ^ (result.number >> 1) ^ a_value[result.number & 1];
        generator->iter = 0;
    }
    result.number = generator->state[generator->iter++];
    result.number ^= U_SHIFT(result.number);
    result.number ^= S_SHIFT(result.number) & B_MASK;
    result.number ^= T_SHIFT(result.number) & C_MASK;
    result.number ^= L_SHIFT(result.number);
    return result;
}