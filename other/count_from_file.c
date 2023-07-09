#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
	FILE *f,*p;
	char c;
	char a[30];
	f=fopen("C:\\Users\\Admin\\Desktop\\output.txt","r");
	p= fopen("C:\\Users\\Admin\\Desktop\\output1.txt","w");
	if (f == NULL ){
	printf("Loi");
	return 1;
	}
		if (p == NULL ){
	printf("Loi");
	return 1;
	}
	
	while (!feof(f))
	{
		c= fgetc(f);
		if (isalnum(c))
		fputc(c,p);
		else {
			c= ' ';
			fputc(c,p);
		}
	}
//	while (!feof(p)){
//		fscanf(p,"%s ",a);
//		printf("%s\n",a);
//	}
	fclose(f);
	fclose(p);
	return 0;

}
