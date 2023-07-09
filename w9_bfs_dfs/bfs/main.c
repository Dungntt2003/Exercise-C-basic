// Exercise
// - Create an binary search tree with 10 nodes. 
//   Each node contains an phone Address
// - Ask user to input an number and search for it.
// - Print the content of the trees.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bst.h"

void inorderprint(tree_t tree) {
  if (tree != NULL) {
    inorderprint(tree->left);
    printf("%s\n", tree->data.key);
    inorderprint(tree->right);
  }
}


void breadth_first(tree_t node)
{
   Queue queue; // queue of pointers
   initialize(&queue);

   if (node!=NULL) {
       EnQueue(node, &queue);
       while (!Empty_Queue(queue)) {
          node = DeQueue(&queue);
          printf("%s", node->data.key);
          if (node->left !=NULL)
             EnQueue(node->left, &queue);
          if (node->right !=NULL)
             EnQueue(node->right, &queue);
         }
     }
}





#include "bst.h"
int main() {
  phoneAddr_t phoneArr[10] = {{"F", "0", "f@g"}, {"B", "1", "b@g"},
                              {"C", "2", "c@g"}, {"D", "3", "d@g"},
                              {"E", "4", "e@g"}, {"A", "5", "a@g"},
                              {"G", "6", "g@g"}, {"H", "7", "h@g"},
                              {"I", "8", "i@g"}, {"J", "9", "j@g"}};

  tree_t tree = NULL;
  srand(time(NULL));

  for (int i = 0; i < 10; i++) 
    insertNode(phoneArr[i], &tree);

  prettyPrint(tree);
  printf("\n");

  breadth_first(tree);

  // char n[40];
  // do {
  //   printf("Enter key to search (Ctrl+C to quit):");
  //   scanf("%s", n);

  //   tree_t p = search(n, tree);
  //   if (p != NULL) printf("Key %s found on the tree\n\n", n);
  // } while (strlen(n) != 0);

  freeTree(tree);

  return EXIT_SUCCESS;
}