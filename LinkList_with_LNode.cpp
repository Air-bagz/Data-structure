//带头结点的单链表 
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L);
LNode *GetElem(LinkList L,int i);				//i in [0,\infty]	O(n)
bool InsertNextNode(LNode *p,ElemType e);		 //p is key			O(1)
bool ListInsert(LinkList &L,int i,ElemType e);	//i in [1,\infty]	O(n)
bool ListDelete(LinkList &L,int i,ElemType &e); //i in [1,\infty]	O(n)
LNode *LocateElem(LinkList L,ElemType e);
void PrintList(LinkList L); 
int Length(LinkList L);

int main()
{
	LinkList L;
	InitList(L);
	ListInsert(L,1,101);	ListInsert(L,2,202);	ListInsert(L,3,303);
	PrintList(L);
	
	int e=-1;
	if (ListDelete(L,2,e))	printf("已删除第2个元素，值为%d\n",e);
		else printf("删除失败");
	PrintList(L);
	
	LNode *p=LocateElem(L,303);		printf("%d\n",p->data);
	
	printf("length=%d\n",Length(L));
	return 0; 
}

bool InitList(LinkList &L)
{
	L=(LNode *)malloc(sizeof(LNode));
	if (L==NULL)	return false;
	L->next=NULL;
	return true;
}

LNode *GetElem(LinkList L,int i)
{
	if(i<0)	return NULL;
	LNode *p=L;
	int j=0;
	while (p!=NULL && j<i)	//until j==i or p==NULL
	{
		p=p->next;
		j++;
	}
	return p;
}

bool InsertNextNode(LNode *p,ElemType e)
{
	if (p==NULL)	return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if (s==NULL)	return false;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

bool ListInsert(LinkList &L,int i,ElemType e)
{
	if(i<1)	return false;//if i is big then p==NULL then InsertNext==false then Insert==false
	LNode *p=GetElem(L,i-1);
	return InsertNextNode(p,e);
}

bool ListDelete(LinkList &L,int i,ElemType &e)
{
	if(i<1)	return false;
	LNode *p=GetElem(L,i-1);
	if(p==NULL) return false;
	if(p->next==NULL) return false;
	LNode *q=p->next;		//p----q
	e=q->data;
	p->next=q->next;
	free(q);
	return true;
}

LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p=L->next;
	while (p!=NULL && p->data!=e)
		p=p->next;
	return p;
}

void PrintList(LinkList L)
{
	LNode *p;
	for (p=L->next;p!=NULL;p=p->next)
		printf("%d\n",p->data);
}

int Length(LinkList L)
{
	int len=0;
	LNode *p=L;
	while (p->next !=NULL)
	{
		p=p->next;
		len++;
	}
	return len;
}
