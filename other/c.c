#include<stdio.h>

int main(){
	int a[10];
	int n,i;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	if (n>=2 && n<=10){
		int max=0;
		for (i=0;i<n;i++){
			if (a[i]+a[i+1]>max)
			max=a[i]+a[i+1];
		}
		printf("%d",max);
	}
	if (n==1)
	printf("0");
	return 0;
	
}
