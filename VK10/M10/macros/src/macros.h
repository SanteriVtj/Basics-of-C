#ifndef AALTO_MACROS_H
#define AALTO_MACROS_H

// Implement something here...

#define EQ3(a, b, c) ((a == b && b == c) ? 1 : 0)

#define MIN2(a, b) ((a < b) ? a : b)
#define MIN3(a, b, c) ((MIN2(a, b) < c) ? MIN2(a,b) : c)

#endif
