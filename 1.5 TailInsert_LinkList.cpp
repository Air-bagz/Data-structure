#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

/*	O(n^2)
InitList;
int length=0;
while ()
{
	get an e;
	ListInsert(L,length+1,e);
	length++;
}
*/

void InitList(LinkList &L);
void InsertNextNode(LNode *p,ElemType e);
void List_TailInsert2(LinkList &L);
LinkList List_TailInsert(LinkList &L);
void PrintList(LinkList L);

int main()
{
	LinkList L;
	InitList(L);
	//L=List_TailInsert(L);
	List_TailInsert2(L);
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

void List_TailInsert2(LinkList &L)
{
	int x;
	LNode *s,*r=L;		//rear
	scanf("%d",&x);
	while (x!=9999)
	{
		InsertNextNode(r,x);
		r=r->next;
		scanf("%d",&x);
	}
	r->next=NULL;
}

LinkList List_TailInsert(LinkList &L)	//O(n)
{
	int x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	LNode *s,*r=L;		//rear
	scanf("%d",&x);
	while (x!=9999)
	{
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
}

void PrintList(LinkList L)
{
	LNode *p;
	for (p=L->next;p!=NULL;p=p->next)
		printf("%d\n",p->data);
}
