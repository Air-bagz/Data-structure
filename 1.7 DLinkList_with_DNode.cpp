#include<stdio.h>
#include<stdlib.h>

typedef int ElemType; 

typedef struct DNode		//定义双链表结点类型 
{
	ElemType data;				//数据域 
	struct DNode *prior,*next;	//前驱和后继指针 
 }DNode,*DLinkList; 
 
bool InitDLinkList(DLinkList &L);
void DestroyList(DLinkList &L);
bool InsertNextDNode(DNode *p, DNode *s);
bool DeleteNextDNode(DNode *p);
bool Empty(DLinkList L);

int main()
{
	DLinkList L;
	InitDLinkList(L);
	if (Empty(L))	printf("empty\n");
		else	printf("not empty\n");
	DNode *s=(DNode *)malloc(sizeof(DNode));
	s->data=101;
	InsertNextDNode(L,s);
	if (Empty(L))	printf("empty\n");
		else	printf("not empty\n");	
		
	DestroyList(L);
	return 0;
}

bool InitDLinkList(DLinkList &L)
{
	L=(DNode *)malloc(sizeof(DNode));
	if (L==NULL)	return false;	 
	L->prior=NULL;
	L->next=NULL;
	return true;
}

void DestroyList(DLinkList &L)
{
	while (L->next!=NULL)		//循环释放各个数据结点 
		DeleteNextDNode(L);
	free(L);				//释放头结点 
	L=NULL;					//头指针指向NULL 
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

bool DeleteNextDNode(DNode *p)
{
	if (p==NULL)	return false;
	DNode *q=p->next;
	if (q==NULL)	return false;
	p->next=q->next;
	if (q->next!=NULL)			//q结点不是最后一个结点
		q->next->prior=p;
	free(q);
	return true; 
}

bool Empty(DLinkList L)
{
	if (L->next==NULL)	return true;
	else return false;
}
