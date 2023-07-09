#include<stdio.h>
#include<ctype.h>
#include<string.h>
char* uppercase(char str[]){
	int i;
	for (i=0;i<strlen(str);i++){
		str[i]=str[i]-32;
	}
	return str;
}

int main(){
	char str[20];
	scanf("%s",str);
	printf("%s",uppercase(str));
	return 0;
}
