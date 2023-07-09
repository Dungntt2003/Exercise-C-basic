#include<stdio.h>
#include<string.h>

typedef struct {
	char str[100];
} string;


int main(){
	string a[100],b[100];
	FILE *f;
	f=fopen("C:\\Users\\Admin\\Desktop\\float.txt","r");
	if (f==NULL ){
		printf("Error\n");
		return 1;
	}
	char chuoi[100];
	int i=0;
	int n=0;
	while (!feof(f)){
		fgets(chuoi,100,f);
		sscanf(chuoi,"%s\t%s",a[i].str,b[i].str);
//		printf("%s %s\n",a[i].str,b[i].str);
		i++;
		n++;
	}
	int j;
	for (j=0;j<n-1;j++)
	printf("%s\t",a[j].str);
	printf("\n");
	for (j=0;j<n-1;j++)
	printf("%s\t",b[j].str);
	fclose(f);
	return 0;
}
