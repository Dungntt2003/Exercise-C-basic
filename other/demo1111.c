#include <stdio.h>
int f(int* a, int n){
if(n == 1) return 0;
return a[n-1] + f(a,n-1);
}
int main(){
int a[5] = {1,2,3,4,5};
printf("%d",f(a,5));
}
