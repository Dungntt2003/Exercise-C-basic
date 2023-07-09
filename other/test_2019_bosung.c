#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	FILE *p,*s;
	p=fopen("C:\\Users\\Admin\\Desktop\\test.txt","w+");
	if (p==NULL)
	{
		printf("Error\n");
		return 1;
	}
	char str[300];
	printf("Hay nhap 1 cau tieng anh : ");
	fflush(stdin);
	gets(str);
	fprintf(p,"%s",str);
	fseek(p,0,SEEK_SET);
	while (!feof(p)){
		char c = fgetc(p);
		if (c>='A' && c<='Z')
		{
			c=c+32;
			printf("%c",c);
		}
		else if (c==' ')
		printf("\n");
		else printf("%c",c);
	}
	fclose(p);
	return 0;
	
}
