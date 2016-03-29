#define BIG_INT_BIT_WIDTH 4096
#define BIG_INT_BYTE_WIDTH BIG_INT_BIT_WIDTH/(sizeof(char) * 8)

// values should be stored using a little-endian format
typedef struct { unsigned char bytes[BIG_INT_BYTE_WIDTH]; } big_int_t;


// create a new big_int_t from an unsigned int
big_int_t * unsigned_to_big_int(unsigned int);

// create a new big_int_t from a hexidecimal string.
//  should return NULL if the hex string cannot be
//  represented with a big_int_t (i.e. its too big or string is invalid)
//  input string should be a hex number consisting of 0-9 and a-f
big_int_t * hex_to_big_int(char *);

// frees any memory allocated for a big_int_t
void destroy_big_int(big_int_t *);

// performs a&=b on big_int_t *a and const big_int_t *b
void big_int_and(big_int_t *, big_int_t *);

// performs a=~a on big_int_t *a
void big_int_not(big_int_t *);

// performs a+=b on big_int_t *a and const big_int_t *b
// returns 1 if the addition operation resulted in overflow
//  otherwise 0
int big_int_add(big_int_t *, big_int_t *);

// performs left shift a=a<<b on big_int_t *a and int b
//  values for b > 4093 should be %4096
void big_int_shiftl(big_int_t *, int);

// performs arithmetic right shift a=a>>b on big_int_t *a and int b
//  values for b > 4093 should be %4096
void big_int_shiftr(big_int_t *, int);
