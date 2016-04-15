#include "bigint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void clear(big_int_t *a) {
  for (int i = 0; i < BIG_INT_BYTE_WIDTH; i++) {
    a->bytes[i] = (char) 0;
  }
}

void reverse(char *data, int n) {
  char temp;
  for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
  }
}

void quick_sort (char *a, int n) {
  int i, j, halfway, temp;
  if (n < 2)
    return;
  halfway = a[n / 2];
  for (i = 0, j = n - 1;; i++, j--) {
    while (a[i] < halfway)
      i++;
    while (halfway < a[j])
      j--;
    if (i >= j)
      break;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
  quick_sort(a, i);
  quick_sort(a + i, n - i);
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
  quick_sort(a->bytes, (int) strlen(a->bytes));
  reverse(a->bytes, (int) strlen(a->bytes));
  return a;
}


big_int_t * hex_to_big_int(char *hex_string) {
  big_int_t *a = malloc(sizeof(big_int_t));
  char *valid = "123456789abcdef";
  int numLength = strlen(hex_string);
  int end = numLength - 1;
  for (int i = 0; i < numLength - 2; i++) {
    if (strchr(valid, hex_string[end - i])) {
      a->bytes[i] = (char) hex_string[end - i] - '0';
    } else {
      return NULL;
    }
  }
  quick_sort(a->bytes, (int) strlen(a->bytes));
  reverse(a->bytes, (int) strlen(a->bytes));
  return a;
}


void destroy_big_int(big_int_t *a) {
  free(a);
}


void big_int_and(big_int_t *a, big_int_t *b) {
  for (int i = 0; i < BIG_INT_BYTE_WIDTH; i++) {
    a->bytes[i] = a->bytes[i] & b->bytes[i];
  }
}

void big_int_not(big_int_t *a) {
  for (int i = 0; i < BIG_INT_BYTE_WIDTH; i++) {
    a->bytes[i] = ~(a->bytes[i]);
  }
}

int big_int_add(big_int_t *a, big_int_t *b) {
  int carry = 0;
  char temp[BIG_INT_BYTE_WIDTH];
  for (int i = 0; i < BIG_INT_BYTE_WIDTH; i++) {
    temp[i] = (char)(carry + a->bytes[i] + b->bytes[i]) % 10;
    carry = (carry + a->bytes[i] + b->bytes[i]) / 10;
    a->bytes[i] = temp[i];
  }
  return 1;
}


void big_int_shiftl(big_int_t *a, int s) {
  //bigger
  if ((strlen(a->bytes) == 0) && (a->bytes[0] == 0))
    return;
  for (int i = strlen(a->bytes); i >= 0; i--) {
    a->bytes[i + s] = a->bytes[i];
    a->bytes[i] = 0;
  }
}


void big_int_shiftr(big_int_t *a, int s) {
  //smaller
  int counter = 0;
  if ((strlen(a->bytes) == 0) && (a->bytes[0] == 0))
    return;
  if (s < strlen(a->bytes)) {
    for (int i = s; i < strlen(a->bytes); i++) {
      a->bytes[i - s] = a->bytes[i];
      counter++;
    }
    int len = strlen(a->bytes) - s;
    for (int i = strlen(a->bytes) - 1; i >= len; i--) {
      a->bytes[i] = 0;
    }
  } else {
    clear(a);
    return;
  }
}

