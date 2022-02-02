#include "vec_uint8_t.h"

#include <stdio.h>

int main() {
	vec_uint8_t* v = vec_uint8_t_with_capacity(4);
	vec_uint8_t_print(v);
	vec_uint8_t_push(v, 3);
	vec_uint8_t_push(v, 5);
	vec_uint8_t_push(v, 7);
	vec_uint8_t_push(v, 11);
	vec_uint8_t_push(v, 13);
	vec_uint8_t_push(v, 17);
	vec_uint8_t_print(v);
	printf("%d\n", vec_uint8_t_pop(v));
	printf("%d\n", vec_uint8_t_pop(v));
	vec_uint8_t_print(v);
	vec_uint8_t_free(v);
	return 0;
}
