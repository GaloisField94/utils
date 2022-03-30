#define N 312
#define M 156
#define WORD_A 0xB5026F5AA96619E9ULL
#define L_MASK 0xFFFFFFFF80000000ULL
#define R_MASK 0x000000007FFFFFFFULL
#define A_MASK 0x5555555555555555ULL
#define B_MASK 0x71D67FFFEDA60000ULL
#define C_MASK 0xFFF7EEE000000000ULL
#define U_SHIFT(x) (x >> 29)
#define S_SHIFT(x) (x << 17)
#define T_SHIFT(x) (x << 37)
#define L_SHIFT(x) (x >> 43)
#define INIT_PARAM_1 6364136223846793005ULL
#define INIT_PARAM_2 19650218ULL
#define INIT_PARAM_3 3935559000370003845ULL
#define INIT_PARAM_4 2862933555777941757ULL
#define XORSHIFT (generator->state[generator->iter - 1] ^ (generator->state[generator->iter - 1] >> 62))

#include "mt19937_64_t.h"

#include <stdlib.h>

static uint64_t a_value[2] = {0, WORD_A};

struct _mt19937_64_t {  
    uint64_t *state;
    size_t iter;
};

mt19937_64_t* mt19937_64_new() {
    mt19937_64_t* result = malloc(sizeof(mt19937_64_t));
    result->state = malloc(sizeof(uint64_t) * N);
    result->iter = N + 1;
    return result;
}

void mt19937_64_init(mt19937_64_t *generator, uint64_t seed) {
    generator->state[0] = seed;
    for(generator->iter = 1; generator->iter < N; generator->iter++) {
        generator->state[generator->iter] = (XORSHIFT + generator->iter) * INIT_PARAM_1;
    }
}

void mt19937_64_init_array(mt19937_64_t* generator, uint64_t* seeds, size_t seeds_len) {
    mt19937_64_init(generator, INIT_PARAM_2);
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
    generator->state[0] |= 0x8000000000000000ULL;
}

mt19937_64_result_t mt19937_64_generate(mt19937_64_t *generator) {
    if(generator->iter == N + 1) {
        return (mt19937_64_result_t){};
    }
    mt19937_64_result_t result = {.success = 1};
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
    result.number ^= U_SHIFT(result.number) & A_MASK;
    result.number ^= S_SHIFT(result.number) & B_MASK;
    result.number ^= T_SHIFT(result.number) & C_MASK;
    result.number ^= L_SHIFT(result.number);
    return result;
}