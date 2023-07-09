#include<stdio.h>
#include<string.h>

typedef struct {
	char name[20];
	int day,month,year;
	char id[10];
	char school[20];
} SV;

int main(){
	SV a[100];
	FILE *p;
	int i=0,n=0;
	char str[100],chuoi[100];
	p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
	if (p==NULL){
		printf("Mo file khong thanh cong\n");
		return 1;
	}
	while (!feof(p)){
		fgets(str,100,p);
		sscanf(str,"%s %d/%d/%d %s",a[i].name,&a[i].day,&a[i].month,&a[i].year,a[i].id);
		fgets(chuoi,100,p);
		strcpy(a[i].school,chuoi);
		i++;n++;
	}
	int k;
	for (k=0;k<n;k++)
	printf("%s %d-%d-%d %s %s\n",a[k].name,a[k].day,a[k].month,a[k].year,a[k].id,a[k].school);
	fclose(p);
	return 0;
}
