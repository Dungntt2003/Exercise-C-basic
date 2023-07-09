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
    {
    	printf("%s\n",Root->key.word);
    	return Search(word, Root->right);
    }
  else {
    // continue searching in the left sub tree
    printf("%s\n",Root->key.word);
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
	  tree_t tree,s = NULL;
	  FILE *p;
	  int key;
	  char str[100];
	  char word[30],meaning[30];
	  char word1[30],meaning1[30];
	  char word3[30];
	  p=fopen("C:\\Users\\Admin\\Desktop\\tudien.txt","r");
	  if (p==NULL){
	  	printf("File mo khong thanh cong\n");
	  	return 1;
	  }
	  while (!feof(p)){
	  	fgets(str,100,p);
	  	printf("%s",str);
	  	sscanf(str,"%s %s",word,meaning);
	  	Insertnode_t(word,&tree,meaning);
	  }
	  printf("\n");
	  inorderprintf(tree);
	  
	while (1){
		printf("Menu\n");
		printf("=========================\n");
		printf("1.In cay\n");
		printf("2.Them tu \n");
		printf("3.Dich\n");
		printf("4.Thoat\n");
		printf("Chon 1-4 : ");
		scanf("%d",&key);
		switch (key){
			case 1 :
				inorderprintf(tree);
				break;
			case 2:
				printf("Hay nhap tu va nghia moi muon them vao : ");
				fflush(stdin);
				scanf("%s %s",word1,meaning1);
				Insertnode_t(word1,&tree,meaning1);
				break;
			case 3 :
				printf("Nhap tu ban muon tim : ");
				fflush(stdin);
				scanf("%s",word3);
				p=Search(word3,tree);
				if (p==NULL)
				printf("Khong tim thay tu can tra\n");
				else printf("Da tim thay tu can tra\n");
				break;
				
		}
	}
	freetree(tree);
	fclose(p);
  return EXIT_SUCCESS;
}
