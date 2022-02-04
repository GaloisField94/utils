#include "vec_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vec_t {
	void** elems;
	size_t capacity;
	size_t size;
} vec_t;

vec_t* vec_t_new() {
	vec_t* result = malloc(sizeof(vec_t));
	result->elems = malloc(sizeof(void*));
	result->capacity = 1;
	result->size = 0;
	return result;
}

vec_t* vec_t_with_capacity(size_t n) {
	vec_t* result = malloc(sizeof(vec_t));
	result->elems = malloc(sizeof(void*) * n);
	result->capacity = n;
	result->size = 0;
	return result;
}

void vec_t_push(vec_t* vec, void* elem) {
	if(vec->size == vec->capacity) {
		void** new_elems = malloc(sizeof(void*) * 2 * vec->capacity);
		for(size_t i = 0; i < vec->capacity; i++) new_elems[i] = vec->elems[i];
		free(vec->elems);
		vec->elems = new_elems;
		vec->capacity *= 2;
	}
	vec->elems[vec->size++] = elem;
}

void vec_t_push_unchecked(vec_t* vec, void* elem) {
	vec->elems[vec->size++] = elem;
}

void* vec_t_pop(vec_t* vec) {
	return (vec->size != 0) ? vec->elems[--(vec->size)] : 0;
}

void* vec_t_pop_unchecked(vec_t* vec) {
	return vec->elems[--(vec->size)];
}

void* vec_t_get(const vec_t* vec, size_t index) {
	return (index < vec->capacity) ? vec->elems[index] : 0;
}

void* vec_t_get_unchecked(const vec_t* vec, size_t index) {
	return vec->elems[index];
}

void vec_t_set(vec_t* vec, size_t index, void* elem) {
	if(index < vec->size) vec->elems[index] = elem;
}

void vec_t_set_unchecked(vec_t* vec, size_t index, void* elem) {
	vec->elems[index] = elem;
}

size_t vec_t_size(const vec_t* vec) {
	return vec->size;
}

size_t vec_t_capacity(const vec_t* vec) {
	return vec->capacity;
}

void vec_t_free(vec_t* vec) {
	free(vec->elems);
	free(vec);
}

void vec_t_print(const vec_t* vec) {
	for(size_t i = 0; i < vec->size; i++) {
		printf("%016lX, ", vec->elems[i]);
	}
	printf("\n%ld\n", vec->capacity);
	printf("%ld\n", vec->size);
}