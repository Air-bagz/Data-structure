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

int main()
{
	LinkList L;
	L=List_HeadInsert(L);
	PrintList(L);
	return 0;
}
