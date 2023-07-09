#include<stdio.h>
#include<string.h>

typedef struct {
	char cpu[20];
	int ram;
} computers;


int main(){
	computers a[100];
	char str[100];
	int i=0,n=0;
	int key;
	char filename[200];
	printf("======Program for management computers====\n");
	printf("1) Load Data Files\n");
	printf("2) Update CPU infor\n");
	printf("3) Update Ram infor\n");
	printf("4) Search\n");
	printf("5) Quit\n");
	printf("Choose : ");
	do scanf("%d",&key);
	while (key<1 || key >5);
	switch (key){
		case 1 :
			int count=0;
			printf("Nhap vao ten 1 file : ");
			fflush(stdin);
			scanf("%s",filename);
			FILE *p;
			p=fopen(filename,"r");
			if (p==NULL)
			printf("File khong ton tai\n");
			else {
				while (!feof(p)){
					fgets(str,100,p);
					sscanf(str,"%s %s",a[i].cpu,a[i].ram);
					i++;
					n++;
					if (n==20)
					{
						printf("Danh sach da day khong them duoc\n");
						break;
					}
					count++;
				}
				printf("So may vua moi them la : %d\n",count);
			}
			break;
		case 2:
			
		}
	
}
