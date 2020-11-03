#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
	an array based, malloc-free, non-destructive binary tree implementation
*/


// header for typedefs
#include "array.h"

struct t init_node(type i)
{
	struct t t;
	t.l = -1;
	t.r = -1;
	t.d = i;
	return t;
}

struct r init_root()
{
	struct r r;
	r.n = 1;
	r.ld = 0;
	memset(r.t, -1, MAX * sizeof(struct t));
	return r;
}

bool member(type i, struct r r)
{
	/*
	   walk the tree as long as we have a left or right node.  Once se hit
	   the bottom, return the final comparison
	 */
	index_type j = 0;
	while (r.t[j].l != -1 || r.t[j].r != -1) {
		if (eq(i, r.t[j].d))
			return true;

		else if (lt(i, r.t[j].d))
			j = r.t[j].l;

		else
			j = r.t[j].r;
	}
	return eq(r.t[j].d, i);
}

index_type get_next(struct r *r)
{
	/*
	   get the next available index
	 */
	int i;
	if (r->ld) {
		i = r->ld;
		r->d[r->ld--] = 0;
	} else {
		i = r->n++;
	}
	return i;
}

struct r insert(type i, struct r r)
{
	/*
	   standard insert.
	 */
	int j = 0, k = 0;
	bool l;

	for (;;) {
		if (eq(i, r.t[j].d))
			goto end;
		else if (lt(i, r.t[j].d)) {
			l = true;
			if ((j = r.t[j].l) < 0)
				goto out;
			k = j;
		} else {
			l = false;
			if ((j = r.t[j].r) < 0)
				goto out;
			k = j;
		}
	}

out:
	j = get_next(&r);
	r.t[j] = init_node(i);
	if (l)
		r.t[k].l = j;
	else
		r.t[k].r = j;

end:
	return r;
}
