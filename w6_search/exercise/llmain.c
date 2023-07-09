// https://code.visualstudio.com/docs/cpp/config-linux
#include <stdio.h>
#include "llist.h"

typedef mobAdd_t T;

// return index of items where items[index] == key
int linearSearchStr(root_t root, char key[]) {
  root_t p = NULL;
  int t;
  for (p = root, t = 0; p!=NULL; p= p->next, t++)
    if (strcmp(key, p->data.name) == 0) return t;
  return -1;  // no match
}


int main() {
  mobAdd_t a[] = {
    {"A","1", "1@"},
    {"B","2", "2@"},
    {"C","3", "3@"},
    {"D","4", "4@"},
    {"E","5", "5@"}
  };

  root_t lst = llInit();
  
  for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
    lst = llInsertHead(lst, a[i]);
  }
  llPrint(lst);

  int index = linearSearchStr(lst, "B");
  if (index == -1) printf("Not found\n");
  else {
    printf("Found. Index = %d\n", index);
    showData(llSeek(lst, index)->data);
  }

  lst = llDeleteAll(lst);

  return 0;
}