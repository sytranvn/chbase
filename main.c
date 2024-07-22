#include "chbase.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char *n1, *n2, *n3, *n4;
  n1 = chbase("1", 2, 8);
  n2 = chbase("1", 8, 2);
  n3 = chbase("11", 2, 3);
  assert(strcmp(n1, "01") == 0);
  assert(strcmp(n2, "0001") == 0);
  assert(strcmp(n3, "010") == 0);
  // overflow
  n4 = chbase("12412543254352435243532412", 10, 16);
  printf("%s\n", n4);
  free(n1);
  free(n2);
  free(n3);
  free(n4);
}
