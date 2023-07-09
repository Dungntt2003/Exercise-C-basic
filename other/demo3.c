#include<stdio.h>
#include<string.h>
void CS(int n,int b){
	if (n==0)
	return;
	CS(n/b,b);
	printf("%d",n%b);
}

int main(){
	CS(2910,24);
		
	return 0;
	
}
