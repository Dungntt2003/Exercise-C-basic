#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void docfile(FILE *p, FILE *ghi){
    char str[100];
    int a[100];
    int i = 0;
    int n = 0;
    fgets(str, 100, p);
    sscanf(str, "%d", &n);
    for (i = 0; i < n && !feof(p); i++){
        fgets(str, 100, p);
        sscanf(str, "%d", &a[i]);
        if (a[i] > 5){
            fprintf(ghi, "%d\n", a[i]);
        }
    }
    if (ghi == NULL) {
    printf("Failed to open file float2.txt.\n");
    } else printf("Done\n");
}

int main(){
    FILE* p, *ghi;
    char filename[30], name[30];
    printf("Nhap ten file muon doc!");
    scanf("%s", filename);
    p = fopen(filename, "r");
    if (p == NULL){
        printf("File not found\n");
        return 0;
    }
    printf("Nhap ten file muon ghi gia tri > 5!");
    scanf("%s", name);
    ghi = fopen(name, "w");
    if (ghi == NULL){
        printf("File not found\n");
        return 0;
    }
    docfile(p, ghi);
    fclose(p);
    fclose(ghi);
    return 0;
}
//Doc tu file.txt roi ghi vao float2.txt
