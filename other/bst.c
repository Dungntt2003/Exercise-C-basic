// BST: Bin Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


tree_t search(char x[], tree_t root) {
  // Enter your code here
  if (root == NULL)
    return NULL;           // not found
  else if (strcmp(root->data.word,x)==0) /* found x */
    return root;
  else if (strcmp(root->data.word,x)<0)
    // continue searching in the right sub tree
    return search(x, root->right);
  else {
    // continue searching in the left sub tree
    return search(x, root->left);
  }
}

void insertNode(data_t x, tree_t *pRoot) {
  // Enter your code here
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    (*pRoot)->data = x;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(x.word,(*pRoot)->data.word)<0)
    insertNode(x, &((*pRoot)->left));
  else if (strcmp(x.word,(*pRoot)->data.word)>0)
    insertNode(x, &((*pRoot)->right));
}



void freeTree(tree_t tree) {
  if (tree != NULL) {
    freeTree(tree->left);
    freeTree(tree->right);
    free((void *)tree);
  }
}


void inorderprintf(tree_t tree)
{
  if (tree != NULL )
    {
      inorderprintf(tree->left);
      printf("%s %s\n",tree->data.word,tree->data.nghia);
      inorderprintf(tree->right);
    }
}



