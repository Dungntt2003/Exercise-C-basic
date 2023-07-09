#include <stdio.h>
#include <string.h>

typedef char T;

int search(T r[], int n, T key);

int search(T r[], int n, T key) {
  int i;
  int tempr;
  for (i = 0; i < n - 1 && r[i] != key; i++)
    ;
  if (key == r[i]) {



    if (i > 0) {
      /*** Transpose with predecessor ***/
      tempr = r[i];
      r[i] = r[i - 1];
      r[--i] = tempr;
    };
    return (i);
  } else
    return (-1);
}

int main(void) {
  char str[20] = "asdf";
  int index = search(str, strlen(str), 'd');
  printf("%d", index);

  return 0;
}