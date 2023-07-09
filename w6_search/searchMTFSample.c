#include <stdio.h>
#include <string.h>

typedef char T;
typedef char key_T;

int searchMTF(T a[], const int n, const key_T key);

int searchMTF(T a[], const int n, const key_T key) {
  int i, j;
  T temp;
  for (i = 0; i < n - 1 && a[i] != key; i++)
    ;
  if (key == a[i]) {
    // Đảo phần tử tìm thấy lên đầu
    // Các phần tử sau phần tử tìm thấy giữa nguyên vị trí
    // Các phần tử trước dịch lùi 1 vị trí
    if (i > 0) {
      temp = a[i];
      for (j = i; j > 0; j--)  // Dồn i phần tử đầu về sau 1 vị trí
        a[j] = a[j-1];
      a[0] = temp;
    };
    return (i);  // trả về chỉ số vị trí cũ. Dữ liệu cũ luôn ở đầu mảng
  } else
    return (-1);
}

int main(void) {
  char str[20] = "asdf";
  const char key = 'd';

  printf("Before search str='%s'\n", str);

  int index = searchMTF(str, strlen(str), key);

  printf("After search str='%s'\n", str);
  printf("Found %c at %d\n", key, index);

  return 0;
}