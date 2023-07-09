#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


typedef struct {
 	char name[30];
 	float mocua[10];
 	float dongcua[10];
 	int count;
} key_t;
typedef struct node_s {
  key_t key;
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

void Insertnode_t(char name[],float mocua, float dongcua, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    strcpy((*pRoot)->key.name,name);
    (*pRoot)->key.mocua[0]=mocua;
    (*pRoot)->key.dongcua[0] = dongcua;
    (*pRoot)->key.count=0;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(name,(*pRoot)->key.name)<0)
    Insertnode_t(name,mocua,dongcua, &((*pRoot)->left));
  else if (strcmp(name,(*pRoot)->key.name)>0)
    Insertnode_t(name,mocua,dongcua, &((*pRoot)->right));
}


void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}


void inorderprint(tree_t tree){
	int i;
	if (tree!=NULL)
	{
		float mc= tree->key.mocua[0];
		float dc = tree->key.dongcua[0];
		inorderprint(tree->left);
		for (i=0;i<10;i++){
			mc=mc+tree->key.mocua[i];
			dc=dc+tree->key.dongcua[i];
		}
		printf("%s %.3f %.3f\n",tree->key.name,mc/10,dc/10);
		inorderprint(tree->right);
	}
}

//
//float find_max (float a[]){
//	int i;
//	float max=a[0];
//	for (i=1;i<10;i++)
//	{
//		if (a[i]>max)
//		max=a[i];
//	}
//	return max;
//}

//void find_stock(tree_t tree){
//	if (tree!=NULL)
//	{
//		if (tree->key.mocua[0]<tree->key.dongcua[0] && tree->key.mocua[1]<tree->key.dongcua[1]){
//			printf("%s\n",tree->key.name);
//		}
//		find_stock(tree->left);
//		find_stock(tree->right);
//	}
//}
//
//void find_case4(tree_t tree,int n){
//	int count=0;
//	int max=0;
//	int i;
//	if (tree!=NULL){
//		for (i=0;i<10;i++)
//		{
//			if (tree->key.mocua[i]<tree->key.dongcua[i])
//			{
//				count++;
//			}
//		}
//		if (count>max)
//		max=count;
//		find_case4(tree->left,n);
//		find_case4(tree->right,n);
//	}
//	printf("%d\n",max);
//}

int main(){
	tree_t tree;
	char str[100];
	char ma[20];
	char name[30];
	FILE *p;
	int key;
	float mocua,dongcua;
	int n,i;
	while (1){
		printf("Menu\n");
		printf("===========================\n");
		printf("1.Doc file\n");
		printf("2.Tim kiem theo ma chung khoan\n");
		printf("3.Tim kiem ma chung khoan co xu huong tang\n");
		printf("4.Tim ma co so ngay tang lon nhat\n");
		printf("5.Thoat chuong trinh\n");
		printf("Chon 1-5 : ");
		scanf("%d",&key);
		switch (key){
			case 1:
				p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
				if (p==NULL)
				{
					printf("Loi mo file\n");
					return 1;
				}
				fscanf(p,"%d",&n);
				while (!feof(p)){
					fgets(str,100,p);
					printf("%s",str);
					sscanf(str,"%s %f %f",name,&mocua,&dongcua);
				tree_t s=Search(name,tree);
					if (s==NULL)
					{
						Insertnode_t(tree,mocua,dongcua,&tree);
					}
					else {
						s->key.count++;
						s->key.mocua[s->key.count]=mocua;
						s->key.dongcua[s->key.count] =dongcua;
					}
				}
				inorderprint(tree);
				fclose(p);
				break;
				
				
//			case 2:
//					printf("Hay nhap vao 1 ma co phieu can tim : ");
//					scanf("%s",ma);
//					tree_t d;
//					d=Search(ma,tree);
//					if (d==NULL)
//					{
//						printf("Khong tim thay\n");
//						return 1;
//					}
//					else {
//						printf("%.3f %.3f\n",find_max(d->key.mocua),find_max(d->key.dongcua));
//					}
//					break;
//			case 3:
//				find_stock(tree);
//				break;
//			case 4:
//				find_case4(tree,n);
//				break;
//			case 5:
//				printf("Nguyen Thi Thuy Dung - 20215009\n");
//				return 1;
		}
	}
	return 0;
	freetree(tree);
}

