#include "chbase.h"
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void upstr(const char *s, char *t) {
  int l = strlen(s);
  for (int i = 0; i < l; i++) {
    t[i] = toupper(s[i]);
  }
}

double log_a_of_b(unsigned int a, unsigned int b) { return log(b) / log(a); }

unsigned int cal_digits(int m, int from, int to) {
  return (unsigned int)ceil(m * log_a_of_b(to, from));
}

const char *d = "0123456789ABCDEF";
const char *b64d =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *chbase(const char *value, int from, int to) {
  unsigned long l = strlen(value);
  unsigned long tl = cal_digits(l, from, to);
  char *temp = malloc(tl + 1 * sizeof(char));
  if (!temp) {
    fprintf(stderr, "Out of memory.\n");
    return temp;
  }
  memset(temp, '0', tl);
  temp[tl] = '\0';

  unsigned long long a = 0;
  unsigned long i = 0;
  while (i < l) {
    a = a * from + (strchr(d, value[i]) - d);
    i++;
  }

  i = tl-1;
  do {
    temp[i] = d[a % to];
    a = a / to;
    i--;
  } while (a > 0);

  char*out = malloc(tl -i +1);
  strcpy(out, temp + i + 1);
  free(temp);
  
  return out;
};
