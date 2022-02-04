#include "vec_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vec_int16_t {
	int16_t* elems;
	size_t capacity;
	size_t size;
} vec_int16_t;

vec_int16_t* vec_int16_t_new() {
	vec_int16_t* result = malloc(sizeof(vec_int16_t));
	result->elems = malloc(sizeof(int16_t));
	result->capacity = 1;
	result->size = 0;
	return result;
}

vec_int16_t* vec_int16_t_with_capacity(size_t n) {
	vec_int16_t* result = malloc(sizeof(vec_int16_t));
	result->elems = malloc(sizeof(int16_t) * n);
	result->capacity = n;
	result->size = 0;
	return result;
}

void vec_int16_t_push(vec_int16_t* vec, int16_t elem) {
	if(vec->size == vec->capacity) {
		int16_t* new_elems = malloc(sizeof(int16_t) * 2 * vec->capacity);
		for(size_t i = 0; i < vec->capacity; i++) new_elems[i] = vec->elems[i];
		free(vec->elems);
		vec->elems = new_elems;
		vec->capacity *= 2;
	}
	vec->elems[vec->size++] = elem;
}

int16_t vec_int16_t_pop(vec_int16_t* vec) {
	return (vec->size != 0) ? vec->elems[--(vec->size)] : 0;
}

int16_t vec_int16_t_pop_unchecked(vec_int16_t* vec) {
	return vec->elems[--(vec->size)];
}

int16_t vec_int16_t_get(const vec_int16_t* vec, size_t index) {
	return (index < vec->capacity) ? vec->elems[index] : 0;
}

int16_t vec_int16_t_get_unchecked(const vec_int16_t* vec, size_t index) {
	return vec->elems[index];
}

void vec_int16_t_set(vec_int16_t* vec, size_t index, int16_t elem) {
	if(index < vec->size) vec->elems[index] = elem;
}

void vec_int16_t_set_unchecked(vec_int16_t* vec, size_t index, int16_t elem) {
	vec->elems[index] = elem;
}

size_t vec_int16_t_size(const vec_int16_t* vec) {
	return vec->size;
}

size_t vec_int16_t_capacity(const vec_int16_t* vec) {
	return vec->capacity;
}

void vec_int16_t_free(vec_int16_t* vec) {
	free(vec->elems);
	free(vec);
}

void vec_int16_t_print(const vec_int16_t* vec) {
	for(size_t i = 0; i < vec->size; i++) {
		printf("%d, ", vec->elems[i]);
	}
	printf("\n%ld\n", vec->capacity);
	printf("%ld\n", vec->size);
}
