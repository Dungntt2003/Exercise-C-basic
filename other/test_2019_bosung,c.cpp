#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	FILE *p,*s;
	p=fopen("C:\\Users\\Admin\\Desktop\\test.txt","w");
	if (p==NULL)
	{
		printf("Error\n");
		return 1;
	}
	char str[300];
	printf("Hay nhap 1 cau tieng anh : ");
	fflush(stdin);
	gets(str);
	
	fclose(p);
	return 0;
	
}
