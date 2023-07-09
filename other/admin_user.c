#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char str[100];
} user;

int main(){
	user[100];
	int key;
	char c[100];
	char admin[100] ="Admin";
	while (1){
		printf("Menu\n");
		printf("Hay dang nhap nao : ");
		printf("Hay thuc hien ten dang nhap : ");
		scanf("%s",c);
		if (strcmp(c,admin)==0){
			printf("Ban la admin va da dang nhap thanh cong\n");
			printf("Menu\n");
			printf("1.Them 1 user\n");
			printf("2.Xoa 1 user\n");
			printf("3.Tim kiem 1 user\n");
			printf("4.Sap xep user theo thu tu tang dan ten\n");
			printf("Hay nhap 1-4 de thuc hien nao : ");
			
		}
	}
}

