
#include <stdio.h>


/*
 * bitwise_nor  - implement ~(x|y) using only ~ and &.
 *  Example biwise_nor(6, 5) = 0xFFFFFFF8
 *  Max. # of operators: 8
 */
int bitwise_nor(int x, int y) {
	return (~x & ~y);
}


/*
 * bitwise_xor - implement x xor y using only ~ and &.
 * Example bitwise_xor(4,5) = 0x1
 * Max # of operators: 14
 */
int bitwise_xor(int x, int y) {
	int temp1, temp2;
	temp1 = x & y;
	temp2 = ~x & ~y;
	return ~temp1 & ~temp2;
}

/*
 * eval_not_equal - implement x!=y.
 *  using only !, ~, &, |, ^, +, << and >>
 *   returns 0 if x == y, otherwise 1
 * Examples: eval_not_equal(2,2) = 0, eval_not_equal(3,4) = 1
 * Max # of operators: 6
 */
int eval_not_equal(int x, int y) {
	// return (x ^ y) ^ ((x ^ y) ^ 1);
	return !!(x ^ y);
}


/*
 * get_byte - extract byte n from word x.
 *  using only !, ~, &, |, ^, +, << and >>
 * do not use any constant values of more than 1 byte in size
 * assume ordering as 0=least significant byte,
 * 3 = most significant byte.
 * Example: get_byte(0x12345678, 1) = 0x56
 * Max # of operators: 6
*/
int get_byte(int x, int n) {
	return (x >> (n << 3)) & 0xff;
}


/*
* copy_lsbit - set all bits of result value to the least significant bit of x
*  using only !, ~, &, |, ^, +, << and >>
* do not use any constant values of more than 1 byte in size
*  Examples: copy_lsbit(5) = 0xFFFFFFFF, copy_lsbit(8) = 0x0
*  Max # of operators: 5
*/
int copy_lsbit(int x) {
	int lsbit = x & 1;
	int msbit = lsbit << 31;
	return msbit >> 31;
}

/*
 * bit_count - returns the # of bits in x that are 1.
 *  using only !, ~, &, |, ^, +, << and >>
 * do not use any constant values of more than 1 byte in size
 * examples: bit_count(2) = 1, bit_count(10) = 2, bit_count(7) = 3
 * Max # of operators: 40
 */
int bit_count(int x) {
	// Google hamming code
	int counter = 0;
	while (x > 0){
		counter++;
		x = x & (x - 1);
	}
	return counter;
}
