#include <stdio.h>
#include <string.h>

// return index of items where items[index] == key
int linearSearchChar(char items[], int siz, char key) {
  int t;
  for (t = 0; t < siz; t++)
    if (key == items[t]) return t;
  return -1;  // no match
}

int main(void) {
  char *str = "asdf";
  int index = linearSearchChar(str, strlen(str), 'd');
  printf("%d", index);

  return 0;
}