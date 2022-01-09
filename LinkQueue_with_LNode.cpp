//带头结点的链队列 
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
	Q.front=Q.rear=(LNode *)malloc(sizeof(LNode));		//初始front和rear都指向头结点 
	Q.front->next=NULL;
 } 

void EnQueue(LinkQueue &Q,ElemType x)
{
	LNode *s=(LNode *)malloc(sizeof(LNode *));
	s->data=x;
	s->next=NULL;			//入队的肯定是最后一个
	Q.rear->next=s;			//新结点插入到rear之后
	Q.rear=s;			//修改表尾指针 
}

bool DeQueue(LinkQueue &Q,ElemType &x) 
{
	if (IsEmpty(Q))	return false;	//空队
	LNode *p=Q.front->next;
	x=p->data;						//用变量x返回队头元素 
	Q.front->next=p->next;			//修改头结点的next指针 
	if (Q.rear==p)	Q.rear=Q.front;	//此次是最后一个结点出队，修改rear指针 
	free(p);						//释放结点空间 
	return true; 
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front==Q.rear)	return true;	//或者判断Q.front->next==NULL 
	else return false;
}
