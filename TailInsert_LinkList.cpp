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
int length;
while ()
{
	get an e;
	ListInsert(L,length+1,e);
	length++;
}
*/

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

int main()
{
	LinkList L;
	L=List_TailInsert(L);
	PrintList(L);
	return 0;
}
