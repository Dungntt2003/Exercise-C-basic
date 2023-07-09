// https://code.visualstudio.com/docs/cpp/config-linux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

int main() {
  root_t lst = llInit();

  for (int i = 0; i < 5; i++) {
    lst = llInsertTail(lst, convert(i));
    lst = llInsertHead(lst, convert(-i));
  }
  llPrint(lst);

  node_t *p = llSeek(lst, 1);
  lst = llDeleteAfter(lst, p);
  lst = llDeleteHead(lst);
  lst = llDeleteTail(lst);

  llPrint(lst);

  lst = llDeleteAll(lst);

  return 0;
}