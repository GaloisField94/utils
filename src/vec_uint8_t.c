#include "vec_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vec_uint8_t {
	uint8_t* elems;
	size_t capacity;
	size_t size;
} vec_uint8_t;

vec_uint8_t* vec_uint8_t_new() {
	vec_uint8_t* result = malloc(sizeof(vec_uint8_t));
	result->elems = malloc(sizeof(uint8_t));
	result->capacity = 1;
	result->size = 0;
	return result;
}

vec_uint8_t* vec_uint8_t_with_capacity(size_t n) {
	vec_uint8_t* result = malloc(sizeof(vec_uint8_t));
	result->elems = malloc(sizeof(uint8_t) * n);
	result->capacity = n;
	result->size = 0;
	return result;
}

void vec_uint8_t_push(vec_uint8_t* vec, uint8_t elem) {
	if(vec->size == vec->capacity) {
		uint8_t* new_elems = malloc(sizeof(uint8_t) * 2 * vec->capacity);
		memcpy(new_elems, vec->elems, vec->capacity);
		free(vec->elems);
		vec->elems = new_elems;
		vec->capacity *= 2;
	}
	vec->elems[vec->size++] = elem;
}

void vec_uint8_t_push_unchecked(vec_uint8_t* vec, uint8_t elem) {
	vec->elems[vec->size++] = elem;
}

uint8_t vec_uint8_t_pop(vec_uint8_t* vec) {
	return (vec->size != 0) ? vec->elems[--(vec->size)] : 0;
}

uint8_t vec_uint8_t_pop_unchecked(vec_uint8_t* vec) {
	return vec->elems[--(vec->size)];
}

uint8_t vec_uint8_t_get(const vec_uint8_t* vec, size_t index) {
	return (index < vec->capacity) ? vec->elems[index] : 0;
}

uint8_t vec_uint8_t_get_unchecked(const vec_uint8_t* vec, size_t index) {
	return vec->elems[index];
}

void vec_uint8_t_set(vec_uint8_t* vec, size_t index, uint8_t elem) {
	if(index < vec->size) vec->elems[index] = elem;
}

void vec_uint8_t_set_unchecked(vec_uint8_t* vec, size_t index, uint8_t elem) {
	vec->elems[index] = elem;
}

size_t vec_uint8_t_size(const vec_uint8_t* vec) {
	return vec->size;
}

size_t vec_uint8_t_capacity(const vec_uint8_t* vec) {
	return vec->capacity;
}

void vec_uint8_t_free(vec_uint8_t* vec) {
	free(vec->elems);
	free(vec);
}

void vec_uint8_t_print(const vec_uint8_t* vec) {
	for(size_t i = 0; i < vec->size; i++) {
		printf("%02X, ", vec->elems[i]);
	}
	printf("\n%ld\n", vec->capacity);
	printf("%ld\n", vec->size);
}