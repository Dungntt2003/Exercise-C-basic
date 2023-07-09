#include <stdio.h>
#include "data_t.h"

void showData(data_t data) { 
  printf("%s - %s - %s\n", data.name, data.tel, data.email);
}

// data_t convert(int i) {
//   return i;
// }