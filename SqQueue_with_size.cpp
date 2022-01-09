#include<stdio.h>

#define MaxSize 10		

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];	
	int front,rear; 		
	int size; 				//���е�ǰ���� 
}SqQueue;

void InitQueue(SqQueue &Q);
bool EnQueue(SqQueue &Q,ElemType x);
bool DeQueue(SqQueue &Q,ElemType &x);
bool GetHead(SqQueue Q,ElemType &x);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);
void testQueue();

int main()
{
	testQueue();
}

void testQueue()
{
	SqQueue Q;
	InitQueue(Q);
	EnQueue(Q,101);		EnQueue(Q,202);		EnQueue(Q,303);
	int x;
	DeQueue(Q,x);	printf("x=%d\n",x);
	GetHead(Q,x);	printf("x=%d\n",x); 
	printf("%d\n",Q.size);
}

void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
	Q.size=0;
}

bool EnQueue(SqQueue &Q,ElemType x)		//��� 
{
	if (QueueFull(Q))	return false;		//�������� 
	Q.data[Q.rear]=x;				//rearָ����һ��Ӧ�ò����λ�� 
	Q.rear=(Q.rear+1)%MaxSize;		//��βָ����ƣ�[0,1,...,MaxSize-1]��״ 
	Q.size++;
	return true;
}

bool DeQueue(SqQueue &Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;		//�ӿձ���
	x=Q.data[Q.front];				//frontָ���ͷԪ�� 
	Q.front=(Q.front+1)%MaxSize; 	//��ͷָ����ƣ���״ 
	Q.size--;
	return true;
}

bool GetHead(SqQueue Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;
	x=Q.data[Q.front];	
	return true;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.size==0)	return true;	//�ӿ����� 
	else return false;
}

bool QueueFull(SqQueue Q)
{
	if ( Q.size==MaxSize )	return true;	//��������	������ 
	else return false;
 } 
