#ifndef __SORT_H__
#define __SORT_H__

#include <string.h>
#include "data_t.h"

void insertionSort(data_t lst[], const int n);
void selectionSort(data_t lst[], const int n);
void heapSort(data_t lst[], const int n);
void quickSort(data_t lst[], const int n);
void mergeSort(data_t lst[], const int n);

#endif