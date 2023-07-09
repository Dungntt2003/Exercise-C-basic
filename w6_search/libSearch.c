#include "libSearch.h"

// M: Array to search
// N: number of element in M
// T: type // typedef int T
int linearSearch(T M[], int N, T X) {
  int k = 0;
  while (M[k] != X && k < N) k++;
  if (k < N) return (k);
  return (-1);
}

// return index of items where items[index] == key
int linearSearchChar(char items[], int siz, char key) {
  int t;
  for (t = 0; t < siz; t++)
    if (key == items[t]) return t;
  return -1;  // no match
}

int linearSentinelSearch(T M[], int siz, T X) {
  int k = 0;
  for (M[siz] = X; M[k] != X; k++)
    ;
  if (k == siz) return -1;
  return k;
}

int searchMTF(T r[], int n, T key) {
  int i, j;
  T tempr;
  for (i = 0; i < n - 1 && r[i] != key; i++)
    ;
  if (key == r[i]) {
    // Đảo phần tử tìm thấy lên đầu
    // Các phần tử sau phần tử tìm thấy giữa nguyên vị trí
    // Các phần tử trước dịch lùi 1 vị trí
    if (i > 0) {
      tempr = r[i];
      for (j = 0; j < i; j++)  // Dồn i phần tử đầu về sau 1 vị trí
        r[j + 1] = r[j];
      r[0] = tempr;
    };
    return (i);
  } else
    return (-1);
}

int search(int key, int r[], int n) {
  int i;
  int tempr;
  for (i = 0; i < n - 1 && r[i] != key; i++)
    ;
  if (key == r[i]) {
    if (i > 0) {
      /*** Transpose with predecessor ***/
      tempr = r[i];
      r[i] = r[i - 1];
      r[--i] = tempr;
    };
    return (i);
  } else
    return (-1);
}

int binSearch(T List[], int Size, int Target) {
  int Mid, Lo = 0, Hi = Size - 1;
  while (Lo <= Hi) {
    Mid = (Lo + Hi) / 2;
    if (List[Mid] == Target)
      return Mid;
    else if (Target < List[Mid])
      Hi = Mid - 1;
    else
      Lo = Mid + 1;
  }
  return -1;
}
