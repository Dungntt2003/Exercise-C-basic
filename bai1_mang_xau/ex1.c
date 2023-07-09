#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int a[100];
	int i;
	for (i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for (i=10-1;i>=0;i--)
	printf("%d\t",a[i]);
	return 0;
}
