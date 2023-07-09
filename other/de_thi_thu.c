#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

typedef struct {
	int way[MAX];
} kc;
int main(){
	kc a[MAX];
	int n,c,b;
	printf("Nhap so ban trong nhom : ");
	scanf("%d",&n);
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++){
			a[i].way[j]=1;
		}
	}
	while (1){
		printf("Nhap cac cap so : ");
		scanf("%d %d",&b,&c);
		if (b==-1 && c==-1)
		{
			break;
		}
		a[b].way[c]=0;
		a[c].way[b]=0;
	}
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%d\t",a[i].way[j]);
		}
		printf("\n");
	}
	int count=0;
	int number;
	printf("Nhap vao 1 con so : ");
	scanf("%d",&number);
	for (i=0;i<n;i++){
		if (a[number].way[i]==0)
		{
			printf("%d\t",i);
			count++;
		}
	}
	if (count==0)
	printf("-1");
	int Y;
	printf("Nhap 1 so : ");
	scanf("%d",&Y);
	for (i=0;i<n;i++){
		if (a[Y].way[i]==1){
			for (j=)
		}
	}
	return 0;
} 
