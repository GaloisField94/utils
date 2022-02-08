#include "natural_t.h"

#include <stdlib.h>
#include <stdio.h>

typedef uint64_t word_t; 
typedef struct _natural_t {
    word_t* words;
    size_t capacity;
    size_t size;
} natural_t;

static void swap(void** op1, void** op2) {
    void* tmp = *op1;
    *op1 = *op2;
    *op2 = tmp; 
}

natural_t* from_str(const char* str, uint8_t base) {
    (void)str; (void)base;
    return malloc(sizeof(natural_t));
}

natural_t* from_unsigned(uint64_t n) {
    natural_t* result = malloc(sizeof(natural_t));
    result->words = malloc(sizeof(word_t));
    result->words[0] = n;
    result->capacity = 1;
    result->size = 1;
    return result;
}

natural_t* clone(const natural_t* src) {
    natural_t* result = malloc(sizeof(natural_t));
    result->words = malloc(sizeof(word_t) * src->size);
    for(size_t i = 0; i < src->size; i++) result->words[i] = src->words[i];
    result->capacity = src->size;
    result->size = src->size;
    return result;
}

natural_t* add(const natural_t* op1, const natural_t* op2) {
    word_t carry = 0;
    //assure op1->size >= op2->size
    if(op1->size < op2->size) swap(&op1, &op2);
    natural_t* result = malloc(sizeof(natural_t));
    result->size = op1->size;
    result->capacity = result->size + 1;
    result->words = malloc(sizeof(word_t) * result->capacity);
    for (size_t i = 0; i < op2->size; i++) {
        result->words[i] = op1->words[i] + op2->words[i] + carry;
        carry = result->words[i] < op1->words[i];
    }
    for (size_t i = op2->size; i < op1->size; i++) {
        result->words[i] = op1->words[i] + carry;
        carry = result->words[i] < op1->words[i];
    }
    result->words[result->size] = carry;
    result->size += carry;
    return result;    
}

natural_t* add_unsigned(const natural_t* op1, uint64_t op2) {
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

void add_to(natural_t* rop, const natural_t* op) {
    (void)rop; (void)op;
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