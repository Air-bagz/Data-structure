#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L);
bool Empty(LinkList L);
bool isTail(LinkList L,LNode *p);

int main()
{
	LinkList L;
	InitList(L);
 } 
 
bool InitList(LinkList &L)
{
	L=(LNode *)malloc(sizeof(LNode));
	if (L==NULL)	return false;
	L->next=L;
	return true;
}

bool Empty(LinkList L)				//判断循环单链表是否为空 
{
	if (L->next==L)	return true;
	else return false;
}

bool isTail(LinkList L,LNode *p)	//判断结点p是否为循环单链表的表尾结点 
{
	if (p->next==L)	return true;
	else return false;
}
