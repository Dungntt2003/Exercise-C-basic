#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct {
 	char name[30];
 	float mocua[10];
 	float dongcua[10];
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

void Insertnode_t(char name[],float mocua, float dongcua, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    strcpy((*pRoot)->key.name,name);
    (*pRoot)->key.mocua[0]=mocua;
    (*pRoot)->key.dongcua[0]=dongcua;
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


void inorderprintf(tree_t tree)
{
	float tbmocua=0;
	float tbdongcua=0;
	int k;
  if (tree != NULL )
    {
      inorderprintf(tree->left);
      for (k=0;k<10;k++){
      	tbmocua = tree->key.mocua[k]+tbmocua;
      	tbdongcua = tree->key.dongcua[k]+tbdongcua;
	  }
	  printf("%s %.3f %.3f\n",tree->key.name,tbmocua/10,tbdongcua/10);
      inorderprintf(tree->right);
    }
}

float max(float a[]){
	float lon = a[0];
	int k;
	for (k=1;k<10;k++){
		if (a[k]>lon)
		lon=a[k];
	}
	return lon;
}



void case3(tree_t tree){
	if (tree!=NULL){
		if (tree->key.mocua[0]<tree->key.dongcua[0] && tree->key.mocua[1]<tree->key.dongcua[1]){
			printf("%s\n",tree->key.name);
		}
		case3(tree->left);
		case3(tree->right);
		
	}
}




void case4(tree_t tree){
	if (tree==NULL){
		
	}
}


int main(){
	char ma[20];
	float avange[3];
	int key;
	char name[20];
	int n,k,i=1;
	tree_t tree=NULL;
	float mocua,dongcua;
	char str[100];
	FILE *p;
	p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
	if (p==NULL){
		printf("Khong mo duoc file\n");
		return 1;
	}
	while (1){
		printf("Menu\n");
		printf("==========================================\n");
		printf("1.Doc file\n");
		printf("2.Tim kiem theo ma chung khoan\n");
		printf("3.Tim kiem nhung ma chung khoan co xu huong tang\n");
		printf("4.Tim ma co so ngay tang lon nhat\n");
		printf("5.Thoat chuong trinh\n");
		printf("Chon 1-5 : ");
		scanf("%d",&key);
		switch (key){
			case 1 :
				fscanf(p,"%d",&n);
				for (k=0;k<n;k++){
					fgets(str,100,p);
					sscanf(str,"%s %f %f",name,&mocua,&dongcua);
					Insertnode_t(name,mocua,dongcua,&tree);
				}
				while (!feof(p)){
					fgets(str,100,p);
					sscanf(str,"%s %f %f",name,&mocua,&dongcua);
					tree_t p=NULL;
					p=Search(name,tree);
					if (p==NULL){
						printf("Khong tim thay\n");
						return 1;
					}
					else {
						p->key.mocua[i]=mocua;
						p->key.dongcua[i]=dongcua;
						i++;
					}
				}
				inorderprintf(tree);
				break;
			case 2:
				printf("Hay nhap 1 ma co phieu : ");
				scanf("%s",ma);
				tree_t p=NULL;
				p=Search(ma,tree);
				if (p==NULL){
					printf("Khong thay ma\n");
				}
				else {
					printf("%.3f %.3f\n",max(p->key.mocua),max(p->key.dongcua));
				}
				break;
			case 3:
				case3(tree);	
				break;
				
				}
		}

	return 0;
}

