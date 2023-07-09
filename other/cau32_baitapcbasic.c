#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	int masp;
	char tensp[100];
	char motasp[200];
	int giasp;
	int sl;
} sp;


int main(){
	FILE *p;
	p=fopen("C:\\Users\\Admin\\Desktop\\sanpham.txt","w");
	if (p==NULL)
	{
		printf("Loi\n");
		return 1;
	}
	int ma,gia,sl;
	char ten[100],mota[200];
	while (1) {
		printf("Hay nhap du lieu cho san pham\n");
		printf("Hay nhap ma so san pham la so va nam trong khoang 101-500 : ");
		scanf("%d",&ma);
		if (ma==-1)
		break;
		if (ma>500 || ma<101)
		scanf("%d",&ma);
		printf("Hay nhap ten san pham : ");
		scanf("%s",ten);
		printf("Hay nhap mo ta san pham : ");
		scanf("%s",mota);
		printf("Hay nhap gia san pham : ");
		scanf("%d",&gia);
		printf("Hay nhap so luong san pham : ");
		scanf("%d",&sl);
		fprintf(p,"%d %s %s %d %d\n",ma,ten,mota,gia,sl);
	}
	fclose(p);
	return 0;
}
