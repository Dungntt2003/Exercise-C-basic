#include<stdio.h>
#include<stdlib.h>


int main(){
	FILE *f,*p;
	f = fopen("C:\\Users\\Admin\\Desktop\\thisinh.txt","w+");
	p=fopen("C:\\Users\\Admin\\Desktop\\thisinh.txt","w");
	if (f==NULL || p==NULL)
	{
		printf("Error\n");
		return 1;
	}

	int a[100];
	int i,n;
	printf("Hay nhap so phan tu cua mang : ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (i=0;i<n;i++)
	fprintf(f,"%d ",a[i]);
	fseek(f,0,SEEK_SET);
	int d;
	char str[100];
	
	while (!feof(f)){
		fscanf(f,"%d ",&d);	
		if (d>5)
		fprintf(p,"%d ",d);
	}
	fclose(f);
	fclose(p);
	return 0;
}
