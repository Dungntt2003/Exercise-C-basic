#ifndef __BST_H__
#define __BST_H__

typedef struct {
  char word[20];
  char nghia[20];
} dic;
  // specify a type for the data

typedef struct node_s {
  dic data;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t search(char x[], tree_t root);
void insertNode(dic x, tree_t *pRoot);
void freeTree(tree_t tree);
void inorderprintf(tree_t tree);

#endif
