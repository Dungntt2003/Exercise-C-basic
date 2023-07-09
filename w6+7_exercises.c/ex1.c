#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int a[100];
	int n,i;
	printf("Hay nhap so phan tu cua mang : ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	int X;
	printf("Hay nhap so can tim trong mang :");
	scanf("%d",&X);
	for (i=0;i<n;i++)
	{
		if (a[i]==X)
		printf("%d\t",i);
	}
	return 0;
	
}
