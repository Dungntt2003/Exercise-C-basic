#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sortChar.h"

int main() {
  char a[] = "aljsdlfjkdlfjlsear";
  char b[] = "aljsdlfjkdlfjlsear";
  char c[] = "aljsdlfjkdlfjlsear";
  char d[] = "aljsdlfjkdlfjlsear";
  char e[] = "aljsdlfjkdlfjlsear";
  // char* arr[] = {"mot", "hai", "ba", "bon", "nam"};

  printf("\n--- Insertion Sort ---\n");
  printf("String: %s\n", a);
  insertion_sort(a, strlen(a));
  printf("result: %s\n", a);

  printf("\n--- Selection Sort ---\n");
  printf("String: %s\n", b);
  selection_sort(b, strlen(b));
  printf("result: %s\n", b);

  printf("\n--- Heap Sort ---\n");
  printf("String: %s\n", c);
  heapsort(c, strlen(c)-1);       // <===
  printf("result: %s\n", c);

  printf("\n--- Quick Sort ---\n");
  printf("String: %s\n", d);
  quicksort(d, 0, strlen(d)-1);
  printf("result: %s\n", d);

  printf("\n--- Merge Sort ---\n");
  printf("String: %s\n", e);
  sortMerge(e, strlen(e));
  printf("result: %s\n", e);

  return EXIT_SUCCESS;
}