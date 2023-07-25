#include<stdio.h>
#define MAX 20

int a[MAX], b[MAX];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int Max = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] > Max){
            Max = a[i];
        }
    }
    for (int i = 0; i <= Max; i++){
        b[i] = 0;
    }
    for (int i = 0; i < n; i++){
        b[a[i]] += 1;
    }
    for (int i = 0; i <= Max; i++){
        if (b[i] > 0){
            printf("%d %d\n", i, b[i]);
        }
    }
    return 0;
}