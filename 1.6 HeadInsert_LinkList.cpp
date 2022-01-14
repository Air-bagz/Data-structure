#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

/*
InitList;
while ()
{
	get an e;
	InsertNextNode(L,e);
}
*/

void InitList(LinkList &L);
void InsertNextNode(LNode *p,ElemType e);
void List_HeadInsert2(LinkList &L);
LinkList List_HeadInsert(LinkList &L);
void PrintList(LinkList L);

int main()
{
	LinkList L;
	//L=List_HeadInsert(L);
	InitList(L);
	List_HeadInsert2(L);
	PrintList(L);
	return 0;
}

void InitList(LinkList &L)
{
	L=(LNode *)malloc(sizeof(LNode));	
	L->next=NULL;
}

void InsertNextNode(LNode *p,ElemType e)
{
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
}

void List_HeadInsert2(LinkList &L)
{
	int x;
	scanf("%d",&x);
	while (x!=9999)
	{
		InsertNextNode(L,x);
		scanf("%d",&x);
	}
}

LinkList List_HeadInsert(LinkList &L)
{
	LNode *s;
	int x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&x);
	while (x!=9999)
	{
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}

void PrintList(LinkList L)
{
	LNode *p;
	for (p=L->next;p!=NULL;p=p->next)
		printf("%d\n",p->data);
}
