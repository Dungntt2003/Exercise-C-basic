#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char word[20];
	char nghia[20];
} dic;


///Ham dfs duyet theo chieu sau





/// ham binary search 


int main(){
	tree_t tree =NULL;
	dic a[100];
	FILE *f;
	int i=0;
	int key;
	int n=0;
	char str[100];
	f=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
	if (f==NULL)
	{
		printf("Error\n");
		return 1;
	}
	while (!feof(f)){
		fgets(str,100,f);
		sscanf(str,"%s %s",a[i].word,a[i].nghia);
		printf("%s %s\n",a[i].word,a[i].nghia);
		insertNode(a[i],&tree);
		i++;
		n++;
	}
	while (1){
		printf("Menu\n");
		printf("1.Duyet theo chieu sau\n");
		printf("2.Them tu moi vao BST\n");
		printf("3.Chuc nang dich 1 tu tieng anh\n");
		printf("4.Thoat chuong trinh\n");
		printf("Hay nhap 1-4 de chay chuong trinh : ");
		scanf("%d",&key);
		switch (key){
			case 1 :
				/// dfs() // ham co san
				break;
			case 2 :
				char word[20];
				char mghia[20];
				printf("Hay nhap tu va nghia moi :");
				scanf("%s %s",word,nghia);
				strcpy(a[n].word,word);
				strcpy(a[n].nghia,nghia);
				insertNode(a[n],&tree);
				n++;
				break;
			case 3 :
				// ham co san
				break;
			case 4 :
				return 1;
			default :
				printf("Hay nhap 1-4 de chay chuong trinh\n");
				break;
				
		}
	}
	return 0;
}
