//����ͷ���������� 
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
	Q.front=Q.rear=NULL;		//��ʼfront��rear��ָ��NULL
 } 

void EnQueue(LinkQueue &Q,ElemType x)
{
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=x;
	s->next=NULL;
	if (Q.front==NULL)		//�ڿն����в����һ��Ԫ�� 
	{
		Q.front=s;			//�޸Ķ�ͷ��βָ�� 
		Q.rear=s;
	}
	else {
		Q.rear->next=s;		//�½����뵽rear���֮�� 
		Q.rear=s;			//�޸�rearָ�� 
	}
}

bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if (IsEmpty(Q))	return false;		//�ն�
	LNode *p=Q.front;					//pָ��˴γ��ӵĽ��
	x=p->data;							//�ñ���x���ض�ͷԪ��
	Q.front=p->next;					//�޸�frontָ��
	if (Q.rear==p)						//�˴������һ��������
	{
		Q.front=NULL;					//frontָ��NULL 
		Q.rear=NULL;					//rearָ��NULL 
	 } 
	free(p);							//�ͷŽ��ռ� 
	return true;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front==NULL)	return true;	//�����ж�Q.rear==NULL 
	else return false;
}
