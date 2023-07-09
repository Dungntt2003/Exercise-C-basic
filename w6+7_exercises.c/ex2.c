#include<stdio.h>
#include<string.h>

int main(){
	FILE *p;
	char str[100];
	p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
	if (p==NULL){
		printf("Loi\n");
		return 1;
	}
	char chuoi[100];
	printf("Hay nhap chuoi muon tim : ");
	scanf("%s",chuoi);
	while (!feof(p)){
		fgets(str,100,p);
		if (strstr(str,chuoi)!=NULL)
		printf("%s\n",str);
	}
	fclose(p);
	return 0;
	
}
