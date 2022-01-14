//不带头结点的链队列 
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
	LNode *front,*rear;		//单链表只需要一个头指针LNode *L <=> LinkList L 
	//int length;
}LinkQueue;				//链队列需要头指针和尾指针

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
	Q.front=Q.rear=NULL;		//初始front和rear都指向NULL
 } 

void EnQueue(LinkQueue &Q,ElemType x)
{
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=x;
	s->next=NULL;
	if (Q.front==NULL)		//在空队列中插入第一个元素 
	{
		Q.front=s;			//修改队头队尾指针 
		Q.rear=s;
	}
	else {
		Q.rear->next=s;		//新结点插入到rear结点之后 
		Q.rear=s;			//修改rear指针 
	}
}

bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if (IsEmpty(Q))	return false;		//空队
	LNode *p=Q.front;					//p指向此次出队的结点
	x=p->data;							//用变量x返回队头元素
	Q.front=p->next;					//修改front指针
	if (Q.rear==p)						//此次是最后一个结点出队
	{
		Q.front=NULL;					//front指向NULL 
		Q.rear=NULL;					//rear指向NULL 
	 } 
	free(p);							//释放结点空间 
	return true;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front==NULL)	return true;	//或者判断Q.rear==NULL 
	else return false;
}
