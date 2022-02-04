#include "vec_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vec_int64_t {
	int64_t* elems;
	size_t capacity;
	size_t size;
} vec_int64_t;

vec_int64_t* vec_int64_t_new() {
	vec_int64_t* result = malloc(sizeof(vec_int64_t));
	result->elems = malloc(sizeof(int64_t));
	result->capacity = 1;
	result->size = 0;
	return result;
}

vec_int64_t* vec_int64_t_with_capacity(size_t n) {
	vec_int64_t* result = malloc(sizeof(vec_int64_t));
	result->elems = malloc(sizeof(int64_t) * n);
	result->capacity = n;
	result->size = 0;
	return result;
}

void vec_int64_t_push(vec_int64_t* vec, int64_t elem) {
	if(vec->size == vec->capacity) {
		int64_t* new_elems = malloc(sizeof(int64_t) * 2 * vec->capacity);
		for(size_t i = 0; i < vec->capacity; i++) new_elems[i] = vec->elems[i];
		free(vec->elems);
		vec->elems = new_elems;
		vec->capacity *= 2;
	}
	vec->elems[vec->size++] = elem;
}

int64_t vec_int64_t_pop(vec_int64_t* vec) {
	return (vec->size != 0) ? vec->elems[--(vec->size)] : 0;
}

int64_t vec_int64_t_pop_unchecked(vec_int64_t* vec) {
	return vec->elems[--(vec->size)];
}

int64_t vec_int64_t_get(const vec_int64_t* vec, size_t index) {
	return (index < vec->capacity) ? vec->elems[index] : 0;
}

int64_t vec_int64_t_get_unchecked(const vec_int64_t* vec, size_t index) {
	return vec->elems[index];
}

void vec_int64_t_set(vec_int64_t* vec, size_t index, int64_t elem) {
	if(index < vec->size) vec->elems[index] = elem;
}

void vec_int64_t_set_unchecked(vec_int64_t* vec, size_t index, int64_t elem) {
	vec->elems[index] = elem;
}

size_t vec_int64_t_size(const vec_int64_t* vec) {
	return vec->size;
}

size_t vec_int64_t_capacity(const vec_int64_t* vec) {
	return vec->capacity;
}

void vec_int64_t_free(vec_int64_t* vec) {
	free(vec->elems);
	free(vec);
}

void vec_int64_t_print(const vec_int64_t* vec) {
	for(size_t i = 0; i < vec->size; i++) {
		printf("%ld, ", vec->elems[i]);
	}
	printf("\n%ld\n", vec->capacity);
	printf("%ld\n", vec->size);
}
