#include <stdio.h>
#include <string.h>
#define MAX 64

int check (char a[]){
    int cnt = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    if (strlen(a) < 10)
    return 0;
    for (int i = 0; i < strlen(a);i++){
        if (a[i] <= '9' && a[i] >= '0')
        cnt++;
        if (a[i]>= 'a' && a[i] <= 'z')
        cnt1 ++;
        if (a[i]>= 'A' && a[i] <= 'Z')
        cnt2 ++;
    }
    if (cnt ==0 || cnt1 ==0 || cnt2 ==0 || cnt + cnt1 + cnt2 != strlen(a))
    return 0;
    return 1;
}

int main(){
    char xau[MAX];
    scanf("%s",xau);
    if (check(xau)==1)
    printf("True");
    else 
    printf("False");
    return 0;
}