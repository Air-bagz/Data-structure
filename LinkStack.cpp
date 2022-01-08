//��ͷ������ջ 
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;				//������ 
	struct LNode *next;
}LNode,*LinkStack;				//ջ���Ͷ��� 

void InitStack(LinkStack &S)
{
	S=(LNode *)malloc(sizeof(LNode));	
	S->next=NULL;
}

void InsertNextNode(LNode *p,ElemType e)			//void Push(LinkStack S,ElemType e)
{
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
}

void DeleteNextLNode(LNode *p)			//void Pop(LinkStack S)		
{
	LNode *q=p->next;
	printf("pop is %d\n",q->data);
	p->next=q->next;
	free(q);
}

int main()
{
	LinkStack S;
	InitStack(S);
	InsertNextNode(S,101);	InsertNextNode(S,202);		InsertNextNode(S,303);
	DeleteNextLNode(S);		DeleteNextLNode(S);
}
