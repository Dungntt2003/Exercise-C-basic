#include <stdio.h>
#include "llistStudent.h"

root_t llInsertSinhVien(root_t root, const student_t sv) {
  if (root == NULL) return llInsertHead(root, sv);

  if (sv.grade > root->data.grade) {
    return llInsertHead(root, sv);
  } else if (root->next == NULL)
    return llInsertTail(root, sv);

  for (node_t* p = root; p->next != NULL; p = p->next) {
    if (sv.grade > p->next->data.grade) {
      root = llInsertAfter(root, p, sv);
      return root;
    }
  }

  return llInsertTail(root, sv);
}