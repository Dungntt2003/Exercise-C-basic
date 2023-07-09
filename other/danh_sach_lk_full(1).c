#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// data.h


typedef struct {
  char id[10];
  char name[30];
  float grade;
} data_t;

//llist.h

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

//llstudent.h

typedef data_t student_t;

// data.c


void showData(data_t data) { 
  printf("%s - %s - %g\n", data.id, data.name, data.grade);
}

data_t convert(char id[], char name[], float grade) {
  data_t data;
  strcpy(data.id, id);
  strcpy(data.name, name);
  data.grade = grade;
  return data;
}


//llist.c
// Traversing a list and show
root_t llPrint(root_t root) {
	node_t* p;
  for ( p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}

// Create a new Node
// return:
//  - on SUCCESS: return a pointer to new Node
//  - on FAIL   : return a NULL pointer
node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

root_t llInit() { return NULL; }

node_t* llSeek(root_t root, int index) {
  node_t* p;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}

/* === Insert ============================================== */

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

root_t llInsertAfter(root_t root, node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;

  return root;
}

/* === Delete ============================================== */

root_t llDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  node_t* p = root->next;
  free(root);
  return (root_t)p;
}

root_t llDeleteTail(root_t root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }

  node_t* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;

  free(p->next);
  p->next = NULL;
  return (root_t)root;
}

root_t llDeleteAfter(root_t root, node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node_t* pToDelElem = pA->next;
  pA->next = pA->next->next;

  free(pToDelElem);
  return root;
}

root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

/* === Tools ========================================= */
int llLength(root_t root) {
  int count;
  for (count = 0; root!=NULL; root = root->next) count++;
  return count;
}

root_t LLReverse(root_t root) {
  node_t *cur, *prev;

  for (cur = prev = NULL; root != NULL;) {
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  return root;
}

int isEmpty(root_t root) { return root == NULL; }


// llistStudent.c

root_t llInsertSinhVien(root_t root, const student_t sv) {
  if (root == NULL) return llInsertHead(root, sv);

  if (sv.grade > root->data.grade) {
    return llInsertHead(root, sv);
  } else if (root->next == NULL)
    return llInsertTail(root, sv);
	node_t* p;
  for (p = root; p->next != NULL; p = p->next) {
    if (sv.grade > p->next->data.grade) {
      root = llInsertAfter(root, p, sv);
      return root;
    }
  }

  return llInsertTail(root, sv);
}


///Tim kiem theo mssv :

void FindbyID (root_t root, char id[]){
	node_t* p;
	int count=0;
	for (p=root ; p!=NULL ; p=p->next){
		if (strcmp(p->data.id,id)==0){
			printf("%s-%s-%g\n",p->data.id,p->data.name,p->data.grade);
			count++;
		}
	}
	if (count==0) printf("Khong tim thay sinh vien co mssv %s nhu vay\n",id);
	
}


/// xoa sinh vien co mssv xac dinh 

void DeletebyID(root_t root, char id[]){
	node_t* p;
	int count=0;
	for (p=root; p!=NULL ;p=p->next){
		if (strcmp(p->next->data.id,id)==0){
			count++;
			root= llDeleteAfter(root,p);
		}
	}
	if (count==0)
	printf("Khong the xoa vi khong co mssv %s trong danh sach\n",id);
}


// Ghi thong tin sinh vien vao file 

//void WriteonFile(root_t root, FILE *p){
//	node_t* s;
//	for (s=root;s!=NULL;s=s->next){
//		fprintf(p,"%s %s %g\n",s->data.id,s->data.name,s->data.grade);
//	}
//}


//Doc thong tin tu FILE va in ra man hinh

//void ReadFromFile(root_t root, FILE *p){
//	data_t a[100];
//	int n=0,i=0;
//	char str[100];
//	while (!feof(p)){
//		fgets(str,100,p);
//		sscanf(str,"%s %s %f",a[i].id,a[i].name,&a[i].grade);
//		i++;
//		n++;
//	}
//	for (i=0;i<n;i++){
//		printf("%s %s %g\n",a[i].id,a[i].name,a[i].grade);
//	}
//}

///main

int main() {
	// Bai 1  
	
	
	
//  data_t aSV[100];
//  
//  int n,i;
//  do {
//  	printf("Hay nhap so sinh vien trong [2;10] : ");
//  	scanf("%d",&n);
//  }
//  while (n<2 || n>10);
//  
//  for (i=0;i<n;i++){
//  	printf("Hay nhap cho hoc sinh thu %d\n",i+1);
//  	printf("Hay nhap mssv : ");
//  	scanf("%s",aSV[i].id);
//  	printf("Hay nhap ten : ");
//  	fflush(stdin);
//  	gets(aSV[i].name);
//  	printf("Hay nhap diem : ");
//  	do	scanf("%f",&aSV[i].grade);
//  	while (aSV[i].grade<0 || aSV[i].grade>10);
//  }
//  
//  root_t lst = llInit();
//  for ( i = 0; i < n; i++) {
//    lst = llInsertTail(lst, aSV[i]);
//  }
//
//  printf("\n\nPrint all\n");
//  llPrint((lst));
//
//
//  llDeleteAll(lst);


///Bai 2 
	FILE *s,*p;
	root_t lst=llInit();
	data_t a[100];
	char id[10];
	int key,n=0,i=0;
	while (1){
		printf("Menu\n");
		printf("******************************\n");
		printf("1.Chen sinh vien vao dau danh sach\n");
		printf("2.Tim kiem theo mssv\n");
		printf("3.Xoa mssv\n");
		printf("4.Hien thi danh sach sinh vien\n");
		printf("5.Thoat chuong trinh\n");
		printf("6.Doc du lieu ra file\n");
		printf("7.Lay du lieu tu file in ra man hinh\n");
		printf("Chon 1-7 de chay chuong trinh : ");
		scanf("%d",&key);
		switch(key){
			case 1 :
				printf("Hay nhap du lieu cho sinh vien\n");
				printf("Hay nhap id : ");
				scanf("%s",a[i].id);
				printf("Hay nhap ten : ");
				fflush(stdin);
				gets(a[i].name);
				printf("Nhap diem : ");
				scanf("%f",&a[i].grade);
				lst=llInsertHead(lst,a[i]);
				i++;
				n++;
				break;
			case 2:
				printf("Hay nhap mssv muon tim : ");
				scanf("%s",id);
				FindbyID(lst,id);
				break;
			case 3:
				printf("Hay nhap mssv muon tim : ");
				scanf("%s",id);	
				DeletebyID(lst,id);
				break;
			case  4:
				llPrint(lst);
				break;
			case 6 :
				p=fopen("C:\\Users\\Admin\\Desktop\\data.txt","w");
				if (p==NULL){
					printf("Error\n");
					return 1;
				}
					node_t* s;
					for (s=lst;s!=NULL;s=s->next){
						fprintf(p,"%s %s %g\n",s->data.id,s->data.name,s->data.grade);
					}
				break;
			case 7:
				s=fopen("C:\\Users\\Admin\\Desktop\\data.txt","r");
				if (s==NULL){
					printf("Error\n");
					return 1;
				}
				data_t b[100];
				int m=0,j=0,k;
				char str[100];
				while (!feof(s)){
					fgets(str,100,s);
					sscanf(str,"%s %s %f",b[i].id,b[i].name,&b[i].grade);
					j++;
					m++;
				}
				for (k=0;k<m;k++){
					printf("%s %s %g\n",b[k].id,b[k].name,b[k].grade);
				}
				
				break;
			case 5 :
				return 1;
			default:
				printf("Hay chon so trong menu\n");
				break;
		}
	}
	llDeleteAll(lst);
  return 0;
}

