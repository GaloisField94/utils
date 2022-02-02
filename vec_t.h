#ifndef _VEC_T_H_
#define _VEC_T_H_

#include <stddef.h>
#include <stdint.h>

#define vec_push(v, e) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_push, \
    vec_uint16_t*: vec_uint16_t_push)(v, e)

typedef struct _vec_uint8_t vec_uint8_t;
typedef struct _vec_uint16_t vec_uint16_t;

vec_uint8_t* vec_uint8_t_new();
vec_uint8_t* vec_uint8_t_with_capacity(size_t n);
void vec_uint8_t_push(vec_uint8_t* vec, uint8_t elem);
uint8_t vec_uint8_t_pop(vec_uint8_t* vec);
uint8_t vec_uint8_t_pop_unchecked(vec_uint8_t* vec);
uint8_t vec_uint8_t_get(const vec_uint8_t* vec, size_t index);
uint8_t vec_uint8_t_get_unchecked(const vec_uint8_t* vec, size_t index);
void vec_uint8_t_set(vec_uint8_t* vec, size_t index, uint8_t elem);
void vec_uint8_t_set_unchecked(vec_uint8_t* vec, size_t index, uint8_t elem);
size_t vec_uint8_t_size(const vec_uint8_t* vec);
size_t vec_uint8_t_capacity(const vec_uint8_t* vec);
void vec_uint8_t_free(vec_uint8_t* vec);
void vec_uint8_t_print(const vec_uint8_t* vec);

vec_uint16_t* vec_uint16_t_new();
vec_uint16_t* vec_uint16_t_with_capacity(size_t n);
void vec_uint16_t_push(vec_uint16_t* vec, uint16_t elem);
uint16_t vec_uint16_t_pop(vec_uint16_t* vec);
uint16_t vec_uint16_t_pop_unchecked(vec_uint16_t* vec);
uint16_t vec_uint16_t_get(const vec_uint16_t* vec, size_t index);
uint16_t vec_uint16_t_get_unchecked(const vec_uint16_t* vec, size_t index);
void vec_uint16_t_set(vec_uint16_t* vec, size_t index, uint16_t elem);
void vec_uint16_t_set_unchecked(vec_uint16_t* vec, size_t index, uint16_t elem);
size_t vec_uint16_t_size(const vec_uint16_t* vec);
size_t vec_uint16_t_capacity(const vec_uint16_t* vec);
void vec_uint16_t_free(vec_uint16_t* vec);
void vec_uint16_t_print(const vec_uint16_t* vec);

#endif
