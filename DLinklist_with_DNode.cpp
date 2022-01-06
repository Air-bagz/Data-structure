#include<stdio.h>
#include<stdlib.h>

typedef int ElemType; 

typedef struct DNode		//定义双链表结点类型 
{
	ElemType data;				//数据域 
	struct DNode *prior,*next;	//前驱和后继指针 
 }DNode,*DLinklist; 
 
bool InitDLinklist(DLinklist &L)
{
	L=(DNode *)malloc(sizeof(DNode));
	if (L==NULL)	return false;	 
	L->prior=NULL;
	L->next=NULL;
	return true;
}

bool Empty(DLinklist L)
{
	if (L->next==NULL)	return true;
	else return false;
}

bool InsertNextDNode(DNode *p, DNode *s)
{
	if (p==NULL||s==NULL)	return false;
	s->next=p->next;
	if (p->next != NULL)	p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}

void testDLinklist()
{
	DLinklist L;
	InitDLinklist(L);
	if (Empty(L))	printf("empty\n");
		else	printf("not empty\n");
	DNode *s=(DNode *)malloc(sizeof(DNode));
	s->data=101;
	InsertNextDNode(L,s);
	if (Empty(L))	printf("empty\n");
		else	printf("not empty\n");
 } 

int main()
{
	DLinklist L;
	testDLinklist();
	return 0;
}
