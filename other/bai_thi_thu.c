#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int thang_30_ngay(int month){
	if (month==4 || month==6 || month==9 || month==11)
	return 1;
}

int thang_31_ngay (int month){
	if (month==1 || month==3 || month==5 || month==7 || month==8 || month == 10 || month==12)
	return 1;
}




typedef struct {
	int date;
	int month;
	int year;
	char name[30];
	char size[30];
	char name1[30];
	int chan;
} message;

int main(){
    int i=0,n=0;
    char yes;
    message a[30];
    while (1){
    	printf("co muon nhap khong : ");
    	fflush(stdin);
    	scanf("%c",&yes);
    	if (yes=='n')
    	break;
    	printf("Nhap dong : ");
    	fflush(stdin);
    	scanf("%d-%d-%d %s %s %s %d",&a[i].date,&a[i].month,&a[i].year,a[i].name,a[i].size,a[i].name1,&a[i].chan);
    	i++;
    	n++;
	}
	int count=0,j;
	for (j=0;j<n;j++){
		if (a[j].year>0){
			if (thang_30_ngay(a[j].month)==1){
				if (a[j].date>0 && a[j].month<31)
				count++;
			}
			else if (thang_31_ngay(a[j].month)==1){
				if (a[j].date>0 && a[j].date<32)
				count++;
			}
		}
	}
	printf("So ngay thoa man la : %d \n",count);
	//////////////////////////////////////////
	char max[100];
	strcpy(max,a[j].size);
	for (j=1;j<n;j++){
		char so[100],so1[100];
		int k;
	for (k=0;k<strlen(max)-2;k++)
	{
		so[i]=max[i];
	}
	for (k=0;k<strlen(a[j].size)-2;k++)
	{
		so1[i]=a[j].size;
	}

		if (max[strlen(max)-1]=='G'){
			if (a[j].size[strlen(a[j].size)-1]=='G' && atoi(so)<atoi(so1))
			strcpy(max,a[j].size);
		}
		else if (max[strlen(max)-1]=='M'){
			if (a[j].size[strlen(a[j].size)-1]=='M' && atoi(so)<atoi(so1))
			strcpy(max,a[j].size);
			else if (a[j].size[strlen(a[j].size)-1]=='G')
			strcpy(max,a[j].size);
		}
		else if (max[strlen(max)-1]=='K'){
			if (a[j].size[strlen(a[j].size)-1]=='K' && atoi(so)<atoi(so1))
			strcpy(max,a[j].size);
			else if (a[j].size[strlen(a[j].size)-1]=='G')
			strcpy(max,a[j].size);
			else if (a[j].size[strlen(a[j].size)-1]=='M')
			strcpy(max,a[j].size);
		}
	}
	printf("%s\n",max);
	return 0;
	
	
	
}
