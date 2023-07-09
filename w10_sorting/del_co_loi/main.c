#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sortChar.h"

int main() {
  char a[] = "aljsdlfjkdlfjlsear";
  char b[] = "aljsdlfjkdlfjlsear";

  printf("String a: %s\n", a);
  insertion_sort_char(a, strlen(a));
  printf("result: %s\n", a);

  printf("String b: %s\n", b);
  selection_sort_char(b, strlen(b));
  printf("result  : %s\n", b);

  return EXIT_SUCCESS;
}