#ifndef __BST_TRAVERSAL_H__
#define __BST_TRAVERSAL_H__

#include "stack.h"
#include "queue.h"

void inOrderPrint(tree_t tree);
void postOrderPrint(tree_t tree);
void preOrderPrint(tree_t tree);
void iter_inorder(tree_t node);

void breadth_first(tree_t node);

#endif