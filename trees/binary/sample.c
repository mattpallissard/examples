#include "array.h"
#include <stdio.h>

bool lt(type i, type j)
{
	return i < j;
}

bool eq(type i, type j)
{
	return i == j;
}

int main(void){
	// array based
	struct r r = init_root();
	struct r r2 = insert(4, r);
	struct r r3 = insert(5, r2);
	printf("%d\n%d\n\n", member(4, r2), member(5, r2));
	printf("%d\n%d\n", member(4, r3), member(5, r3));
}
