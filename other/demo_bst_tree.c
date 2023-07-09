#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	char a;
	int count;
} key_t;

typedef struct node_s {
  key_t key;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t Search(char word, tree_t Root) {
  if (Root == NULL)
    return NULL;           // not found
  else if (strcmp(word,Root->key.word)==0) /* found x */
    return Root;
  else if (strcmp(Root->key.word,word)<0)
    // continue searching in the right sub tree
    return Search(word, Root->right);
  else {
    // continue searching in the left sub tree
    return Search(word, Root->left);
  }
}

void Insertnode_t(char word, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    strcmp((*pRoot)->key.word,word);
    (*pRoot)->key.count=1;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(word,(*pRoot)->key.word)<0)
    Insertnode_t(word, &((*pRoot)->left));
    
  else if (strcmp(word,(*pRoot)->key.word)>0)
    Insertnode_t(word, &((*pRoot)->right));
}



void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}

void prettyprint(tree_t tree, char *prefix) {
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    printf("%s %d", tree->key.word,tree->key.count);
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




int main() {
  char prefix[200] = "";
  tree_t p, tree = NULL;
  int i;
  char c;

  do {
    printf("Enter key to search (-1 to quit):");
    scanf("%c",&c);

    p = Search(c, tree);
    if (p != NULL) 
	{
		printf("Key %c found on the tree\n\n", c);
		p->key.count++;
	}
    else {
      Insertnode_t(c, &tree);
      prettyprint(tree,prefix);
    }
  } while (strcmp(c,"-1")!=0);

  freetree(tree);

  return EXIT_SUCCESS;
}
