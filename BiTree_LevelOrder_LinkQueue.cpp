#include<stdio.h>
#include<stdlib.h>
//�������Ľ�㣨��ʽ�洢��
typedef struct BiTNode
{
	char data;						//������ 
	struct BiTNode *lchild,*rchild;		//���Һ���ָ�� 
 }BiTNode,*BiTree;
 
typedef BiTNode *	ElemType; 	//ָ�� 
//��ʽ���н�� 
typedef struct LNode
{
	ElemType data;			//��ָ������ǽ�� 
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
	//����һ�ÿ��� 
	BiTree root=NULL;
	//��������
	root=(BiTNode *)malloc(sizeof(BiTNode));
	root->data='A';
	root->lchild=NULL;
	root->rchild=NULL;
	//�����½��
	BiTNode *p=(BiTNode *)malloc(sizeof(BiTNode));
	p->data='B';
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;		//��Ϊ���������� 
	
	//�����½��
	BiTNode *p2=(BiTNode *)malloc(sizeof(BiTNode));
	p2->data='C';
	p2->lchild=NULL;
	p2->rchild=NULL;
	root->rchild=p2;		//��Ϊ�������Һ��� 
	
	LevelOrder(root);
}

//�������
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);					//��ʼ���������� 
	BiTNode * p;
	EnQueue(Q,T);					//���������� 
	while (!IsEmpty(Q))				//���в�����ѭ�� 
	{
		DeQueue(Q,p);				//��ͷ������ 
		visit(p);					//���ʳ��ӽ�� 
		if (p->lchild!=NULL)
			EnQueue(Q,p->lchild);	//������� 
		if (p->rchild!=NULL)
			EnQueue(Q,p->rchild);	//�Һ������ 
	}
 }

void visit(BiTNode * p)
{
	printf("%c\n",p->data);
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
