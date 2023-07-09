// Exercise
// - Create an binary search tree with 10 nodes.
//   Each node contains an number
// - Print the content of the trees

#include <stdio.h>
#include <stdlib.h>

#include "../bst_traversal.h"

int main() {
  phoneAddr_t arr[] = {{"F", "0", "f@g"}, {"B", "1", "b@g"},
                         {"C", "2", "c@g"}, {"D", "3", "d@g"},
                         {"E", "4", "e@g"}, {"A", "5", "a@g"},
                         {"G", "6", "g@g"}, {"H", "7", "h@g"},
                         {"I", "8", "i@g"}, {"J", "9", "j@g"}};
  tree_t tree = NULL;
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    insertNode(arr[i], &tree);

  printf("\nArray:\n");
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) showData(arr[i]);

  printf("\nTree:\n");
  prettyPrint(tree);
  printf("\n\n");

  printf("\n--- preOrderPrint:\n");
  preOrderPrint(tree);

  printf("\n--- postOrderPrint:\n");
  postOrderPrint(tree);

  printf("\n--- inOrderPrint\n");
  inOrderPrint(tree);

  printf("\n--- iter_inorder (DFS):\n");
  iter_inorder(tree);

  printf("\n--- Breath First (BFS): \n");
  breadth_first(tree);

  freeTree(tree);
  return EXIT_SUCCESS;
}