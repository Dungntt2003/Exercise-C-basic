#include<stdio.h>
#include<string.h>
typedef struct {
	char str[100];
}STR;

int main(){
	STR a[100];
	char chuoi[1000];
	printf("Nhap chuoi : ");
	fflush(stdin);
	gets(chuoi);
	int i,n=0;
	for (i=0;i<strlen(chuoi);i++){
		int j=0;
		if (chuoi[i]==' '){
			i++;
			n++;
			j=0;
		}
		else {
			a[i].str[j] = chuoi[i];
			j++;
		}
	}
	
	for (i=0;i<n;i++)
	prinft("%s\n",a[i].str);
	return 0;
}
