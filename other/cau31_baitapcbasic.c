#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	
typedef	struct {
	char id[10];	
	char name[30];
	float grade;
	} SV;

int binarySearch(SV a[], char id[], int n) {
  int Low, Mid, High;
  Low = 0;
  High = n - 1;
  while (Low <= High) {
    Mid = (Low + High) / 2;
    if (strcmp(a[Mid].id,id)<0)
      Low = Mid + 1;
    else if (strcmp(a[Mid].id,id)>0)
      High = Mid - 1;
    else
      return Mid; /* Found */
  }
  return -1; /* NotFound is defined as -1 */
}


int main(){
//	FILE *p;
//	p=fopen("C:\\Users\\Admin\\Desktop\\sv.txt","w");
//	if (p==NULL)
//	{
//		printf("Loi\n");
//		return 1;
//	}
//	char id[10],name[30];
//	float grade;
//	do {
//		printf("Nhap du lieu cho sinh vien : \n");
//		printf("Nhap mssv : ");
//		scanf("%s",id);
//		printf("Hay nhap ten khong khoang trang : ");
//		scanf("%s",name);
//		printf("Nhap diem trong khoang 0-10 : ");
//		do scanf("%f",&grade);
//		while (grade<0 || grade>10);
//		if (strcmp(name,"###")!=0)
//		fprintf(p,"%s %s %g\n",id,name,grade);
//	}
//	while (strcmp(name,"###")!=0);
//	fclose(p);


//doc file



	SV a[100];
	int i=0,n=0;
	FILE *s;
	s=fopen("C:\\Users\\Admin\\Desktop\\sv.txt","r");
	if (s==NULL)
	{
		printf("Loi\n");
		return 0;
	}
	char str[100];
	while (!feof(s)){
		fgets(str,100,s);
		sscanf(str,"%s %s %f",a[i].id,a[i].name,&a[i].grade);
		i++;
		n++;
	}
	
	
	/// sap xep in ra man hinh 
	
	
	int j,k;
	for (j=0;j<n;j++)
	printf("%s %s %g\n",a[j].id,a[j].name,a[j].grade);
	SV tem;
	for (j=0;j<n;j++){
		for (k=j+1;k<n;k++){
			if (strcmp(a[j].id,a[k].id)>0){
				tem=a[j];
				a[j]=a[k];
				a[k]=tem;
			}
		}
	}
	
	// in ra man hinh 
	
	
	for (j=0;j<n;j++)
	printf("%s %s %g\n",a[j].id,a[j].name,a[j].grade);
	char mssv[10];
	printf("Nhap mssv can tim : ");
	scanf("%s",mssv);
	int m=binarySearch(a,mssv,n);
	printf("%s %s %g\n",a[m].id,a[m].name,a[m].grade);
	fclose(s);
	return 0;
}
