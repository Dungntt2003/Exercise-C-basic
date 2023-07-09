#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50


//data.h

typedef struct {
	char id[10];
	char name[30];
	float grade;
} data_t;


//data.c

void showData(data_t data) { 
  printf("%s %s %g\n", data.id,data.name,data.grade);
}

data_t convert(char id[],char name[],float grade) {
  data_t data;
  strcpy(data.id,id);
  strcpy(data.name,name);
  data.grade=grade;
  return data;
}

// stack.h

typedef data_t elem_t;

typedef struct stack_s{
	elem_t storage[MAX];
   int top;
} stack_t;


//Stack.c

void initialize(stack_t *pStack) { (*pStack).top = 0; }

int isEmpty(stack_t stack) { return stack.top == 0; }

int isFull(stack_t stack) { return stack.top == MAX; }

void push(elem_t el, stack_t *pStack) {
  if (isFull(*pStack)) {
    printf("Stack overflow\n");
    return 1;
  } else
    (*pStack).storage[(*pStack).top++] = el;
}

elem_t pop(stack_t *pStack) {
  if (isEmpty(*pStack)) {
    printf("stack underflow");
  } else
    return (*pStack).storage[--(*pStack).top];
}



///main.c


int main() {
  stack_t s;
  initialize(&s);
	data_t a[100];
  printf("Them du lieu vao stack (-1 de ket thuc):\n");
	int i;
	for (i=0;i<5;i++){
		printf("Nhap cho sinh vien thu %d\n",i+1);
		fflush(stdin);
		printf("Nhap mssv : ");
		fflush(stdin);
		scanf("%s",a[i].id);
		printf("Nhap ten : ");
		fflush(stdin);
		gets(a[i].name);
		printf("Nhap diem cho sinh vien : ");
		fflush(stdin);
		scanf("%f",&a[i].grade);
	}
	for (i=0;i<5;i++)
	push(a[i],&s);

  // Pop data from Stack and display to screen
  while (!isEmpty(s)) {
    showData(pop(&s));
  }

  return 0;
}

