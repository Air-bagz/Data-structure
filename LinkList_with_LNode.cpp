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
void DestroyList(LinkList &L);
LNode *GetElem(LinkList L,int i);				//i in [0,\infty]	O(n)
bool InsertNextNode(LNode *p,ElemType e);		 //p is key			O(1)
bool ListInsert(LinkList &L,int i,ElemType e);	//i in [1,\infty]	O(n)
bool ListDelete(LinkList &L,int i,ElemType &e); //i in [1,\infty]	O(n)
bool DeleteNode1(LinkList &L,LNode *p);
bool DeleteNode2(LNode *p);
LNode *LocateElem(LinkList L,ElemType e);
int Length(LinkList L);
void PrintList(LinkList L); 

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
	
	LNode *p=LocateElem(L,303);		printf("  %d\n",p->data);
	
	printf("length=%d\n",Length(L));
	
	DeleteNode1(L,p);	printf("删除p结点后length=%d\n",Length(L));		PrintList(L);	
	
	LNode *p2=LocateElem(L,101);	DeleteNode2(p2);	printf("删除p结点后length=%d\n",Length(L));		PrintList(L);	//剩一个结点删除失灵 
	
	DestroyList(L);		
	
	return 0; 
}

bool InitList(LinkList &L)
{
	L=(LNode *)malloc(sizeof(LNode));	
	if (L==NULL)	return false;
	L->next=NULL;
	return true;
}

void DestroyList(LinkList &L)
{	
	LNode *q=L->next;
	while (q!=NULL)		//只要L后继不空，就删后继q 
	{
		L->next=q->next;		//while (L->next!=NULL) 	DeleteNode2(L); 
		free(q);			
		q=L->next;
	}
	printf("销毁链表后length=%d\n",Length(L));
	free(L);		//释放头结点 
	L->next=NULL; 	//头指针指向NULL 
}

LNode *GetElem(LinkList L,int i)
{
	if(i<0)	return NULL;
	LNode *p=L;		//从第0个结点开始 
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

bool DeleteNode1(LinkList &L,LNode *p)
{
	LNode *pp=L;
	while (pp->next != p)
		pp=pp->next;
	pp->next=p->next;
	free(p);
 } 

bool DeleteNode2(LNode *p)
{
	if (p==NULL)	return false;	//空的删失败 
	if (p->next==NULL)	return false;	//最后一个删失败 
	LNode *q=p->next;			//令q指向*p的后继结点 
	p->data=q->data;			//和后继结点交换数据域 
	p->next=q->next;			//将*q结点从链中断开 
	free(q);					//释放后继结点的存储空间 
	return true; 
}

LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p=L->next;	//从第1个结点开始找,p!=NULL
	while (p!=NULL && p->data!=e)
		p=p->next;
	return p;
}

int Length(LinkList L)
{
	int len=0;
	LNode *p=L;		//从第0个结点开始,p->next!=NULL
	while (p->next !=NULL)
	{
		p=p->next;
		len++;
	}
	return len;
}

void PrintList(LinkList L)
{
	LNode *p;
	for (p=L->next;p!=NULL;p=p->next)	//从第1个结点开始,p!=NULL
		printf("%d\n",p->data);
}
//其实统一化都应该从第0个结点(表头)开始，因为单链表可能只有表头，无伤大雅 
