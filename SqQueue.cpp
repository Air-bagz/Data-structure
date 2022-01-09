#include<stdio.h>
#define MaxSize 10				//���������Ԫ�ص������� 

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];		//�þ�̬�����Ŷ���Ԫ�� 
	int front,rear; 			//��ͷָ��Ͷ�βָ�� 
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

void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}

bool EnQueue(SqQueue &Q,ElemType x)		//��� 
{
	if (QueueFull(Q))	return false;		//�������� 
	Q.data[Q.rear]=x;				//rearָ����һ��Ӧ�ò����λ�� 
	Q.rear=(Q.rear+1)%MaxSize;		//��βָ����ƣ�[0,1,...,MaxSize-1]��״ 
	return true;
}

bool DeQueue(SqQueue &Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;		//�ӿձ���
	x=Q.data[Q.front];				//frontָ���ͷԪ�� 
	Q.front=(Q.front+1)%MaxSize; 	//��ͷָ����ƣ���״ 
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
	if (Q.rear==Q.front)	return true;	//�ӿ����� 
	else return false;
}

bool QueueFull(SqQueue Q)
{
	if ( (Q.rear+1)%MaxSize==Q.front )	return true;	//��������	����һ�� 
	else return false;
 } 

void testQueue()
{
	SqQueue Q;
	InitQueue(Q);
	EnQueue(Q,101);		EnQueue(Q,202);		EnQueue(Q,303);
	int x;
	DeQueue(Q,x);	printf("x=%d\n",x);
	GetHead(Q,x);	printf("x=%d\n",x); 
	printf("%d\n",(Q.rear+MaxSize-Q.front)%MaxSize);
}
