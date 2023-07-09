#include <stdio.h>
#include <string.h>

typedef char T;

int linearSentinelSearch(T M[], int siz, T X) {
  int k = 0;
  for (M[siz] = X; M[k] != X; k++) ;
  if (k == siz) return -1;
  return k;
}

int main(void) {
  char str[20] = "asdf";
  int index = searchMTF(str, strlen(str), 'd');
  printf("%d", index);

  return 0;
}