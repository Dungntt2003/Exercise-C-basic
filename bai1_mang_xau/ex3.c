#include<stdio.h>

void sort (int a[],int n){
	int i,j,tem;
	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++){
			tem=a[i];
			a[i]=a[j];
			a[j]=tem;
		}
	}
	for (i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
}


int main(){
	int a[100],b[100];
	int i,m,n,j;
	printf("Nhap so phan tu mang 1 :");
	scanf("%d",&m);
	printf("Nhap so phan tu mang 2 : ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (i=0;i<m;i++)
	scanf("%d",&b[i]);
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (a[i]==b[j])
			printf("%d\t",a[i]);
		}
	}
	printf("\n");
	sort(a,n);
	sort(b,m);
	// Mix hai mang
	
	return 0;
	
}
