#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ql{
    char str1[20], str2[20], str3[20];
    int ng,th,na;
    struct ql *next;
}ql;
ql* head, *tail;


void insert_tolast(char *str1, int ng, int th, int na, char *str2, char *str3){
    ql* newnode=(ql*)malloc(sizeof(ql));
    if(newnode==NULL){
        printf("cap phat loi ram\n");
        return;
    }
    strcpy(newnode->str1, str1);
    newnode->ng=ng;
    newnode->th=th;
    newnode->na=na;
    strcpy(newnode->str2, str2);
    strcpy(newnode->str3,str3);
    newnode->next=NULL;
    if(head==NULL && tail==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}

void freeql(){
    ql* tmp=head, *tmp1;
    while(tmp!=NULL){
        tmp1=tmp;
        free(tmp);
        tmp=tmp1->next;
    }
}

void duyet(){
    ql *tmp;
    for(tmp=head; tmp->next!=NULL; tmp=tmp->next){
        printf("%s\t%d/%d/%d\t%s\n", tmp->str1, tmp->ng,tmp->th,tmp->na,tmp->str2);
        printf("%s\n", tmp->str3);
    }
}

void readFile(char *filename){
 
    FILE* f=fopen(filename, "r");
    if(f==NULL){
        printf("File khong ton tai!\n");
        exit(0);
    }
    char str1[20], str2[20],str3[20]; int ng,th,na;
    while(!feof(f)){
        fscanf(f, "%s\t%d/%d/%d\t%[^\n]", str1, &ng,&th,&na,str2);
        fscanf(f, "%[^\n]",str3);

        insert_tolast(str1,ng,th,na,str2,str3);
    }
    fclose(f);
}
//
void readfile(){
    char filename[20];
    printf("Nhap ten file:\n");
    scanf("%s", filename);
    readFile(filename);
}

int main(){
    readfile();
    duyet();
    return 0;
    freeql();
}