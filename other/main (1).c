#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
  char id[10];
  char name[30];
  float grade;
}
  SV;

void nhap_thong_tin(FILE *f){
  char name[30];
  char id[10];
  float grade;
  do {
    printf("Nhap mssv: ");
    scanf("%s",id);
    printf("Nhap ten: ");
    scanf("%s",name);
    printf("Nhap diem : ");
    do  scanf("%f",&grade);
    while (grade<0 || grade>10);
    if (strcmp(name,"###") != 0)
      fprintf(f,"%s %s %g\n",id,name,grade);
  }
  while (strcmp(name,"###")!=0);
}

void sort(SV a[],int n){
	int i,j;
	SV tem;
	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++){
			if (strcmp(a[i].id,a[j].id)>0){
				tem=a[i];
				a[i]=a[j];
				a[j]=tem;		
			}
		}
	}
	for (i=0;i<n;i++)
	printf("%s %s %g\n",a[i].id,a[i].name,a[i].grade);
}



void doc_file(FILE *s, SV a[], int *n){
  int i=0;
  *n=0;
  char str[200];
  while (!feof(s))
    {
      fgets(str,200,s);
      sscanf(str,"%s %s %f",a[i].id,a[i].name,&a[i].grade);
      printf("%s %s %g\n",a[i].id,a[i].name,a[i].grade);
      i++;
      (*n)++;      
    }
}


int bst(SV a[],int n, char id[]){
	sort(a,n);
	int i;
	int Low, Mid, High;
  	Low = 0;
  	High = n - 1;
  	while (Low <= High) {
    Mid = (Low + High) / 2;
    if (strcmp(a[i].id,id)<0)
      Low = Mid + 1;
    else if (strcmp(a[i].id,id)>0)
      High = Mid - 1;
    else
      return Mid;
  }
  	return -1;
}

int main(){
  SV a[100];
  int n;
  FILE *f,*s;
  char id[10];
  int key,submit=0;
  while (1){
    printf("Menu\n");
    printf("1.Nhap sinh vien vao file\n");
    printf("2.Doc du lieu\n");
    printf("3.Sap xep\n");
    printf("4.Tim kiem\n");
    printf("5.Thoat\n");
    printf("Nhap 1-5: ");
    scanf("%d",&key);
      switch (key){
      case 1:
	f=fopen("C:\\Users\\Admin\\Desktop\\SVdat.txt","w");
	nhap_thong_tin(f);
	fflush(stdin);
	fclose(f);
	break;
      case 2:
	s=fopen("C:\\Users\\Admin\\Desktop\\SVdat.txt","r");
	  doc_file(s,a,&n);
	  printf("%d",n);
	fclose(s);
	break;
	case 3 :
		sort(a,n);
		break;
	case 4 :
		printf("Hay nhap mssv muon tim : ");
		scanf("%s",id);
		if (bst(a,n,id)==-1)
		printf("Khong tim thay mssv trong danh sach\n");
		else 
		printf("%s %s %g\n",a[bst(a,n,id)].id,a[bst(a,n,id)].name,a[bst(a,n,id)].grade);
		break;
		
    case 5 :
	return 1;
      }
  }

 
    return 0;
  }
