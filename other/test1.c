#include<stdio.h>

int main(){
	int i,max=0,a[i],n;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
		if (a[i]%3==0 && a[i]>max){
			max= a[i];
		}
	}
	printf("%d\n",max);
	return 0;
}
