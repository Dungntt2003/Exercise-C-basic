#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
 	char name[30];
 	float open[10];
 	float close[10];
 	int count;
} data_t;
typedef struct node_s {
  data_t key;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t Search(char name[], tree_t Root) {
  if (Root == NULL)
    return NULL;           // not found
  else if (strcmp(Root->key.name,name)==0) /* found x */
    return Root;
  else if (strcmp(Root->key.name,name)<0)
    // continue searching in the right sub tree
    return Search(name, Root->right);
  else {
    // continue searching in the left sub tree
    return Search(name, Root->left);
  }
}

void Insertnode_t(char name[],float open,float close, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    strcpy((*pRoot)->key.name,name);
    (*pRoot)->key.open[0]= open;
    (*pRoot)->key.close[0]=close;
    (*pRoot)->key.count=0;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(name,(*pRoot)->key.name)<0)
    Insertnode_t(name,open,close, &((*pRoot)->left));
  else if (strcmp(name,(*pRoot)->key.name)>0)
    Insertnode_t(name,open,close, &((*pRoot)->right));
}


void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}

float trung_binh (float a[]){
	int i;
	float open=a[0];
	for (i=1;i<10;i++)
	{
		open=open+a[i];
	}
	return open/10;
}


void inorderprint(tree_t tree){
	if (tree!=NULL){
		inorderprint(tree->left);
		printf("%s %.3f %.3f\n",tree->key.name,tree->key.open[0],tree->key.close[0]);
		inorderprint(tree->right);
	}
}

int main(){
	tree_t tree=NULL;
	char str[100];
	char name[20];
	float open,close;
	int n;
	int i;
	FILE *p;
	int key;
	while (1){
		printf("Menu\n");
		printf("==============================\n");
		printf("1.Doc file\n");
		printf("2.Tim kiem theo ma chung khoan\n");
		printf("3.Tim kiem nhung ma chung khoan co xu huong tang\n");
		printf("4.Tim ma co so ngay tang lon nhat\n");
		printf("5. Thoat chuong trinh\n");
		printf("Chon 1-5 : ");
		scanf("%d",&key);
		switch (key){
			case 1:
				p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
				if (p==NULL){
					printf("Mo file loi\n");
					return 1;
				}
				fscanf(p,"%d",&n);
				fflush(stdin);
				printf("%d\n",n);
				while (!feof(p)){
					fflush(stdin);
					fgets(str,100,p);
					fflush(stdin);
					sscanf(str,"%s %f %f",name,&open,&close);
					tree_t s = Search(name,tree);
					if (s==NULL)
					{
						Insertnode_t(name,open,close,&tree);
					}
					else {
						s->key.count++;
						s->key.open[s->key.count]=open;
						s->key.close[s->key.count]=close;
					}
				}
				inorderprint(tree);
				fclose(p);
				
		}
	}
	freetree(tree);
	return 0;
}
