#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MAX (1000)

void initArray(data_t dst[], data_t src[], int N) {
  for (int i = 0; i < N; i++) dst[i] = src[i];
}

int main() {
  char a[MAX] = "uysdialjsdlfjkdlfjlsear";
  char b[MAX];
  const int N = strlen(a);

  printf("\n--- Insertion Sort ---\n");
  initArray(b, a, N);
  printf("Before: %s\n", b);
  insertionSort(b, N);
  printf("After : %s\n", b);

  printf("\n--- Selection Sort ---\n");
  initArray(b, a, N);
  printf("Before: %s\n", b);
  selectionSort(b, N);
  printf("After : %s\n", b);

  printf("\n--- Heap Sort ---\n");
  initArray(b, a, N);
  printf("Before: %s\n", b);
  heapSort(b, N);       // <===
  printf("After : %s\n", b);

  printf("\n--- Quick Sort ---\n");
  initArray(b, a, N);
  printf("Before: %s\n", b);
  quickSort(b, N);
  printf("result: %s\n", b);

  printf("\n--- Merge Sort ---\n");
  initArray(b, a, N);
  printf("Before: %s\n", b);
  mergeSort(b, N);
  printf("After : %s\n", b);

  return EXIT_SUCCESS;
}