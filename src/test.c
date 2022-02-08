#include "natural_t.h"
#include "vec_t.h"

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
*/
	natural_t* a = from_unsigned(UINT64_MAX), *b = clone(a), *c = add(a, b);
	natural_print_words(c);
	c = add(c, c);
	c = add(c, c);
	natural_print_words(c);
	c = add_unsigned(c, 8);
	natural_print_words(c);
	return 0;
}
