#include "bigint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// TIP: internet search and read about C's string.h library
//  you will find many functions that might be of use in this assignment
//  like strlen(cont char *) which returns the length of a string

big_int_t * unsigned_to_big_int(unsigned int x) {
  big_int_t *a = malloc(sizeof(big_int_t));

  return a;
}

big_int_t * hex_to_big_int(char *hex_string) {
  int i;
  char tmp[3] = {0};
  big_int_t *a = malloc(sizeof(big_int_t));

  for (i = 0; i < BIG_INT_BIT_WIDTH; i++){
    memcpy(tmp, hex_string + 2 * i, 2);
    a->bytes[i] = (unsigned char) tmp;

  return a;
  }


  // int numbl = strlen(hex_string);
  // big_int_t* out = (big_int_t*)malloc(numbl);
  // for (int i = 0; i < numbl; i++) {
  //   out[i] = numb[i] - CHARZERO_ABOVEINTZERO;
  // }
  // // num->number = out;
  // // num->length = numbl;
  return NULL;
}

void destroy_big_int(big_int_t *a) {

}


void big_int_and(big_int_t *a, big_int_t *b) {


}

void big_int_not(big_int_t *a) {

}

int big_int_add(big_int_t *a, big_int_t *b) {
  return 0;
}

void big_int_shiftl(big_int_t *a, int s) {

}

void big_int_shiftr(big_int_t *a, int s) {

}

