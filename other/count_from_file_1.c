#include<stdio.h>


int main(){
	FILE *p,*s;
	p=fopen("C:\\Users\\Admin\\Desktop\\output.txt","r");
	s=fopen("C:\\Users\\Admin\\Desktop\\output1.txt","w");
	if (p==NULL)
	{
		printf("Error\n");
		return 1;
	}
	if (s==NULL)
	{
		printf("Error\n");
		return 1;
	}	
	char a[30];
	while (!feof(p)){
		fscanf(p,"%s ",a);
		fprintf(s,"%s\n",a);
	}
	fclose(p);
	fclose(s);
	return 0;
}
