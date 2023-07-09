#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int key_t;  // specify a type for the data
typedef struct node_s {
  key_t key;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t Search(key_t x, tree_t Root) {
  if (Root == NULL)
    return NULL;           // not found
  else if (Root->key == x) /* found x */
    return Root;
  else if (Root->key < x)
    // continue searching in the right sub tree
    return Search(x, Root->right);
  else {
    // continue searching in the left sub tree
    return Search(x, Root->left);
  }
}

void Insertnode_t(key_t x, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    (*pRoot)->key = x;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (x < (*pRoot)->key)
    Insertnode_t(x, &((*pRoot)->left));
  else if (x > (*pRoot)->key)
    Insertnode_t(x, &((*pRoot)->right));
}

key_t DeleteMin(tree_t *Root) {
  key_t k;
  if ((*Root)->left == NULL) {
    k = (*Root)->key;
    (*Root) = (*Root)->right;
    return k;
  } else
    return DeleteMin(&(*Root)->left);
}

void Deletenode_t(key_t x, tree_t *Root) {
  if (*Root != NULL)
    if (x < (*Root)->key)
      Deletenode_t(x, &(*Root)->left);
    else if (x > (*Root)->key)
      Deletenode_t(x, &(*Root)->right);
    else if (((*Root)->left == NULL) && ((*Root)->right == NULL))
      *Root = NULL;
    else if ((*Root)->left == NULL)
      *Root = (*Root)->right;
    else if ((*Root)->right == NULL)
      *Root = (*Root)->left;
    else
      (*Root)->key = DeleteMin(&(*Root)->right);
}

void prettyprint(tree_t tree, char *prefix) {
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    printf("%04d", tree->key);
    if (tree->left != NULL)
      if (tree->right == NULL) {
        printf("\304");
        strcat(prefix, "     ");
      } else {
        printf("\302");
        strcat(prefix, "\263    ");
      }
    prettyprint(tree->left, prefix);
    *prefixend = '\0';
    if (tree->right != NULL)
      if (tree->left != NULL) {
        printf("\n%s", prefix);
        printf("\300");
      } else
        printf("\304");
    strcat(prefix, "     ");
    prettyprint(tree->right, prefix);
  }
}

void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}






int main() {
  char prefix[200] = "";
  tree_t p, tree = NULL;
  int i, n = 0;
  srand(time(NULL));
 
  for (i = 0; i < 10; i++) 
    Insertnode_t(rand() % 100, &tree);
  printf("pretty print:\n");
  strcpy(prefix, "    ");
  prettyprint(tree, prefix);
  printf("\n");

  do {
    printf("Enter key to search (-1 to quit):");
    scanf("%d", &n);

    p = Search(n, tree);
    if (p != NULL) printf("Key %d found on the tree\n\n", n);
    else {
      Insertnode_t(n, &tree);
      prettyprint(tree, prefix);
    }
  } while (n != -1);

  freetree(tree);

  return EXIT_SUCCESS;
}