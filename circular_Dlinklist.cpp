#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct DNode	
{
	ElemType data;				
	struct DNode *prior,*next;	
 }DNode,*DLinklist; 
 
bool InitDLinklist(DLinklist &L)
{
	L=(DNode *)malloc(sizeof(DNode));
	if (L==NULL)	return false;
	L->prior=L;
	L->next=L;
	return true;
}

bool Empty(DLinklist L)			//�ж�ѭ��˫�����Ƿ�Ϊ�� 
{
	if (L->next==L)	return true;
	else return false;
}

bool isTail(DLinklist L,DNode *p)	//�жϽ��p�Ƿ�Ϊѭ��������ı�β��� 
{
	if (p->next==L)	return true;
	else return false;
}

bool InsertNextDNode(DNode *p,DNode *s)
{
	s->next=p->next;
	p->next->prior=s;
	s->prior=p;
	p->next=s;
}

bool DeleteNextDNode(DNode *p);		//ɾ��p�ĺ�̽��q 
{
	DNode *q=p->next;
	p->next=q->next;
	q->next->prior=p;
	free(q);
}

void testDLinklist()
{
	DLinklist L;
	InitDLinklist(L);
 } 
 
int main()
{
	testDLinklist();
}

