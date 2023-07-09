#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct node* link;

struct node {
  Item item;
  link l, r;
};

link NEW(Item item, link l, link r) {
  link x = malloc(sizeof(*x));
  x->item = item;
  x->l = l;
  x->r = r;
  return x;
}

Item _max(Item x, Item y) { return x > y ? x : y; }

link max(Item a[], int l, int r) {
  int m = (l + r) / 2;
  Item u, v;
  link x = NEW(a[m], NULL, NULL);
  if (l == r) return x;

  x->l = max(a, l, m);
  x->r = max(a, m + 1, r);
  x->item = _max(x->l->item, x->r->item);
  return x;
}

int main() {
  //   int a[] = {1, 2, 3, 4, 5, 6};
  int a[] = {5, 3, 6, 3, 7, 1, 3, 9};
  struct node* binTree = max(a, 0, sizeof(a) / sizeof(a[0]) - 1);

  printf("%d\n", binTree->item);

  return 0;
}