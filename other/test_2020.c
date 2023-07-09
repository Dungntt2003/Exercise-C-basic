#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// data.h


typedef struct {
  char place[50];
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
  strcpy(data.place,place);
  data.hour=hour;
  data.minute=minute;
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



int check_time (int hour1, int minute1, int hour2, int minute2){
	if (hour1<hour2)
	return 1;
	if (hour1==hour2 && minute1< minute2)
	return 1;
}



int main() {
	data_t a[100];
	FILE *p;
	char str[100];
	int i=0,n=0,count=0,number=0,dem=0;
	int hour, minute;
	int key;
	node_t* s,h;
	char place[50];
	data_t b;
	root_t lst=llInit();
	while (1){
 	printf("Menu\n");
 	printf("==========================================\n");
 	printf("1.Nap du lieu log lich su di chuyen\n");
 	printf("2.In ra lich su di chuyen\n");
 	printf("3.Tim kiem lich su di chuyen theo dia diem\n");
 	printf("4.Tim kiem lich su di chuyen theo thoi gian\n");
 	printf("5.Kiem tra truy vet moi nhat\n");
 	printf("6.Thoat\n");
 	printf("Choose 1-6 : ");
 	scanf("%d",&key);
		switch (key){
		case 1 :
			p=fopen("C:\\Users\\Admin\\Desktop\\log.txt","r");
			if (p==NULL){
				printf("Nhap du lieu khong thanh cong \n");
			}
			else {
				while (!feof(p)){
					fgets(str,100,p);
					sscanf(str,"%s %d %d",a[i].place,&a[i].hour,&a[i].minute);
					lst = llInsertTail(lst,a[i]);
					i++;
					n++;
				}
				printf("Nap du lieu thanh cong\n");
		}
			break;
		case 2 :
			llPrint(lst);
			break;
		case 3:
			printf("Hay nhap vao 1 dia diem : ");
			fflush(stdin);
			scanf("%s",place);
			for (s=lst;s!=NULL;s=s->next){
				if (strcmp(s->data.place,place)==0){
					printf("%d:%d\n",s->data.hour,s->data.minute);
					count++;
				}
			}
			if (count==0)
			printf("Ban chua toi dia diem do\n");
			break;
		case 4:
			printf("Hay nhap thoi gian: ");
			fflush(stdin);
			do scanf("%d %d",&hour,&minute);
			while (hour<0 || hour>12 && minute<0 || minute>60 );
			for (s=lst;s!=NULL;s=s->next){
				if (s->data.hour== hour && s->data.minute==minute){
					printf("%s\n",s->data.place);
					number++;
				}
			}
			if (number==0)
			printf("Khong tim thay lich su di chuyen\n");
			break;
		case 5:
			printf("Nhap du lieu cho benh nhan covid : ");
			fflush(stdin);
			scanf("%s %d %d",b.place,&b.hour,&b.minute);
			for (s=lst ; s!=NULL ;s=s->next){
				if (strcmp(s->data.place,b.place)==0 && check_time(b.hour,b.minute,s->data.hour,s->data.minute)==1)
				dem++;
			}
			if (dem==0)
			printf("Lich su di chuyen cua ban OK\n");
			else printf("Ban co kha nang bi lay covid, can phai khai bao y te ngay lap tuc !\n");
			break;
		case 6:
			return 1;
		
	}
}
	fclose(p);
	llDeleteAll(lst);
  return 0;
}

