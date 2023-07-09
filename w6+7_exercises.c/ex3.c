#include<stdio.h>
#include<string.h>

typedef struct {
	char id[10];
	char name[30];
	float grade;
} SV;


int main(){
	SV a[100];
	FILE *p,*s;
	p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","w+");
	if (p==NULL ){
		printf("Loi\n");
		return 1;
	}
	char id[10],name[30];
	float grade;
	do {
		printf("Nhap du lieu cho sinh vien\n");
		printf("Hay nhap mssv :");
		scanf("%s",id);
		printf("Hay nhap ten :");
		fflush(stdin);
		scanf("%s",name);
		printf("Nhap diem : ");
		do scanf("%f",&grade);
		while (grade<0 || grade>10);
		if (strcmp(name,"###")!=0){
			fprintf(p,"%s %s %g\n",id,name,grade);
		}
	}
	while (strcmp(name,"###")!=0);
	char str[100];
	int i=0,n=0;
	fseek(p,0,SEEK_SET);
	while (!feof(p)){
		fgets(str,100,p);
		sscanf(str,"%s %s %f",a[i].id,a[i].name,&a[i].grade);
		printf("%s %s %g\n",a[i].id,a[i].name,a[i].grade);
		i++;
		n++;
	}
	int j,k;
//	SV tem;
//	for (j=0;j<n;j++){
//		for (k=j+1;k<n;k++){
//			if (strcmp(a[j].id,a[k].id)>0){
//				tem=a[j];
//				a[j]=a[k];
//				a[k]=tem;
//			}
//		} 
//	}
//	printf("Mang sau khi sap xep la : \n");
	for (j=0;j<n;j++)
	printf("%s %s %g\n",a[i].id,a[i].name,a[i].grade);
	
	fclose(p);
	return 0;	
}
