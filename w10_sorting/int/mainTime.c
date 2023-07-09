#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort.h"
#include "utils.h"
#define MAX (500)

void initArray(data_t dst[], data_t src[], int N) {
  for (int i = 0; i < N; i++) dst[i] = src[i];
}

void showDataLst(const char* msg, const data_t lst[], const int N) {
  static const int MAX_DISP = 10;
  printf("%s", msg);
  const int max_disp = N > MAX_DISP ? MAX_DISP : N;
  for (int i = 0; i < max_disp; i++) printf("%d ", lst[i]);
  printf("\n");
}

int main() {
  uint64_t t1, t2;
  data_t a[MAX], b[MAX];
  for (int i = 0; i < MAX; i++) a[i] = rand() % 10000;

  const int N = MAX;

  printf("\n--- Insertion Sort ---\n");
  initArray(b, a, N);
  showDataLst("Before: ", b, N);

  t1 = GetTimeStamp();
  insertionSort(b, N);
  t2 = GetTimeStamp();

  showDataLst("After : ", b, N);
  printf("Duration in micro seconds: %ld\n", (t2 - t1));

  // ==========================================================================

  printf("\n--- Selection Sort ---\n");
  initArray(b, a, N);
  showDataLst("Before: ", b, N);

  t1 = GetTimeStamp();
  selectionSort(b, N);
  t2 = GetTimeStamp();

  showDataLst("After : ", b, N);
  printf("Duration in micro seconds: %ld\n", (t2 - t1));

  return EXIT_SUCCESS;
}