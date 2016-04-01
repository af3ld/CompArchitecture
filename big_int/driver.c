#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

void print_big_int(big_int_t *);

int main(void) {
  // big_int_t *a = unsigned_to_big_int(45);
  big_int_t *b = hex_to_big_int("0x012");


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
 
  for(i=0;i<BIG_INT_BYTE_WIDTH;i++) {
    if (i%8 == 0) {
      printf("\n%d: ", i);
    }
    printf("%.2x ", b->bytes[i]);
  }
  printf("\n");
}
