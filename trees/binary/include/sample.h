#include <stdint.h>
#include <stdbool.h>
typedef uint64_t type;
typedef uint8_t index_type;
typedef int max_type;
enum { MAX = 254 };

bool lt(type i, type j);
bool eq(type i, type j);
