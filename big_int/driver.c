#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

void print_big_int(big_int_t *);

int main(void) {
  big_int_t *a = unsigned_to_big_int(1234567);
  big_int_t *b = hex_to_big_int("0x2f1da32f");
  // big_int_t *c = unsigned_to_big_int(43);
  big_int_shiftr(b, 2);
  // big_int_shiftl(a, 8);
  // big_int_and(a, c);
  // big_int_not(a);
  // big_int_add(a, b);

  // print_big_int(a);
  print_big_int(b);
  // destroy_big_int(a);
  // destroy_big_int(b);
}


//------------------ print_big_int --------------------//
// pretty printing for each byte of a big_int_t        //
//-----------------------------------------------------//
void print_big_int(big_int_t *b) {

  int i;

  if (b == NULL) return;

  for (i = 0; i < BIG_INT_BYTE_WIDTH; i++) {
    if (i % 8 == 0) {
      printf("\n%d: ", i);
    }
    printf("%.2x ", b->bytes[i]);
  }
  printf("\n");
}
