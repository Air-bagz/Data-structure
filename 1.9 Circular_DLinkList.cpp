#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct DNode	
{
	ElemType data;				
	struct DNode *prior,*next;	
 }DNode,*DLinkList; 
 
bool InitDLinkList(DLinkList &L);
void InsertNextDNode(DNode *p,DNode *s);
void DeleteNextDNode(DNode *p);
bool Empty(DLinkList L);
bool isTail(DLinkList L,DNode *p);

int main()
{
	DLinkList L;
	InitDLinkList(L);
	if (Empty(L))	printf("empty\n");
		else	printf("not empty\n");	
}

bool InitDLinkList(DLinkList &L)
{
	L=(DNode *)malloc(sizeof(DNode));
	if (L==NULL)	return false;
	L->prior=L;
	L->next=L;
	return true;
}

void InsertNextDNode(DNode *p,DNode *s)
{
	s->next=p->next;
	p->next->prior=s;
	s->prior=p;
	p->next=s;
}

void DeleteNextDNode(DNode *p)		//删除p的后继结点q 
{
	DNode *q=p->next;
	p->next=q->next;
	q->next->prior=p;
	free(q);
}

bool Empty(DLinkList L)			//判断循环双链表是否为空 
{
	if (L->next==L)	return true;
	else return false;
}

bool isTail(DLinkList L,DNode *p)	//判断结点p是否为循环单链表的表尾结点 
{
	if (p->next==L)	return true;
	else return false;
}
