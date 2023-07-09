#include<stdio.h>
#include<string.h>

int main(){
	FILE *p;
	p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
	if (p==NULL)
	{
		printf("Loi mo file\n");
		return 1;
	}
	int k=0;
	int n;
	int a[100];
	int b[100];
	
	int i;
	fscanf(p,"%d",&n);
	for (i=0;i<2;i++)
	fscanf(p,"%d",&a[i]);
	while (!feof(p)){
		fscanf(p,"%d",&b[k]);
		k++;
	}
	printf("%d\n",n);
	for (i=0;i<2;i++)
	printf("%d\t",a[i]);
	printf("\n");
	for (i=0;i<k;i++)
	printf("%d\t",b[i]);
	return 0;
}
