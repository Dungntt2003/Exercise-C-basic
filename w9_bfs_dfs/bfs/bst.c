// BST: Bin Search Tree
#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef tree_t elem_t;

tree_t search(keyT x, tree_t root) {
  keyT k = root->data.key;  // <===
  if (root == NULL)
    return NULL;               // not found
  else if (strcmp(k, x) == 0)  // found x  <===
    return root;
  else if (strcmp(k, x) < 0)  // <===
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
    memcpy(&((*pRoot)->data), &x, sizeof(data_t));  // <===
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(x.key, (*pRoot)->data.key) < 0)  // <===
    insertNode(x, &((*pRoot)->left));
  else if (strcmp(x.key, (*pRoot)->data.key) > 0)  // <===
    insertNode(x, &((*pRoot)->right));
}

// Find the left-most node of right sub tree
keyT deleteMin(tree_t *root) {
  if ((*root)->left == NULL) {
    keyT k = (*root)->data.key;
    (*root) = (*root)->right;
    return k;
  } else
    return deleteMin(&(*root)->left);
}

// Delete a node from a BST
void deleteNode(keyT x, tree_t *root) {
  if (*root != NULL)
    if (strcmp(x, (*root)->data.key) < 0)
      deleteNode(x, &(*root)->left);
    else if (strcmp((*root)->data.key, x) < 0)
      deleteNode(x, &(*root)->right);
    else if (((*root)->left == NULL) && ((*root)->right == NULL))
      *root = NULL;
    else if ((*root)->left == NULL)
      *root = (*root)->right;
    else if ((*root)->right == NULL)
      *root = (*root)->left;
    else
      strcpy((*root)->data.key, deleteMin(&(*root)->right));
}

void prettyPrint(tree_t tree) {
  static char prefix[200] = "    ";
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    printf("'%s'", tree->data.key);
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

typedef tree_t ElementType;
void initialize(Queue *pQ) {
  pQ->Front = -1;
  pQ->Rear = -1;
}

int Empty_Queue(Queue Q) { return Q.Front == -1; }
int Full_Queue(Queue Q) { return (Q.Rear - Q.Front + 1) % MAX_LENGTH == 0; }
void EnQueue(tree_t X, Queue *pQ) {
  if (!Full_Queue(*pQ)) {
    if (Empty_Queue(*pQ)) pQ->Front = 0;
    pQ->Rear = (pQ->Rear + 1) % MAX_LENGTH;
    pQ->elements[pQ->Rear] = X;
  } else
    printf("Queue is full!");
}
ElementType DeQueue(Queue *pQ) {
  if (!Empty_Queue(*pQ)) {
    ElementType retVal = pQ->elements[pQ->Front];
    if (pQ->Front == pQ->Rear)
      initialize(pQ);
    else
      pQ->Front = (pQ->Front + 1) % MAX_LENGTH;

    return retVal;
  } else {
    printf("Queue is empty!");
    exit(-1);
  }
}