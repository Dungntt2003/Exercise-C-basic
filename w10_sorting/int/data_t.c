#include "data_t.h"

void swap(data_t *x, data_t *y) {
  data_t tmp = *x;
  *x = *y;
  *y = tmp;
}