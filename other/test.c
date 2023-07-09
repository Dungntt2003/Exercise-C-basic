#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// data.h


typedef struct {
  char place[20];
  int hour;
  int minute;
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
  printf("%-50s %-10d %-10d\n", data.place, data.hour, data.minute);
}

data_t convert(char place[], int hour, int minute) {
  data_t data;
  strcpy(data.place, place);
  data.hour= hour;
  data.minute=minute;
  return data;
}


//llist.c
// Traversing a list and show
root_t llPrint(root_t root) {
	printf("%-50s %-10s %-10s\n","Dia diem","Gio","Phut");
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



void find_place(root_t root, char place[]){
	int count=0;
	node_t* p;
	for (p=root;p!=NULL;p=p->next){
		if (strcmp(p->data.place,place)==0){
			printf("%d:%d,",p->data.hour,p->data.minute);
			count++;
		}
	}
	if (count==0)
	printf("Ban chua toi dia diem do\n");
	printf("\n");
}

void find_time (root_t root, int hour, int minute){
	int count=0;
	node_t* p;
	for (p=root;p!=NULL;p=p->next){
		if (p->data.hour==hour && p->data.minute==minute){
			printf("%s\n",p->data.place);
			count++;
		}
	}
	if (count==0)
	printf("Khong tim thay lich su di chuyen\n");
	
}

int check_time(int hour, int minute,int hour1,int minute1){
	if (hour<hour1)
	return 1;
	if (hour==hour1 && minute<minute1)
	return 1;
	return 0;
}

int check(char place[],int hour, int minute, root_t root){
	node_t* p;
	for (p=root;p!=NULL;p=p->next){
		if (strcmp(p->data.place,place)==0&& check_time(hour,minute,p->data.hour,p->data.minute)==1)
		return 1;
	}
	return 0;
}

int main(){
	FILE *p;
	data_t a;
	char place[20];
	char str[100];
	root_t lst=llInit();
	int hour,minute;
	int key;
	while (1){
		printf("Menu\n");
		printf("=======================================\n");
		printf("1.Nap du lieu log lich su di chuyen\n");
		printf("2.In ra lich su di chuyen\n");
		printf("3.Tim kiem lich su di chuyen theo dia diem\n");
		printf("4.Tim kiem thong tin di chuyen theo thoi gian\n");
		printf("5.Kiem tra truy vet moi nhat\n");
		printf("6.Thoat\n");
		printf("chon 1-6 : ");
		scanf("%d",&key);
		switch (key){
			case 1:
				p=fopen("data.txt","r");
				if (p==NULL){
					printf("Doc file khong thanh cong\n");
					return 1;
				}
				while (!feof(p)){
					fgets(str,100,p);
					sscanf(str,"%s %d %d",a.place,&a.hour,&a.minute);
					lst=llInsertTail(lst,a);
				}
				printf("Doc thanh cong du lieu\n");
				fclose(p);
				break;
			case 2:
				llPrint(lst);
				break;
			case 3:
				printf("Hay nhap dia diem ban muon tim : ");
				scanf("%s",place);
				find_place(lst,place);
				break;
			case 4:
				printf("Hay nhap gio va phut can tim : ");
				do scanf("%d %d",&hour,&minute);
				while (hour<0 || hour>12 || minute<0 || minute >60);
				find_time(lst,hour,minute);
				break;
			case 5:
				printf("Hay nhap lich trinh cua nguoi covid : ");
				scanf("%s %d %d",place,&hour,&minute);
				if (check(place,hour,minute,lst)==1)
				printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc\n");
				else printf("Lich su di chuyen cua ban OK\n");
				break;
			case 6:
				llDeleteAll(lst);
				return 1;
	}
}
return 0;
}
