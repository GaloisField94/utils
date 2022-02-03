#include "vec_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vec_uint16_t {
	uint16_t* elems;
	size_t capacity;
	size_t size;
} vec_uint16_t;

vec_uint16_t* vec_uint16_t_new() {
	vec_uint16_t* result = malloc(sizeof(vec_uint16_t));
	result->elems = malloc(sizeof(uint16_t));
	result->capacity = 1;
	result->size = 0;
	return result;
}

vec_uint16_t* vec_uint16_t_with_capacity(size_t n) {
	vec_uint16_t* result = malloc(sizeof(vec_uint16_t));
	result->elems = malloc(sizeof(uint16_t) * n);
	result->capacity = n;
	result->size = 0;
	return result;
}

void vec_uint16_t_push(vec_uint16_t* vec, uint16_t elem) {
	if(vec->size == vec->capacity) {
		uint16_t* new_elems = malloc(sizeof(uint16_t) * 2 * vec->capacity);
		memcpy(new_elems, vec->elems, vec->capacity);
		free(vec->elems);
		vec->elems = new_elems;
		vec->capacity *= 2;
	}
	vec->elems[vec->size++] = elem;
}

uint16_t vec_uint16_t_pop(vec_uint16_t* vec) {
	return (vec->size != 0) ? vec->elems[--(vec->size)] : 0;
}

uint16_t vec_uint16_t_pop_unchecked(vec_uint16_t* vec) {
	return vec->elems[--(vec->size)];
}

uint16_t vec_uint16_t_get(const vec_uint16_t* vec, size_t index) {
	return (index < vec->capacity) ? vec->elems[index] : 0;
}

uint16_t vec_uint16_t_get_unchecked(const vec_uint16_t* vec, size_t index) {
	return vec->elems[index];
}

void vec_uint16_t_set(vec_uint16_t* vec, size_t index, uint16_t elem) {
	if(index < vec->size) vec->elems[index] = elem;
}

void vec_uint16_t_set_unchecked(vec_uint16_t* vec, size_t index, uint16_t elem) {
	vec->elems[index] = elem;
}

size_t vec_uint16_t_size(const vec_uint16_t* vec) {
	return vec->size;
}

size_t vec_uint16_t_capacity(const vec_uint16_t* vec) {
	return vec->capacity;
}

void vec_uint16_t_free(vec_uint16_t* vec) {
	free(vec->elems);
	free(vec);
}

void vec_uint16_t_print(const vec_uint16_t* vec) {
	for(size_t i = 0; i < vec->size; i++) {
		printf("%04X, ", vec->elems[i]);
	}
	printf("\n%ld\n", vec->capacity);
	printf("%ld\n", vec->size);
}