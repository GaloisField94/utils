#ifndef _NATURAL_H_T_
#define _NATURAL_H_T_

#include <stddef.h>
#include <stdint.h>

typedef struct _natural_t natural_t;

natural_t* from_str(const char* str, uint8_t base);
natural_t* from_unsigned(uint64_t n);
natural_t* clone(const natural_t* src);
natural_t* add(const natural_t* op1, const natural_t* op2); //ret op1 + op2
natural_t* add_unsigned(const natural_t* op1, uint64_t op2); //ret op1 + op2
void add_to(natural_t* rop, const natural_t* op); //rop += op

size_t natural_size(const natural_t* op);
size_t natural_capacity(const natural_t* op);
void natural_print_words(const natural_t* op);

#endif