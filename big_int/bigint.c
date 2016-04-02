#include "bigint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define CHARZERO 48
#define INTSIZE(x) (int) log10(x) + 1 

// TIP: internet search and read about C's string.h library
//  you will find many functions that might be of use in this assignment
//  like strlen(cont char *) which returns the length of a string
int intToCharArray(unsigned int x, char *charArray) {
  int n = log10(x) + 1;
  for (int i = 0; i < n; i++) {
    charArray[i] = (x % 10) + '0';
    x /= 10;
  }
  return n;
}

big_int_t * unsigned_to_big_int(unsigned int x) {
  big_int_t *a = malloc(sizeof(big_int_t));
  char charArray[INTSIZE(x)];
  int n = intToCharArray(x, &charArray);
  for (int i = 0; i < n; i++){
    a->bytes[i] = charArray[i];
  }
  return a;
}

big_int_t * hex_to_big_int(char *hex_string) {
  // char *valid_characters = "0123456789abcdef";
  // char *c = hex_string;
  // int ignoreFirstX = 0;
  // while (*c) {
  //   if (!strchr(valid_characters, *c)) {
  //     if (ignoreFirstX) {
  //       return NULL;
  //     }
  //     ignoreFirstX = 1;
  //   }
  //   c++;
  // }
  char tmp[3] = {0};
  big_int_t *a = malloc(sizeof(big_int_t));
  for (int i = 0; i < BIG_INT_BIT_WIDTH; i++) {
    memcpy(tmp, hex_string + (2 * i), 2);
    a->bytes[i] = (unsigned char) strtol(tmp, NULL,  0);
  }
  return a;
}





void destroy_big_int(big_int_t *a) {
  free(a);
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
