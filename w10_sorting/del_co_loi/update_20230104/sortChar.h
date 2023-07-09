#ifndef __SORTCHAR_H__
#define __SORTCHAR_H__

#include <string.h>
#include <stdlib.h>

void insertion_sort(char a[], const int n);
void selection_sort(char a[], const int n);
void heapsort(char lst[], const int n);
void quicksort(char list[], int left, int right);
void sortMerge(char a[], const int n);

#endif