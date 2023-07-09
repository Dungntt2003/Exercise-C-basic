#include<stdio.h>
#include<ctype.h>
#include<string.h>
void uppercase(char str[]){
	int i;
	for (i=0;i<strlen(str);i++){
		str[i]=str[i]+32;
	}
	printf("%s\n",str);
}

int main(){
	char str[20];
	scanf("%s",str);
	uppercase(str);
	return 0;
}
