#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BST: Bin Search Tree
#include "bst.h"

tree_t search(keyT x, tree_t root) {
  data_t* k = &(root->data);  // <===
  if (root == NULL)
    return NULL;    // not found
  else if (eq(x, k))  // found x  <===
    return root;
  else if (gt(x, k))  // <===
    // continue searching in the right sub tree
    return search(x, root->right);
  else {
    // continue searching in the left sub tree
    return search(x, root->left);
  }
}

void insertNode(data_t x, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    (*pRoot)->data = x;  // <===
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (lt(x.email, &((*pRoot)->data)))  // <===
    insertNode(x, &((*pRoot)->left));
  else if (gt(x.email, &((*pRoot)->data)))  // <===
    insertNode(x, &((*pRoot)->right));
}

// Find the left-most node of right sub tree
data_t deleteMin(tree_t *root) {
  if ((*root)->left == NULL) {
    data_t k = (*root)->data;
    (*root) = (*root)->right;
    return k;
  } else
    return deleteMin(&(*root)->left);
}

// Delete a node from a BST
void deleteNode(keyT x, tree_t *root) {
  if (*root != NULL)
    if (lt(x, &((*root)->data)))
      deleteNode(x, &(*root)->left);
    else if (gt(x, &((*root)->data)))
      deleteNode(x, &(*root)->right);
    else if (((*root)->left == NULL) && ((*root)->right == NULL))
      *root = NULL;
    else if ((*root)->left == NULL)
      *root = (*root)->right;
    else if ((*root)->right == NULL)
      *root = (*root)->left;
    else
      (*root)->data = deleteMin(&(*root)->right);
}

void prettyPrint(tree_t tree) {
  static char prefix[200] = "    ";
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    showData(tree->data);
    if (tree->left != NULL)
      if (tree->right == NULL) {
        printf("\304");
        strcat(prefix, "     ");
      } else {
        printf("\302");
        strcat(prefix, "\263    ");
      }
    prettyPrint(tree->left);
    *prefixend = '\0';
    if (tree->right != NULL)
      if (tree->left != NULL) {
        printf("\n%s", prefix);
        printf("\300");
      } else
        printf("\304");
    strcat(prefix, "     ");
    prettyPrint(tree->right);
  }
}

void freeTree(tree_t tree) {
  if (tree != NULL) {
    freeTree(tree->left);
    freeTree(tree->right);
    free((void *)tree);
  }
}

