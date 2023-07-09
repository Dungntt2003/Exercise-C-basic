#include<stdio.h>
#include<string.h>



int main(){
	FILE *p;
	p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
	char str[100];
	while (!feof(p)){
		fscanf(p,"%s",str);
		printf("%s123\n",str);
	}
	fclose(p);
	return 0;
}
