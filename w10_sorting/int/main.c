#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

#define MAX (100)

void initArray(data_t dst[], data_t src[], int N) {
  for (int i = 0; i < N; i++) dst[i] = src[i];
}

void showDataLst(const char*msg, const data_t lst[], const int N) {
  static const int MAX_DISP = 10;
  printf("%s", msg);
  const int max_disp = N > MAX_DISP ? MAX_DISP : N;
  for (int i = 0; i < max_disp; i++) printf("%d ", lst[i]);
  printf("\n");
}

// ========================================================
// Main
// ========================================================

int main() {
  data_t a[MAX], b[MAX];
  for (int i = 0; i < MAX; i++) a[i] = rand() % 10000;

  const int N = MAX;

  printf("\n--- Insertion Sort ---\n");
  initArray(b, a, N);
  showDataLst("Before: ",b, N);
  insertionSort(b, N);
  showDataLst("After : ",b, N);

  printf("\n--- Selection Sort ---\n");
  initArray(b, a, N);
  showDataLst("Before: ",b, N);
  selectionSort(b, N);
  showDataLst("After : ",b, N);

  printf("\n--- Heap Sort ---\n");
  initArray(b, a, N);
  showDataLst("Before: ",b, N);
  heapSort(b, N);  // <===
  showDataLst("After : ",b, N);

  printf("\n--- Quick Sort ---\n");
  initArray(b, a, N);
  showDataLst("Before: ",b, N);
  quickSort(b, N);
  showDataLst("After : ",b, N);

  printf("\n--- Merge Sort ---\n");
  initArray(b, a, N);
  showDataLst("Before: ",b, N);
  mergeSort(b, N);
  showDataLst("After : ",b, N);

  return EXIT_SUCCESS;
}