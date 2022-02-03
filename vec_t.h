#ifndef _VEC_T_H_
#define _VEC_T_H_

#include <stddef.h>
#include <stdint.h>

//------------------||
//--- structures ---||
//------------------||

typedef struct _vec_uint8_t vec_uint8_t;
typedef struct _vec_uint16_t vec_uint16_t;
typedef struct _vec_uint32_t vec_uint32_t;
typedef struct _vec_uint64_t vec_uint64_t;
typedef struct _vec_int8_t vec_int8_t;
typedef struct _vec_int16_t vec_int16_t;
typedef struct _vec_int32_t vec_int32_t;
typedef struct _vec_int64_t vec_int64_t;

//--------------------||
//--- constructors ---||
//--------------------||

vec_uint8_t* vec_uint8_t_new();
vec_uint8_t* vec_uint8_t_with_capacity(size_t n);
vec_uint16_t* vec_uint16_t_new();
vec_uint16_t* vec_uint16_t_with_capacity(size_t n);
vec_uint32_t* vec_uint32_t_new();
vec_uint32_t* vec_uint32_t_with_capacity(size_t n);
vec_uint64_t* vec_uint64_t_new();
vec_uint64_t* vec_uint64_t_with_capacity(size_t n);
vec_int8_t* vec_int8_t_new();
vec_int8_t* vec_int8_t_with_capacity(size_t n);
vec_int16_t* vec_int16_t_new();
vec_int16_t* vec_int16_t_with_capacity(size_t n);
vec_int32_t* vec_int32_t_new();
vec_int32_t* vec_int32_t_with_capacity(size_t n);
vec_int64_t* vec_int64_t_new();
vec_int64_t* vec_int64_t_with_capacity(size_t n);

//-------------------------------||
//--- templates for functions ---||
//-------------------------------||

#define vec_push(v, e) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_push, \
    vec_uint16_t*: vec_uint16_t_push, \
    vec_uint32_t*: vec_uint32_t_push, \
    vec_uint64_t*: vec_uint64_t_push, \
    vec_int8_t*: vec_int8_t_push, \
    vec_int16_t*: vec_int16_t_push, \
    vec_int32_t*: vec_int32_t_push, \
    vec_int64_t*: vec_int64_t_push)(v, e)

#define vec_push_unchecked(v, e) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_push_unchecked, \
    vec_uint16_t*: vec_uint16_t_push_unchecked, \
    vec_uint32_t*: vec_uint32_t_push_unchecked, \
    vec_uint64_t*: vec_uint64_t_push_unchecked, \
    vec_int8_t*: vec_int8_t_push_unchecked, \
    vec_int16_t*: vec_int16_t_push_unchecked, \
    vec_int32_t*: vec_int32_t_push_unchecked, \
    vec_int64_t*: vec_int64_t_push_unchecked)(v, e)

#define vec_pop(v) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_pop, \
    vec_uint16_t*: vec_uint16_t_pop, \
    vec_uint32_t*: vec_uint32_t_pop, \
    vec_uint64_t*: vec_uint64_t_pop, \
    vec_int8_t*: vec_int8_t_pop, \
    vec_int16_t*: vec_int16_t_pop, \
    vec_int32_t*: vec_int32_t_pop, \
    vec_int64_t*: vec_int64_t_pop)(v)

#define vec_pop_unchecked(v) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_pop_unchecked, \
    vec_uint16_t*: vec_uint16_t_pop_unchecked, \
    vec_uint32_t*: vec_uint32_t_pop_unchecked, \
    vec_uint64_t*: vec_uint64_t_pop_unchecked, \
    vec_int8_t*: vec_int8_t_pop_unchecked, \
    vec_int16_t*: vec_int16_t_pop_unchecked, \
    vec_int32_t*: vec_int32_t_pop_unchecked, \
    vec_int64_t*: vec_int64_t_pop_unchecked)(v)

#define vec_set(v, i) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_set, \
    vec_uint16_t*: vec_uint16_t_set, \
    vec_uint32_t*: vec_uint32_t_set, \
    vec_uint64_t*: vec_uint64_t_set, \
    vec_int8_t*: vec_int8_t_set, \
    vec_int16_t*: vec_int16_t_set, \
    vec_int32_t*: vec_int32_t_set, \
    vec_int64_t*: vec_int64_t_set)(v, i)

#define vec_set_unchecked(v, i) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_set_unchecked, \
    vec_uint16_t*: vec_uint16_t_set_unchecked, \
    vec_uint32_t*: vec_uint32_t_set_unchecked, \
    vec_uint64_t*: vec_uint64_t_set_unchecked, \
    vec_int8_t*: vec_int8_t_set_unchecked, \
    vec_int16_t*: vec_int16_t_set_unchecked, \
    vec_int32_t*: vec_int32_t_set_unchecked, \
    vec_int64_t*: vec_int64_t_set_unchecked)(v, i)

#define vec_get(v, i) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_get, \
    vec_uint16_t*: vec_uint16_t_get, \
    vec_uint32_t*: vec_uint32_t_get, \
    vec_uint64_t*: vec_uint64_t_get, \
    vec_int8_t*: vec_int8_t_get, \
    vec_int16_t*: vec_int16_t_get, \
    vec_int32_t*: vec_int32_t_get, \
    vec_int64_t*: vec_int64_t_get)(v, i)

#define vec_get_unchecked(v, i) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_get_unchecked, \
    vec_uint16_t*: vec_uint16_t_get_unchecked, \
    vec_uint32_t*: vec_uint32_t_get_unchecked, \
    vec_uint64_t*: vec_uint64_t_get_unchecked, \
    vec_int8_t*: vec_int8_t_get_unchecked, \
    vec_int16_t*: vec_int16_t_get_unchecked, \
    vec_int32_t*: vec_int32_t_get_unchecked, \
    vec_int64_t*: vec_int64_t_get_unchecked)(v, i)

#define vec_size(v) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_size, \
    vec_uint16_t*: vec_uint16_t_size, \
    vec_uint32_t*: vec_uint32_t_size, \
    vec_uint64_t*: vec_uint64_t_size, \
    vec_int8_t*: vec_int8_t_size, \
    vec_int16_t*: vec_int16_t_size, \
    vec_int32_t*: vec_int32_t_size, \
    vec_int64_t*: vec_int64_t_size)(v)

#define vec_capacity(v) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_capacity, \
    vec_uint16_t*: vec_uint16_t_capacity, \
    vec_uint32_t*: vec_uint32_t_capacity, \
    vec_uint64_t*: vec_uint64_t_capacity, \
    vec_int8_t*: vec_int8_t_capacity, \
    vec_int16_t*: vec_int16_t_capacity, \
    vec_int32_t*: vec_int32_t_capacity, \
    vec_int64_t*: vec_int64_t_capacity)(v)

#define vec_free(v) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_free, \
    vec_uint16_t*: vec_uint16_t_free, \
    vec_uint32_t*: vec_uint32_t_free, \
    vec_uint64_t*: vec_uint64_t_free, \
    vec_int8_t*: vec_int8_t_free, \
    vec_int16_t*: vec_int16_t_free, \
    vec_int32_t*: vec_int32_t_free, \
    vec_int64_t*: vec_int64_t_free)(v)

#define vec_print(v) _Generic((v), \
    vec_uint8_t*: vec_uint8_t_print, \
    vec_uint16_t*: vec_uint16_t_print, \
    vec_uint32_t*: vec_uint32_t_print, \
    vec_uint64_t*: vec_uint64_t_print, \
    vec_int8_t*: vec_int8_t_print, \
    vec_int16_t*: vec_int16_t_print, \
    vec_int32_t*: vec_int32_t_print, \
    vec_int64_t*: vec_int64_t_print)(v)

//------------------------------||
//--- functions declarations ---||
//------------------------------||

void vec_uint8_t_push(vec_uint8_t* vec, uint8_t elem);
void vec_uint8_t_push_unchecked(vec_uint8_t* vec, uint8_t elem);
uint8_t vec_uint8_t_pop(vec_uint8_t* vec);
uint8_t vec_uint8_t_pop_unchecked(vec_uint8_t* vec);
void vec_uint8_t_set(vec_uint8_t* vec, size_t index, uint8_t elem);
void vec_uint8_t_set_unchecked(vec_uint8_t* vec, size_t index, uint8_t elem);
uint8_t vec_uint8_t_get(const vec_uint8_t* vec, size_t index);
uint8_t vec_uint8_t_get_unchecked(const vec_uint8_t* vec, size_t index);
size_t vec_uint8_t_size(const vec_uint8_t* vec);
size_t vec_uint8_t_capacity(const vec_uint8_t* vec);
void vec_uint8_t_free(vec_uint8_t* vec);
void vec_uint8_t_print(const vec_uint8_t* vec);

void vec_uint16_t_push(vec_uint16_t* vec, uint16_t elem);
void vec_uint16_t_push_unchecked(vec_uint16_t* vec, uint16_t elem);
uint16_t vec_uint16_t_pop(vec_uint16_t* vec);
uint16_t vec_uint16_t_pop_unchecked(vec_uint16_t* vec);
void vec_uint16_t_set(vec_uint16_t* vec, size_t index, uint16_t elem);
void vec_uint16_t_set_unchecked(vec_uint16_t* vec, size_t index, uint16_t elem);
uint16_t vec_uint16_t_get(const vec_uint16_t* vec, size_t index);
uint16_t vec_uint16_t_get_unchecked(const vec_uint16_t* vec, size_t index);
size_t vec_uint16_t_size(const vec_uint16_t* vec);
size_t vec_uint16_t_capacity(const vec_uint16_t* vec);
void vec_uint16_t_free(vec_uint16_t* vec);
void vec_uint16_t_print(const vec_uint16_t* vec);

void vec_uint32_t_push(vec_uint32_t* vec, uint32_t elem);
void vec_uint32_t_push_unchecked(vec_uint32_t* vec, uint32_t elem);
uint32_t vec_uint32_t_pop(vec_uint32_t* vec);
uint32_t vec_uint32_t_pop_unchecked(vec_uint32_t* vec);
void vec_uint32_t_set(vec_uint32_t* vec, size_t index, uint32_t elem);
void vec_uint32_t_set_unchecked(vec_uint32_t* vec, size_t index, uint32_t elem);
uint32_t vec_uint32_t_get(const vec_uint32_t* vec, size_t index);
uint32_t vec_uint32_t_get_unchecked(const vec_uint32_t* vec, size_t index);
size_t vec_uint32_t_size(const vec_uint32_t* vec);
size_t vec_uint32_t_capacity(const vec_uint32_t* vec);
void vec_uint32_t_free(vec_uint32_t* vec);
void vec_uint32_t_print(const vec_uint32_t* vec);

void vec_uint64_t_push(vec_uint64_t* vec, uint64_t elem);
void vec_uint64_t_push_unchecked(vec_uint64_t* vec, uint64_t elem);
uint64_t vec_uint64_t_pop(vec_uint64_t* vec);
uint64_t vec_uint64_t_pop_unchecked(vec_uint64_t* vec);
void vec_uint64_t_set(vec_uint64_t* vec, size_t index, uint64_t elem);
void vec_uint64_t_set_unchecked(vec_uint64_t* vec, size_t index, uint64_t elem);
uint64_t vec_uint64_t_get(const vec_uint64_t* vec, size_t index);
uint64_t vec_uint64_t_get_unchecked(const vec_uint64_t* vec, size_t index);
size_t vec_uint64_t_size(const vec_uint64_t* vec);
size_t vec_uint64_t_capacity(const vec_uint64_t* vec);
void vec_uint64_t_free(vec_uint64_t* vec);
void vec_uint64_t_print(const vec_uint64_t* vec);

void vec_int8_t_push(vec_int8_t* vec, int8_t elem);
void vec_int8_t_push_unchecked(vec_int8_t* vec, int8_t elem);
int8_t vec_int8_t_pop(vec_int8_t* vec);
int8_t vec_int8_t_pop_unchecked(vec_int8_t* vec);
void vec_int8_t_set(vec_int8_t* vec, size_t index, int8_t elem);
void vec_int8_t_set_unchecked(vec_int8_t* vec, size_t index, int8_t elem);
int8_t vec_int8_t_get(const vec_int8_t* vec, size_t index);
int8_t vec_int8_t_get_unchecked(const vec_int8_t* vec, size_t index);
size_t vec_int8_t_size(const vec_int8_t* vec);
size_t vec_int8_t_capacity(const vec_int8_t* vec);
void vec_int8_t_free(vec_int8_t* vec);
void vec_int8_t_print(const vec_int8_t* vec);

void vec_int16_t_push(vec_int16_t* vec, int16_t elem);
void vec_int16_t_push_unchecked(vec_int16_t* vec, int16_t elem);
int16_t vec_int16_t_pop(vec_int16_t* vec);
int16_t vec_int16_t_pop_unchecked(vec_int16_t* vec);
void vec_int16_t_set(vec_int16_t* vec, size_t index, int16_t elem);
void vec_int16_t_set_unchecked(vec_int16_t* vec, size_t index, int16_t elem);
int16_t vec_int16_t_get(const vec_int16_t* vec, size_t index);
int16_t vec_int16_t_get_unchecked(const vec_int16_t* vec, size_t index);
size_t vec_int16_t_size(const vec_int16_t* vec);
size_t vec_int16_t_capacity(const vec_int16_t* vec);
void vec_int16_t_free(vec_int16_t* vec);
void vec_int16_t_print(const vec_int16_t* vec);

void vec_int32_t_push(vec_int32_t* vec, int32_t elem);
void vec_int32_t_push_unchecked(vec_int32_t* vec, int32_t elem);
int32_t vec_int32_t_pop(vec_int32_t* vec);
int32_t vec_int32_t_pop_unchecked(vec_int32_t* vec);
void vec_int32_t_set(vec_int32_t* vec, size_t index, int32_t elem);
void vec_int32_t_set_unchecked(vec_int32_t* vec, size_t index, int32_t elem);
int32_t vec_int32_t_get(const vec_int32_t* vec, size_t index);
int32_t vec_int32_t_get_unchecked(const vec_int32_t* vec, size_t index);
size_t vec_int32_t_size(const vec_int32_t* vec);
size_t vec_int32_t_capacity(const vec_int32_t* vec);
void vec_int32_t_free(vec_int32_t* vec);
void vec_int32_t_print(const vec_int32_t* vec);

void vec_int64_t_push(vec_int64_t* vec, int64_t elem);
void vec_int64_t_push_unchecked(vec_int64_t* vec, int64_t elem);
int64_t vec_int64_t_pop(vec_int64_t* vec);
int64_t vec_int64_t_pop_unchecked(vec_int64_t* vec);
void vec_int64_t_set(vec_int64_t* vec, size_t index, int64_t elem);
void vec_int64_t_set_unchecked(vec_int64_t* vec, size_t index, int64_t elem);
int64_t vec_int64_t_get(const vec_int64_t* vec, size_t index);
int64_t vec_int64_t_get_unchecked(const vec_int64_t* vec, size_t index);
size_t vec_int64_t_size(const vec_int64_t* vec);
size_t vec_int64_t_capacity(const vec_int64_t* vec);
void vec_int64_t_free(vec_int64_t* vec);
void vec_int64_t_print(const vec_int64_t* vec);

#endif