#include <stdio.h>
#define MAX 30

int main(){
    int n;
    do {
        scanf("%d",&n);
    }
    while (n < 1 || n > MAX);
    int m=0, b=1, fibo;
	for(int i=1;i<n;i++){
		fibo=m+b;
		b=m;
		m=fibo;
	}
    printf("%d",fibo);
    return 0;
}