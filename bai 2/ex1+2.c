#include<stdio.h>
#include<string.h>


int main(){
	FILE *f,*p;
	f = fopen("C:\\Users\\Admin\\Desktop\\float.txt","w+");
	p=fopen("C:\\Users\\Admin\\Desktop\\float1.txt","w");
	if (f==NULL|| p==NULL )
	{
		printf("Error\n");
		return 1;
	}
	int n,i;
	float a[100];
	printf("Nhap so nguyen n : ");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%f",&a[i]);
	}
	fprintf(f,"%d\n",n);
	for (i=0;i<n;i++)
	fprintf(f,"%g\n",a[i]);
	char c;
    fseek(f,0,SEEK_SET);
	while (!feof(f)){
		c = fgetc(f);
		if (c>='0' && c <='9' && c >'5'){
			fprintf(p,"%g\n",c);
		}
	}
	fclose(p);
	fclose(f);
	return 0;
}


