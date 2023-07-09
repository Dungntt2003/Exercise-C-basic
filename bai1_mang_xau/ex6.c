#include<stdio.h>
#include<string.h>

int check (char str[]){
	int i;
	for (i=strlen(str)-1;i>=0;i--){
		if (str[i]==' ')
		return i;
	}
}

int check1(char str[]){
	int i;
	for (i=0;i<strlen(str);i++){
		if (str[i]==' ')
		{
			return i;
		}
	}
}

int main(){
	char str[100];
	int i;
	printf("Hay nhap ten : ");
	fflush(stdin);
	gets(str);
	for (i=0;i<check1(str);i++)
	printf("%c",str[i]);
	printf("\n");
	for (i=check1(str)+1;i<check(str);i++)
	printf("%c",str[i]);
	printf("\n");
	for (i=check(str)+1;i<strlen(str);i++)
	printf("%c",str[i]);
	return 0;
}
