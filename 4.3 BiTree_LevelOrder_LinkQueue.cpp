#include<stdio.h>
#include<stdlib.h>
//二叉树的结点（链式存储）
typedef struct BiTNode
{
	char data;						//数据域 
	struct BiTNode *lchild,*rchild;		//左、右孩子指针 
 }BiTNode,*BiTree;
 
typedef BiTNode *	ElemType; 	//指针 
//链式队列结点 
typedef struct LNode
{
	ElemType data;			//存指针而不是结点 
	struct LNode *next;
}LNode;

typedef struct
{
	LNode *front,*rear;		
	//int length;
}LinkQueue;	

void LevelOrder(BiTree T);
void InitQueue(LinkQueue &Q);
void EnQueue(LinkQueue &Q,ElemType x); 
bool DeQueue(LinkQueue &Q,ElemType &x); 
bool IsEmpty(LinkQueue Q); 
void visit(BiTNode * p);

int main()
{
	//定义一棵空树 
	BiTree root=NULL;
	//插入根结点
	root=(BiTNode *)malloc(sizeof(BiTNode));
	root->data='A';
	root->lchild=NULL;
	root->rchild=NULL;
	//插入新结点
	BiTNode *p=(BiTNode *)malloc(sizeof(BiTNode));
	p->data='B';
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;		//作为根结点的左孩子 
	
	//插入新结点
	BiTNode *p2=(BiTNode *)malloc(sizeof(BiTNode));
	p2->data='C';
	p2->lchild=NULL;
	p2->rchild=NULL;
	root->rchild=p2;		//作为根结点的右孩子 
	
	LevelOrder(root);
}

//层序遍历
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);					//初始化辅助队列 
	BiTNode * p;
	EnQueue(Q,T);					//将根结点入队 
	while (!IsEmpty(Q))				//队列不空则循环 
	{
		DeQueue(Q,p);				//队头结点出队 
		visit(p);					//访问出队结点 
		if (p->lchild!=NULL)
			EnQueue(Q,p->lchild);	//左孩子入队 
		if (p->rchild!=NULL)
			EnQueue(Q,p->rchild);	//右孩子入队 
	}
 }

void visit(BiTNode * p)
{
	printf("%c\n",p->data);
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
