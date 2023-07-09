#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct {
	char name[10];
	int ram;
} user;


int test_data(char data[]){
	if (data[0]=='i' || data[0]=='I'){
		return 1;
	}
	else return 0;
}

int main(){
	int key;
	char name[10];
	int ram;
	int k,ma1,ram1;
	user a[100];
	char filename[100];
	char tencpu[10];
	char str[100];
	char ten[10];
	int i=0,n=0,count=0;
	char data[100];
	int ma;
	FILE *p;
	while (1){
		printf("Menu\n");
		printf("========================\n");
		printf("1.Load Data Files\n");
		printf("2.Update CPU infor\n");
		printf("3.Update Ram infor\n");
		printf("4.Search\n");
		printf("5.Quit\n");
		printf("Choose : ");
		do scanf("%d",&key);
		while (key < 1 || key > 5  );
		switch (key){
			case 1:
//				printf("Hay nhap ten file : ");
//				scanf("%s",filename);
				p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
				if (p==NULL){
					printf("Khong mo duoc file\n");
					return 1;
				}
				int count=0;
				while (!feof(p)){
					fgets(str,100,p);
					sscanf(str,"%s %d",a[i].name,&a[i].ram);
					i++;
					n++;
					count++;
					if (n>20){
						printf("Danh sach da day, khong tang duoc nua \n");
						break;
					}
				}
				printf("So may vua moi them la : %d\n",count);
				fclose(p);
				break;
			case 2:
				printf("Nhap ma id cpu muon doi ten : ");
				scanf("%d",&ma);
				printf("Nhap ten muon doi : ");
				scanf("%s",tencpu);
				strcpy(a[ma].name,tencpu);
				ma++;
				do {
					printf("Hay nhap ten moi cho cpu tiep theo : ");
					scanf("%s",ten);
					if (ten!="STOP")
					{
						strcpy(a[ma].name,ten);
					}
					ma++;
				}
				while (ma<20 && ten!="STOP");
				for (k=0;k<n;k++)
				printf("%s %d\n",a[i].name,a[i].ram);
				break;
			case 3:
				printf("Nhap ma id cpu muon doi ram : ");
				scanf("%d",&ma1);
				printf("Nhap ten muon doi : ");
				scanf("%d",&ram1);
				a[ma1].ram=ram1;
				ma1++;
				do {
					printf("Hay nhap ram moi cho cpu tiep theo : ");
					scanf("%d",ram1);
					if (ram!=-1)
					{
						a[ma1].ram=ram1;
					}
					ma1++;
				}
				while (ma1<20 && ram1!=-1);
				for (k=0;k<n;k++)
				printf("%s %d\n",a[k].name,a[k].ram);
				break;
			case 4:
				printf("Hay nhap du lieu can tim : ");
				scanf("%s",data);
				if (test_data(data)==1){
					for (k=0;k<n;k++)
					{
						if (strcmp(data,a[k].name)==1)
						{
							printf("%s\n",data);
							count++;
						}
					}
				}
				else {
					for (k=0;k<n;k++){
						if (a[k].ram==data)
						{
							printf("Co tim thay\n");
							count++;
						}
					}
				}
				if (count==0)
				printf("Gia tri tim kiem khong hop le\n");
				break;
			case 5:
				return 1;
		}
	}
	return 0;
}
