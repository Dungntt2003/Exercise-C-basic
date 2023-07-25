#include<stdio.h>
int a[20][20];
void Nhap(int a[20][20],int n){
	int i,j;
    for(i = 0; i<n; i++){
        for(j = 0 ; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}
int Donvi(int a[20][20],int n)
{
	int i,j;
    for(i =0; i<n; i++){
        if(a[i][i]!=1){
            return 0;
        }
    }
    for(i =0; i<n; i++){
        for(j =i+1; j<n; j++){
            if((a[i][j] !=0) || (a[j][i] !=0)){
                return 0;
            }
        }
    }
    
    return 1;
}
int main(){
    int n;
    do{
        scanf("%d", &n);
    }while(n<1 || n>20);
    Nhap(a,n);
    if(Donvi(a,n)==1){
        printf("Co");
    }else{
        printf("Khong");
    }
    return 0;
}
