#include <stdlib.h>
#include "sort.h"

// ==================================================================
// Algorithm
// ==================================================================

// ----------------------------------------------
// --- Insertion Sort
// ----------------------------------------------

void insertionSort(data_t lst[], const int n) {
  for (int i = 0; i < n; i++) {
    data_t next = lst[i];
    int j;
    for (j = i - 1; j >= 0 && next < lst[j]; j--) lst[j + 1] = lst[j];
    lst[j + 1] = next;
  }
}


// ----------------------------------------------
// --- Selection Sort
// ----------------------------------------------

void selectionSort(data_t lst[], const int n) {
  for (int i = 0; i < n - 1; i++) {
    int mi = i;  // mi: min_index, index of min value
    for (int j = i + 1; j < n; j++)
      if (lst[j] < lst[mi]) mi = j;
    swap(&lst[i], &lst[mi]);
  }
}


// ----------------------------------------------
// --- Heap sort
// ----------------------------------------------
void buildHeap(data_t lst[], const int n);
void correctHeapNode(data_t lst[], const int n, const int i);

void heapSort(data_t lst[], const int n) {
  buildHeap(lst, n);

  for (int i = n; i > 1; i--) {
    swap(&lst[0], &lst[i - 1]);
    correctHeapNode(lst, i - 1, 0);
  }
}

void buildHeap(data_t lst[], const int n) {
  for (int i = (n / 2); i >= 0; i--) correctHeapNode(lst, n, i);
}

void correctHeapNode(data_t lst[], const int n, const int i) {
  const int l = i * 2 + 1;
  const int r = l + 1;
  int m = i;
  if (l < n && lst[l] > lst[m]) m = l;
  if (r < n && lst[r] > lst[m]) m = r;
  if (m != i) {
    // swap(lst, i, m);
    swap(&lst[i], &lst[m]);
    correctHeapNode(lst, n, m);
  }
}


// ----------------------------------------------
// --- Quick sort
// ----------------------------------------------
void mergeParts_aux(data_t *a, const int l, const int m, const int r);
void _quicksort(data_t lst[], int left, int right);
void quickSort(data_t lst[], const int n) {
  _quicksort(lst, 0, n - 1);
}

void _quicksort(data_t list[], const int left, const int right) {
  int pivot, i, j;
  if (left < right) {
    i = left;
    j = right + 1;
    pivot = list[left];  // <=== Chọn pivot
    do {
      do i++;
      while (list[i] < pivot);
      do j--;
      while (list[j] > pivot);
      if (i < j) swap(&list[i], &list[j]);
    } while (i < j);
    swap(&list[left], &list[j]);
    _quicksort(list, left, j - 1);
    _quicksort(list, j + 1, right);
  }
}


// ----------------------------------------------
// --- Merge sort
// ----------------------------------------------
void mergeParts_aux(data_t *a, const int l, const int m, const int r);
void mergeParts_inPlace(data_t lst[], const int l, int m, const int r);
void sortMergePart(data_t *lst, const int l, const int r);

void mergeSort(data_t lst[], const int n) { sortMergePart(lst, 0, n - 1); }

// Merge Sort
void sortMergePart(data_t *lst, const int l, const int r) {
  const int m = (l + r) / 2;
  if (m > l) sortMergePart(lst, l, m);
  if (m + 1 < r) sortMergePart(lst, m + 1, r);
  // mergeParts_aux(lst, l, m, r);
  mergeParts_inPlace(lst, l, m, r);
}

void mergeParts_aux(data_t *a, const int l, const int m, const int r) {
  const int pn = m - l + 1;
  const int qn = r - m;

  data_t *p = (data_t *)malloc(pn * sizeof(data_t));  // p = a.slice(l, l + pn);
  memcpy(p, a + l, pn * sizeof(data_t));

  data_t *q = (data_t *)malloc(qn * sizeof(data_t));  // q = a.slice(m + 1, m + 1 + qn);
  memcpy(q, a + m + 1, qn * sizeof(data_t));

  for (int i = 0, j = 0; i < pn || j < qn;) {
    if ((i == pn) || (j < qn && p[i] > q[j])) {
      a[l + i + j] = q[j];
      j++;
    } else {
      a[l + i + j] = p[i];
      i++;
    }
  }

  free(p);
  free(q);
}

void mergeParts_inPlace(data_t lst[], const int l, int m, const int r) {
  int i;
  data_t t;
  for (; m < r; m++) {
    t = lst[m + 1];
    for (i = m; i >= l && lst[i] > t; i--) lst[i + 1] = lst[i];
    lst[i + 1] = t;
  }
}