#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
 	char word[30];
	char meaning[30];
} key_t;
typedef struct node_s {
  key_t key;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t Search(char word[], tree_t Root) {
  if (Root == NULL)
    return NULL;           // not found
  else if (strcmp(Root->key.word,word)==0) /* found x */
    return Root;
  else if (strcmp(Root->key.word,word)<0)
    // continue searching in the right sub tree
    return Search(word, Root->right);
  else {
    // continue searching in the left sub tree
    return Search(word, Root->left);
  }
}

void Insertnode_t(char word[], tree_t *pRoot,char meaning[]) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    strcpy((*pRoot)->key.word,word);
    strcpy((*pRoot)->key.meaning,meaning);
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(word,(*pRoot)->key.word)<0)
    Insertnode_t(word, &((*pRoot)->left),meaning);
  else if (strcmp(word,(*pRoot)->key.word)>0)
    Insertnode_t(word, &((*pRoot)->right),meaning);
}


void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}



void inorderprintf(tree_t tree)
{
  if (tree != NULL )
    {
      inorderprintf(tree->left);
	printf("%s-%s\n",tree->key.word,tree->key.meaning);
      inorderprintf(tree->right);
    }
}

int main() {
	tree_t tree=NULL;
	FILE *p;
	p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
	if (p==NULL){
		printf("Error\n");
		return 1;
	}
	char str[100];
	char word[30],meaning[30];
	while (!feof(p)){
		fgets(str,100,p);
		printf("%s",str);
		sscanf(str,"%s %s",word,meaning);
		Insertnode_t(word,&tree,meaning);
	}
	printf("\n");
	
	inorderprintf(tree);
	char english[30];
	char giai[30];
	char yes;
	char change[30];
	printf("Hay nhap 1 tu tieng anh : ");
	fflush(stdin);
	scanf("%s",english);
	if (Search(english,tree)==NULL){
		printf("Hay nhap giai nghia cho tu nay");
		fflush(stdin);
		scanf("%s",giai);
		Insertnode_t(english,&tree,giai);
		inorderprintf(tree);
	}
	else {
		printf("Ban co muon nhap thay doi nghia khong  y/n: ");
		fflush(stdin);
		scanf("%c",&yes);
		if (yes=='y')
		{
			printf("Nhap thay doi : ");
			fflush(stdin);
			scanf("%s",change);
			strcpy(Search(english,tree)->key.meaning,change);
		}
		inorderprintf(tree);
	}
	
	fclose(p);
	free(tree);
  return 0;
}
