#include "sample.h"

struct t {
	int l, r;
	type d;
};

struct r {
	max_type n;
	max_type ld;
	max_type d[MAX];
	struct t t[MAX];
};

bool lt(type i, type j);
bool eq(type i, type j);
struct t init_node(type i);
struct r init_root();
bool member(type i, struct r r);
index_type get_next(struct r *r);
struct r insert(type i, struct r r);
