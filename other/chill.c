#include<stdio.h>
#include<string.h>

int main(){
	char str;
	do {
	printf("Do you love me : y/n?\n");
	printf("If you choose no you will never exit from the loop\n");
	printf("It's time for you to choose : ");
	scanf("%c",&str);
	}
	while (str!='y');
	printf("Done\n");
	return 0;
}
