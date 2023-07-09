#include<stdio.h>


int main(){
	int a[11],b[11],c[11];
	int i,k=0,m=0;
	int n1=0,n2=0;
	for (i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<10;i++){
		if (a[i]%2==0){
			b[k]=a[i];
			k++;
			n1++;
		}
		else {
			c[m]=a[i];
			m++;
			n2++;
		}
	}
	for (i=0;i<n1;i++)
	printf("%d\t",b[i]);
	printf("%d\n",n1);
	for (i=0;i<n2;i++)
	printf("%d\t",c[i]);
	printf("%d\n",n2);
	return 0;
	
}
