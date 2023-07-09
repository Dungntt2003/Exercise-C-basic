#include <stdio.h>
#include <stdlib.h>

#include "bst_traversal.h"

void inOrderPrint(tree_t tree) {
  if (tree != NULL) {
    inOrderPrint(tree->left);
    showData(tree->data);
    inOrderPrint(tree->right);
  }
}

void postOrderPrint(tree_t tree) {
  if (tree != NULL) {
    postOrderPrint(tree->left);
    postOrderPrint(tree->right);
    showData(tree->data);
  }
}

void preOrderPrint(tree_t tree) {
  if (tree != NULL) {
    showData(tree->data);
    preOrderPrint(tree->left);
    preOrderPrint(tree->right);
  }
}

void iter_inorder(tree_t tree) {
  stack_t stack;
  stack_initialize(&stack);
  for (;;) {
    for (; tree; tree = tree->left) 
      push(tree, &stack);          			/* add to stack */
    if (stack_isEmpty(stack)) return;		/* stack is empty */
    tree = pop(&stack); 			          /*delete from stack*/

    if (tree == NULL) 
      break;
    showData(tree->data);
    tree = tree->right;
  }
}

void breadth_first(tree_t node) {
  Queue queue;      // queue of tree
  
  init_Queue(&queue);

  if (node != NULL) {
    EnQueue(node, &queue);
    while (!Empty_Queue(queue)) {
      node = DeQueue(&queue);
      showData(node->data);
      if (node->left != NULL) EnQueue(node->left, &queue);
      if (node->right != NULL) EnQueue(node->right, &queue);
    }
  }
}