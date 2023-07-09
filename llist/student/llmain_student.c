// https://code.visualstudio.com/docs/cpp/config-linux
#include <stdio.h>
#include <stdlib.h>

#include "llistStudent.h"

int main() {
  data_t aSV[] = {{"001", "sv1", 2},
                  {"002", "sv2", 4},
                  {"003", "sv3", 6},
                  {"004", "sv4", 8},
                  {"005", "sv5", 10}};

  // Test InsertStudent
  printf("Test InsertStudent\n\n");
  root_t lst = llInit();

  for (int i = 0; i < sizeof(aSV) / sizeof(aSV[0]); i++) {
    lst = llInsertHead(lst, aSV[i]);
  }

  printf("\n\nPrint all\n");
  llPrint((lst));

  student_t sv = {"100", "sv100", 1};
  lst = llInsertSinhVien(lst, sv);

  printf("LList after Insert\n");
  llPrint(lst);


  llDeleteAll(lst);
  return 0;
}