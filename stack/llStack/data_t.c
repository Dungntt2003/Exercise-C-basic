#include "data_t.h"
#include <stdio.h>

void showData(data_t data) { 
  printf("%d ", data);
}

data_t convert(int i) {
  return i;
}
// data_t convert(char id[], char name[], int grade) {
//   data_t data;
//   strcpy(data.id, id);
//   strcpy(data.name, name);
//   data.grade = grade;
//   return data;
// }