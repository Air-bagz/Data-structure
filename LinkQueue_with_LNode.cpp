//��ͷ���������� 
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode;

typedef struct
{
	LNode *front,*rear;		//������ֻ��Ҫһ��ͷָ��LNode *L <=> LinkList L 
	//int length;
}LinkQueue;				//��������Ҫͷָ���βָ��

void InitQueue(LinkQueue &Q);
void EnQueue(LinkQueue &Q,ElemType x); 
bool DeQueue(LinkQueue &Q,ElemType &x); 
bool IsEmpty(LinkQueue Q); 
void testLinkQueue();
 
int main()
{
	testLinkQueue();
}

void testLinkQueue()
{
	LinkQueue Q;
 	InitQueue(Q);
 	EnQueue(Q,101); 	EnQueue(Q,202);		EnQueue(Q,303);
 	int x;
 	DeQueue(Q,x);	printf("x=%d\n",x);
 	if (IsEmpty(Q))	printf("empty\n");
 	else printf("not empty\n");
}

void InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(LNode *)malloc(sizeof(LNode));		//��ʼfront��rear��ָ��ͷ��� 
	Q.front->next=NULL;
 } 

void EnQueue(LinkQueue &Q,ElemType x)
{
	LNode *s=(LNode *)malloc(sizeof(LNode *));
	s->data=x;
	s->next=NULL;			//��ӵĿ϶������һ��
	Q.rear->next=s;			//�½����뵽rear֮��
	Q.rear=s;			//�޸ı�βָ�� 
}

bool DeQueue(LinkQueue &Q,ElemType &x) 
{
	if (IsEmpty(Q))	return false;	//�ն�
	LNode *p=Q.front->next;
	x=p->data;						//�ñ���x���ض�ͷԪ�� 
	Q.front->next=p->next;			//�޸�ͷ����nextָ�� 
	if (Q.rear==p)	Q.rear=Q.front;	//�˴������һ�������ӣ��޸�rearָ�� 
	free(p);						//�ͷŽ��ռ� 
	return true; 
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front==Q.rear)	return true;	//�����ж�Q.front->next==NULL 
	else return false;
}
