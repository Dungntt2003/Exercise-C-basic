#define _DEBUG_

#include "strMatching.h"

#include <stdio.h>
#include <stdlib.h>

int BruteForceMatch(const char T[], const char P[]) {
  const int n = strlen(T);
  const int m = strlen(P);

  for (int i = 0; i < n - m; i++) {
    // test shift i of the pattern
    int j;
    for (j = 0; (j < m) && (T[i + j] == P[j]); j++)
      ;
    if (j == m) return i;  // match at i
  };
  return -1;
}

int min(int x, int y) { return x < y ? x : y; }

// L có kích thước 256 phần tử, mỗi phần tử kiểu số nguyên
void LastOccurenceFunc(const char P[], const char setOfChar[], int L[]) {
  const int lenSetOfChar = strlen(setOfChar);
  const int m = strlen(P);

  memset(L, -1, 256);

  for (int i = 0; i < lenSetOfChar; i++) {
    int j;
    char c = setOfChar[i];
    for (j = m - 1; (j >= 0) && (P[j] != c); j--)
      ;
    L[c] = (j == -1) ? -1 : j;  // not found = -1, found = largest index
                                // i such that P[i] == c
  }

#ifdef _DEBUG_
  printf("L vector: ");
  for (int i = 'a'; i <= 'z'; i++)
    if (L[i] != -1) printf("%c:%d ", i, L[i]);
#endif
}

int BoyerMooreMatch(const char T[], const char P[], const char setOfChar[]) {
  static int L[256];
  const int lenSetOfChar = strlen(setOfChar);
  LastOccurenceFunc(P, setOfChar, L);

  const int n = strlen(T);
  const int m = strlen(P);

  int i;  // chỉ số quét T
  int j;  // chỉ số quét P
  for (i = j = m - 1; (i <= n - 1);) {
    if (T[i] == P[j]) {
      if (j == 0)
        return i;  // match at i
      else
        i--, j--;
    } else {
      // character jump
      int l = L[T[i]];
      i += m - min(j, l + 1);  // update chỉ số quét T
      j = m - 1;               // reset chỉ số quét P
    }
  }
  return -1;
}

void FailureFunction(const char P[], int F[]) {
  const int m = strlen(P);
  for (int i = 0; i < m; i++) F[i] = 0;
  int i = 1;
  int j = 0;
  while (i < m) {
    if (P[i] == P[j]) {  // we have matched j+1 chars
      F[i] = j + 1;
      i++, j++;
    } else if (j > 0)  // use failure function to shift P
      j = F[j - 1];
    else {
      F[i] = 0;  // no match
      i++;
    }
  }
#ifdef _DEBUG_
  for (int i = 0; i < m; i++) printf("%d ", F[i]);
  printf("\n");
#endif
}

int KMPMatch(const char T[], const char P[]) {
  int *F = (int *)malloc(strlen(T) * sizeof(int));
  const int m = strlen(P);
  const int n = strlen(T);
  FailureFunction(P, F);
  int i = 0;
  int j = 0;
  while (i < n) {
    if (T[i] == P[j])
      if (j == m - 1)
        return i - j;
      else {
        i++, j++;
      }
    else {
      if (j > 0)
        j = F[j - 1];
      else
        i++;
    }
  }
  return -1;  // no match
}