// Exercise
// - Create an binary search tree with 10 nodes. Each node contains an random integer. 
// - Ask user to input an number and search for it.
// - Print the content of the trees. 

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include "bst.h"



int main() {
  tree_t tree = NULL;

  // Create an binary search tree with 10 nodes.
  // Each node contains an random integer.
  // --- Your code here ---
  char c[28];
  int i;
  for (i=0;i<10;i++)
  {	
  	printf("Nhap email : ");
  	scanf("%s",c);
  	data_t data;
  	strcpy(data.name,"abc");
  	strcpy(data.tel,"0123");
  	strcpy(data.email,c);
  	insertNode(data,&tree);
  }
  // Print the content of the trees. 
  inorderprintf(tree);


  freeTree(tree);

  return EXIT_SUCCESS;
}
