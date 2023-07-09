#include<stdio.h>
#include<string.h>

typedef struct {
	char id[10];
	char name[30];
	float grade;
} SV;

int main(){
	SV a[100];
	int i=0,n=0;
	FILE *p,*f;
	char id[10],name[30];
	float grade;
	p=fopen("C:\\Users\\Admin\\Desktop\\thisinh.txt","w+");
	f=fopen("C:\\Users\\Admin\\Desktop\\thisinh2.txt","w");
	if (p==NULL || f==NULL)
	{
		printf("Error\n");
		return 1;
	}
	do {
		printf("Nhap so bao danh : ");
		fflush(stdin);
		scanf("%s",id);
		printf("Nhap ten : ");
		fflush(stdin);
		scanf("%s",name);
		printf("Nhap diem thi : ");
		fflush(stdin);
		do scanf("%f",&grade);
		while (grade <0 || grade>10);
		if (strcmp(id,"-1")!=0){
			fprintf(p,"%s %s %g\n",id,name,grade);
		}
	}
	while (strcmp(id,"-1")!=0);
	char str[200];
	fseek(p,0,SEEK_SET);
	while (!feof(p)){
		fgets(str,200,p);
		sscanf(str,"%s %s %f",a[i].id,a[i].name,&a[i].grade);
		i++;
		n++;
	}
	int j;
	printf("In mang lay tu file : \n");
	for (j=0;j<n-1;j++)
	printf("%s %s %g\n",a[j].id,a[j].name,a[j].grade);
	for (j=0;j<n-1;j++){
		if (a[j].grade>=5)
		fprintf(f,"%s %s %g\n",a[j].id,a[j].name,a[j].grade);
	}
	fclose(p);
	fclose(f);
	return 0;
}
