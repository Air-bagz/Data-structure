#include<stdio.h>

#define MaxSize 10		

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];	
	int front,rear; 		
	int tag; 				//最近进行的是删除/插入 
}SqQueue;

void InitQueue(SqQueue &Q);
bool EnQueue(SqQueue &Q,ElemType x);	//tag=1
bool DeQueue(SqQueue &Q,ElemType &x);	//tag=0
bool GetHead(SqQueue Q,ElemType &x);
bool QueueEmpty(SqQueue Q);//tag=0
bool QueueFull(SqQueue Q);//tag=1
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
	printf("%d\n",(Q.rear+MaxSize-Q.front)%MaxSize);
}

void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
	Q.tag=0;
}

bool EnQueue(SqQueue &Q,ElemType x)		//入队 
{
	if (QueueFull(Q))	return false;		//队满报错 
	Q.data[Q.rear]=x;				//rear指向下一个应该插入的位置 
	Q.rear=(Q.rear+1)%MaxSize;		//队尾指针后移，[0,1,...,MaxSize-1]环状 
	Q.tag=1;
	return true;
}

bool DeQueue(SqQueue &Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;		//队空报错
	x=Q.data[Q.front];				//front指向队头元素 
	Q.front=(Q.front+1)%MaxSize; 	//队头指针后移，环状 
	Q.tag=0;
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
	if ( (Q.front==Q.rear)&&(Q.tag==0) )	return true;	//队空条件 
	else return false;
}

bool QueueFull(SqQueue Q)
{
	if ( (Q.front==Q.rear)&&(Q.tag==1) )	return true;	//队满条件	无牺牲 
	else return false;
 } 
