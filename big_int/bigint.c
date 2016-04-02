#include "bigint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void clear(big_int_t *a) {
  for (int i = 0; i < BIG_INT_BIT_WIDTH; i++) {
    a->bytes[i] = (char) 0;
  }
}


big_int_t * unsigned_to_big_int(unsigned int x) {
  int finalDigit = -1;
  big_int_t *a = malloc(sizeof(big_int_t));
  clear(a);
  while (x > 0) {
    finalDigit++;
    a->bytes[finalDigit] = (x % 10);
    x /= 10;
  }
  return a;
}


big_int_t * hex_to_big_int(char *hex_string) {
  big_int_t *a = malloc(sizeof(big_int_t));
  char *valid = "123456789abcdef";
  int numLength = strlen(hex_string);
  int end = numLength - 1;
  for (int i = 0; i < numLength - 2; i++) {
    if (strchr(valid, hex_string[end - i])) {
      a->bytes[i] = (char) hex_string[end - i];
    } else {
      return NULL;
    }
  }
  return a;
}



void destroy_big_int(big_int_t *a) {
  free(a);
}


void big_int_and(big_int_t *a, big_int_t *b) {
  for (int i = 0; i < BIG_INT_BIT_WIDTH; i++) {
    a->bytes[i] = a->bytes[i] & b->bytes[i];
  }
}

void big_int_not(big_int_t *a) {
  for (int i = 0; i < BIG_INT_BIT_WIDTH; i++) {
    a->bytes[i] = ~(a->bytes[i]);
  }
}

int big_int_add(big_int_t *a, big_int_t *b) {
  int carry, answer = 0;
  int isZero = 1;
  char temp[BIG_INT_BIT_WIDTH];
  for (int i = 0; i < BIG_INT_BIT_WIDTH; i++) {
    temp[i] = (char)(carry + a->bytes[i] + b->bytes[i]) % 10;
    carry = (carry + a->bytes[i] + b->bytes[i]) / 10;
  }
  for (int i = BIG_INT_BIT_WIDTH - 1; i >= 0; i--) {
    if ((temp[i] != 0) || (!isZero)) {
      isZero = 0;
      answer *= 10;
      answer += temp[i];
    }
  }
return answer;
}

void big_int_shiftl(big_int_t *a, int s) {

}

void big_int_shiftr(big_int_t *a, int s) {

}

