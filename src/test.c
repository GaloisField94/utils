#include "natural_t.h"
#include "vec_t.h"
#include "mt19937_t.h"
#include "mt19937_2002_t.h"
#include "mt19937_64_t.h"

#include <stdio.h>

/*typedef struct
{
	const char* name;
	uint8_t age;
} person;
*/

int main() {
/*	vec_t* v = vec_t_new();
	person p1 = {"Daniel", 27};
	person p2 = {"Daniela", 37};
	person p3 = {"Dawid", 29};
	person p4 = {"Damian", 81};
	person p5 = {"Danuta", 69};
	vec_push(v, &p1);
	vec_push(v, &p2);
	vec_push(v, &p3);
	vec_push(v, &p4);
	vec_push(v, &p5);
	for(size_t i = 0; i < vec_size(v); i++) {
		printf("%s: %d\n", ((person*)vec_get_unchecked(v, i))->name, ((person*)vec_get_unchecked(v, i))->age);
	}

	natural_t* a = from_unsigned(UINT64_MAX), *b = clone(a), *c = add(a, b);
	natural_print_words(c);
	c = add(c, c);
	c = add(c, c);
	natural_print_words(c);
	c = add_unsigned(c, 8);
	natural_print_words(c);
	mt19937_64_t* generator = mt19937_64_new();
	mt19937_64_init_array(generator, (uint64_t[]){420, 69}, 2);
	mt19937_64_result_t result;
	for(size_t i = 0; i < 10; i++) {
		result = mt19937_64_generate(generator);
		printf("successful: %d\ngenerated number: %lu\n", result.success, result.number);
	}*/
	natural_t* a = natural_from_unsigned(UINT64_MAX - 1);
	natural_t* b = natural_from_unsigned(UINT64_MAX - 3);
	natural_t* c = natural_add(a, b);
	natural_print_words(c);
	c = natural_add(c, b);
	natural_print_words(c);
	c = natural_add(c, b);
	natural_print_words(c);
	natural_add_to(a, b);
	natural_print_words(a);
	natural_add_to(a, b);
	natural_print_words(a);
	natural_add_to(a, b);
	natural_print_words(a);
	natural_delete(a);
	natural_delete(b);
	natural_delete(c);
	return 0;
}
