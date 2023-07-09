#include <stdio.h>

#define NotFound (-1)
typedef int T;

int binarySearch(T A[], T X, int N) {
  int Low, Mid, High;
  Low = 0;
  High = N - 1;
  while (Low <= High) {
    Mid = (Low + High) / 2;
    if (A[Mid] < X)
      Low = Mid + 1;
    else if (A[Mid] > X)
      High = Mid - 1;
    else
      return Mid; /* Found */
  }
  return NotFound; /* NotFound is defined as -1 */
}

int recursiveBinarySearch(T A[], T X, int Lo, int Hi);

int main() {
  static int A[] = {1, 3, 5, 7, 9, 13, 15};
  const int SizeofA = sizeof(A) / sizeof(A[0]);
  int i;
  for (i = 0; i < 20; i++) {
    printf("BinarySearch of %d returns %d\n", i,
           binarySearch(A, i, SizeofA));
    // printf("BinarySearch of %d returns %d\n", i,
          //  recursiveBinarySearch(A, i, 0, SizeofA - 1));
  }
  return 0;
}

// Usage: recursiveBinarySearch(A, X, 0, size - 1)
int recursiveBinarySearch(T A[], T X, int Lo, int Hi) {
  if (Lo > Hi) return NotFound;

  int Mid = (Lo + Hi) / 2;
  if (A[Mid] < X)
    return recursiveBinarySearch(A, X, Mid + 1, Hi);
  else if (A[Mid] > X)
    return recursiveBinarySearch(A, X, Lo, Mid - 1);
  else
    return Mid; /* Found */

  return NotFound; /* NotFound is defined as -1 */
}
