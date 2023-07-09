#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
 	char word[30];
	int count;
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

void Insertnode_t(char word[], tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    strcpy((*pRoot)->key.word,word);
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

int check (char c){
	int a=0,b=0;
	if (c>='0' && c<='9')
	a=1;
	if (c>='A' && c<='Z')
	b=1;
	if (a==1 || b==1)
	return 1;
	else return 0;
}


char* uppercase(char str[]){
	int i;
	
	for (i=0;i<strlen(str);i++){
		if (check(str[i])==0)
		str[i]=str[i]-32;
	}
	return str;
}


void inorderprintf(tree_t tree,FILE *t)
{
  if (tree != NULL )
    {
      inorderprintf(tree->left,t);
//      printf("%s-%d\n",tree->key.word,tree->key.count);
	fprintf(t,"%s-%d\n",uppercase(tree->key.word),tree->key.count);
      inorderprintf(tree->right,t);
    }
}

int main() {
	
		FILE *f,*s,*t;
	char c;
	char a[30];
	f=fopen("C:\\Users\\Admin\\Desktop\\output1.txt","r");
	t=fopen("C:\\Users\\Admin\\Desktop\\output2.txt","w");
	if (f == NULL ){
	printf("Loi");
	return 1;
	}
//		if (s == NULL ){
//	printf("Loi");
//	return 1;
//	}
		if (t == NULL ){
	printf("Loi");
	return 1;
	}
//	while (!feof(f))
//	{
//		c= fgetc(f);
//		if (isalnum(c))
//		fputc(c,s);
//		else {
//			c= ' ';
//			fputc(c,s);
//		}
//	}
	
  tree_t p, tree = NULL;
  int i, n = 0;

  while (!feof(f)){
  	fscanf(f,"%s ",a);
   p = Search(a, tree);
   if (p != NULL) 
	{
		p->key.count++;
	}
    else {
      Insertnode_t(a, &tree);
    }
  }
  
inorderprintf(tree,t);
	
	
  freetree(tree);
  
//  fclose(s);
  fclose(f);
  fclose(t);
  return EXIT_SUCCESS;
}
