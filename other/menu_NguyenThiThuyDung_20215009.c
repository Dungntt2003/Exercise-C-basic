#include<stdio.h>

int main(){
	int a,b,key,submit=0;
	while (1){
		printf("Menu\n");
		printf("1.Nhap 2 so nguyen a,b\n");
		printf("2.Tinh tong hai so nguyen\n");
		printf("3.Tinh tich hai so nguyen\n");
		printf("4.Thoat chuong trinh\n");
		printf("Nhap 1-4 de chay chuong trinh: ");
		scanf("%d",&key);
		switch (key){
			case 1:
				printf("Nhap so nguyen a: ");
				scanf("%d",&a);
				printf("Nhap so nguyen b :");
				scanf("%d",&b);
				submit=1;
				break;
			case 2 :
				if (submit)
				printf("Tong hai so nguyen la %d\n",a+b);
				else printf("Hay nhap so nguyen a,b\n");
				break;
			case 3 :
				if (submit)
				printf("Tich hai so nguyen la %d\n",a*b);
				else printf("Hay nhap so nguyen a,b\n");
				break;
			case 4 :
				return 1;
			default :
				printf("Hay nhap 1-4 de chay chuong trinh\n");
		}
	}
	return 0;
}
