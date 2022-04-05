#include "natural_t.h"

#include <stdlib.h>
#include <stdio.h>

#define word_width 64
#define word_half_width (word_width / 2)

typedef uint64_t word_t; 
typedef word_t dword_t[2];
typedef struct _natural_t {
    word_t* words;
    size_t capacity;
    size_t size;
} natural_t;

natural_t* natural_from_str(const char* str, uint8_t base) {
    (void)str; (void)base;
    return malloc(sizeof(natural_t));
}

natural_t* natural_from_unsigned(uint64_t n) {
    natural_t* result = malloc(sizeof(natural_t));
    result->words = malloc(sizeof(word_t));
    result->words[0] = n;
    result->capacity = 1;
    result->size = 1;
    return result;
}

natural_t* natural_clone(const natural_t* src) {
    natural_t* result = malloc(sizeof(natural_t));
    result->words = malloc(sizeof(word_t) * src->size);
    for(size_t i = 0; i < src->size; i++) result->words[i] = src->words[i];
    result->capacity = src->size;
    result->size = src->size;
    return result;
}

natural_t* natural_add(const natural_t* op1, const natural_t* op2) {
    word_t carry = 0;
    const natural_t* widther = (op1->size >= op2->size ? op1 : op2);
    const natural_t* thinner = (op1->size < op2->size ? op1 : op2);
    natural_t* result = malloc(sizeof(natural_t));
    result->size = widther->size;
    result->capacity = result->size + 1;
    result->words = malloc(sizeof(word_t) * result->capacity);
    for (size_t i = 0; i < thinner->size; i++) {
        result->words[i] = widther->words[i] + thinner->words[i] + carry;
        carry = result->words[i] < widther->words[i];
    }
    for (size_t i = thinner->size; i < widther->size; i++) {
        result->words[i] = widther->words[i] + carry;
        carry = result->words[i] < widther->words[i];
    }
    result->words[result->size] = carry;
    result->size += carry;
    return result;    
}

natural_t* natural_add_unsigned(const natural_t* op1, uint64_t op2) {
    natural_t* result = malloc(sizeof(natural_t));
    result->size = op1->size;
    result->capacity = result->size + 1;
    result->words = malloc(sizeof(word_t) * result->capacity);
    result->words[0] = op1->words[0] + op2;
    word_t carry = result->words[0] < op1->words[0];
    for (size_t i = 1; i < op1->size; i++) {
        result->words[i] = op1->words[i] + carry;
        carry = result->words[i] < op1->words[i];
    }
    result->words[result->size] = carry;
    result->size += carry;
    return result;    
}

void natural_add_to(natural_t* rop, const natural_t* op) {
    (void)rop; (void)op;
}

static word_t add_dwords_carry(dword_t c, const dword_t a, const dword_t b) {
	c[1] = a[1] + b[1];
	c[0] = a[0] + b[0] + (word_t)(c[1] < a[1]); //identify overflow - true <=> sum < elem
	return (word_t)(c[0] < a[0]); //identify overflow - true <=> sum < elem
}

static void mult_words(dword_t c, const word_t a, const word_t b) {
	word_t a0 = a >> word_half_width, a1 = a & 0xFFFFFFFF;
	word_t b0 = b >> word_half_width, b1 = b & 0xFFFFFFFF;
	word_t mid_term = a0 * b1 + a1 + b0;
	c[0] = a0 * b0 + (mid_term >> word_half_width); //c = 2^{64}a0b0 + 2^{32}(a0b1 + a1b0) + a1b1
	c[1] = a1 * b1 + (mid_term << word_half_width); //thus upper half of mid term goes to lower half of c[0] and lower to upper of c[1]
}

natural_t* natural_mul(const natural_t* op1, const natural_t* op2) {
	(void)op1; (void)op2;
	return natural_from_unsigned(0);
}

size_t natural_size(const natural_t* op) {
    return op->size;
}

size_t natural_capacity(const natural_t* op) {
    return op->capacity;
}

void natural_print_words(const natural_t* op) {
    for (size_t i = 0; i < op->size; i++) {
        printf("0x%lX, ", op->words[i]);
    }
    printf("\n");
}

void natural_swap(natural_t** op1, natural_t** op2) {
    natural_t* tmp = *op1;
    *op1 = *op2;
    *op2 = tmp; 
}
