#include<stdio.h>
#include<string.h>

int check(char str[]){
	int i,j;
	for (i=0,j=strlen(str)-1;i<=j;i++,j--){
		if (str[i]!=str[j])
		return 1;
	}
	 return 0;
}

int main(){
	char str[100];
	printf("Hay nhap chuoi ky tu : ");
	scanf("%s",str);
	
	if (check(str)==1) printf("Chuoi %s khong doi xung\n",str);
	else printf("Chuoi %s la doi xung\n",str);
	return 0;
}
