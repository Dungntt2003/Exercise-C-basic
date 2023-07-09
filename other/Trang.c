#include <stdio.h>
#include <math.h>

int giaithua (int x){
	int i;
	int giaithua = 1;
	for (i=1;i<=x;i++)
	giaithua = giaithua * i;
	return giaithua;
}


double tinh_sin (double x){
	int i=2;
	double out = 0;
	double err= pow(10,-4); 
	while (abs(sin(x)-out)>err){
		out = out + pow(x,i)/giaithua(i);
		i = i+2;
	}
	return out;
}


int main (){
	double x;
	printf("Nhap x : ");
	scanf("%lf",&x);
	printf("Gia tri can tim la : %lf\n",tinh_sin(x));
} 
