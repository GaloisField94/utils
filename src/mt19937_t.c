#define N 624
#define M 397
#define WORD_A 0x9908B0DF
#define L_MASK 0x80000000
#define R_MASK 0x7FFFFFFF
#define B_MASK 0x9D2C5680
#define C_MASK 0xEFC60000
#define U_SHIFT(x) (x >> 11)
#define S_SHIFT(x) (x << 7)
#define T_SHIFT(x) (x << 15)
#define L_SHIFT(x) (x >> 18)
#define INIT_PARAM 69069

#include "mt19937_t.h"

#include <stddef.h>
#include <stdlib.h>

static uint32_t a_value[2] = {0, WORD_A};

struct _mt19937_t {  
    uint32_t *state;
    size_t iter;
};

mt19937_t* mt19937_new() {
    mt19937_t* result = malloc(sizeof(mt19937_t));
    result->state = malloc(sizeof(uint32_t) * N);
    result->iter = N + 1;
    return result;
}

void mt19937_init(mt19937_t *generator, uint32_t seed) {
    generator->state[0] = seed;
    for(generator->iter = 1; generator->iter < N; generator->iter++) {
        generator->state[generator->iter] = generator->state[generator->iter - 1] * INIT_PARAM;
    }
}

mt19937_result_t mt19937_generate(mt19937_t *generator) {
    if(generator->iter == N + 1) {
        return (mt19937_result_t){};
    }
    mt19937_result_t result = {.success = 1};
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