#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[100];
	int i,n,x,j;
	printf("Nhap so phan tu cua mang : ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("So ban muon tim la : ");
	scanf("%d",&x);
	for (i=0;i<n;i++){
		if (a[i]==x){
			for (j=i;j<n;j++)
			a[j]=a[j+1];
			n--;
		}
	}
	for (i=0;i<n;i++)
	printf("%d\t",a[i]);
	return 0;
}
