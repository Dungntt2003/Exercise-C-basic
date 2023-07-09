#include "sortChar.h"

void swap(char *x, char *y) {
  char tmp = *x;
  *x = *y;
  *y = tmp;
}

void insertion_sort(char a[], const int n) {
  for (int i = 0; i < n; i++) {
    char next = a[i];
    int j;
    for (j = i - 1; j >= 0 && next < a[j]; j--) a[j + 1] = a[j];
    a[j + 1] = next;
  }
}

void selection_sort(char a[], const int n) {
  for (int i = 0; i < n - 1; i++) {
    int mi = i;  // mi: min_index - index of min value
    for (int j = i + 1; j < n; j++)
      if (a[j] < a[mi]) mi = j;
    swap(&a[i], &a[mi]);
  }
}

// === Heap sort ===

void adjust(char lst[], int root, int n) {
  char temp = lst[root];
  char rootkey = lst[root];
  int child = 2 * root;
  while (child <= n) {
    if ((child < n) && (lst[child] < lst[child + 1])) child++;
    if (rootkey > lst[child])
      break;
    else {
      lst[child / 2] = lst[child];
      child *= 2;
    }
  }
  lst[child / 2] = temp;
}

// ascending order (max heap)
void heapsort(char lst[], int n) {
  for (int i = n / 2; i > 0; i--) adjust(lst, i, n);
  for (int i = n - 1; i > 0; i--) {
    swap(&lst[1], &lst[i + 1]);
    adjust(lst, 1, i);
  }
}
