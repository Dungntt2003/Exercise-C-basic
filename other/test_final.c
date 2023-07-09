#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct {
 	char word[30];
 	char meaning[30];
} data_t;
typedef struct node_s {
  data_t key;
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

void Insertnode_t(char word[],char meaning[], tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    strcpy((*pRoot)->key.word,word);
    strcpy((*pRoot)->key.meaning,meaning);
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(word,(*pRoot)->key.word)<0)
    Insertnode_t(word,meaning, &((*pRoot)->left));
  else if (strcmp(word,(*pRoot)->key.word)>0)
    Insertnode_t(word,meaning, &((*pRoot)->right));
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
	printf("%s\t%s\n",tree->key.word,tree->key.meaning);
      inorderprintf(tree->right);
    }
}

char* lowercase(char str[]){
	int i;
	
	for (i=0;i<strlen(str);i++){
		if (str[i]>='A' && str[i]<='Z')
		str[i]=str[i]+32;
	}
	return str;
}


int main(){
	int key;
	tree_t tree=NULL;
	tree_t s=NULL;
	FILE *p;
	FILE *f;
	char yes_no;
	char word[30],meaning[30];
	char str[100];
	while (1){
		printf("Menu\n");
		printf("==============================\n");
		printf("1.Nap tu dien\n");
		printf("2.Noi dung tu dien\n");
		printf("3.Them sua tu\n");
		printf("4.Dich cau Anh Viet\n");
		printf("5.Thoat\n");
		printf("Chon 1-5 : ");
		scanf("%d",&key);
		switch (key){
			case 1:
				p=fopen("data.txt","r");
				if (p==NULL){
					printf("Loi\n");
					return 1;
				}
				while (!feof(p)){
					fgets(str,100,p);
					sscanf(str,"%s %s",word,meaning);
					printf("%s",str);
					Insertnode_t(word,meaning,&tree);
				}
				printf("\n");
				fclose(p);
				break;
			case 2:
				inorderprintf(tree);
				break;
			case 3:
				printf("Hay nhap vao 1 tu tieng anh : ");
				scanf("%s",word);
				s=Search(word,tree);
				if (s==NULL){
					printf("Hay nhap giai nghia cho tu do : ");
					scanf("%s",meaning);
					Insertnode_t(word,meaning,&tree);
					
				}
				else {
					printf("Ban co muon cap nhap noi dung moi hay khong y/n : ");
					fflush(stdin);
					scanf("%c",&yes_no);
					if (yes_no=='y')
					{
						printf("Ban hay nhap nghia moi cho tu : ");
						scanf("%s",meaning);
						strcpy(s->key.meaning,meaning);
					}
				}
				break;
			case 4:
				printf("Hay nhap vao 1 dong tieng anh : ");
				fflush(stdin);
				gets(str);
				lowercase(str);
				f=fopen("data1.txt","w+");
				fprintf(f,"%s",str);
				fseek(f,0,SEEK_SET);
				while (!feof(f)){
					fscanf(f,"%s ",word);
					printf("%s\n",word);
				}
				fseek(f,0,SEEK_SET);
				while (!feof(f)){
					fscanf(f,"%s ",word);
					s=Search(word,tree);
					if (s==NULL)
					printf("<Thieu tu> ");
					else printf("%s ",s->key.meaning);
				}
				printf("\n");
				break;
			case 5: 
				freetree(tree);
				return 1;
		}
	}
	return 0;
}
