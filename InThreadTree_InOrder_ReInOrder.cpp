#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
//�������������
typedef char ElemType;

typedef struct ThreadNode
{
	ElemType data;							//������ 
	struct ThreadNode *lchild,*rchild;		//���Һ���ָ�� 
	int ltag,rtag;							//����������־ 
 }ThreadNode,*ThreadTree; 
 
ThreadNode *pre=NULL;		//ȫ�ֱ���pre��ָ��ǰ���ʽ���ǰ�� 
char xulie[MaxSize]={"ABD#G##E##CF###"};	//PPT��������ȫ�ֱ�����������Ҫÿ�δ��� 
int num=0;				//����ȫ�ֱ�����������Ҫÿ�δ��� 

void CreateBiTree(ThreadTree &T);
void InOrder_O_n(ThreadTree T);
void visit_ordinary(ThreadNode * p);
//------------------1.���������������ݹ������������------------------------------------------------------------------------
void CreateInThread(ThreadTree &T); 
void InThread(ThreadTree T);
void visit_thread(ThreadNode *q);
//-----------------2.�������������������õ���������������-------------------------------------------------------------------- 
ThreadNode *FirstNode(ThreadNode *p);
ThreadNode *NextNode(ThreadNode *p);
void InOrder_O_1(ThreadNode *T);
//-----------------3.�������������������������������һ����㿪ʼ�����������̣�����ʵ���������-------------------------------- 
ThreadNode *LastNode(ThreadNode *p);
ThreadNode *PreNode(ThreadNode *p);
void ReInOrder(ThreadNode *T);
//-----------------4.��������������������������������һ����㿪ʼ����������ǰ��������ʵ�������������------------------------- 

int main()
{			 
	//scanf("%s",xulie);
	ThreadTree T=NULL;
	CreateBiTree(T);		//1.1���������� 
			printf("InOrder_O_n:");
		InOrder_O_n(T);		//1.2�ݹ����������ͬʱ�������������ɹ���� 
			printf("\n");
	CreateInThread(T);		//2.������������������ 
			printf("InOrder_O_1:");
		InOrder_O_1(T);		//3.�ǵݹ�������� 
			printf("\n");
			printf("ReInOrder_O_1:");
		ReInOrder(T); 		//4.�ǵݹ������������	
			printf("\n");
	return 0;
}

void CreateBiTree(ThreadTree &T)	//������������������������������պ�����#��ʾ 
{
	char ch;
	ch=xulie[num++]; //���߲���
	if (ch=='#') T=NULL;
	else
	{
		T=(ThreadNode *)malloc(sizeof(ThreadNode));
		T->data=ch; //���ɸ��ڵ�
		T->ltag=0;	T->rtag=0;	//�����ʼ��������������� 
		CreateBiTree(T->lchild);//����������
		CreateBiTree(T->rchild);//����������
	}
}

void InOrder_O_n(ThreadTree T)		//�ռ临�Ӷ�O(n)		������֤�����������ɹ��� 
{
	if (T!=NULL)
	{
		InOrder_O_n(T->lchild);		//�ݹ���������� 
		visit_ordinary(T);				//���ʸ���� 
		InOrder_O_n(T->rchild);		//�ݹ���������� 
	}
 } 

void visit_ordinary(ThreadNode * p)
{
	printf("%c",p->data);
}

void CreateInThread(ThreadTree &T)
{
	pre=NULL;		//pre��ʼΪNULL
	if (T!=NULL)	//�ǿն��������������� 
	{
		InThread(T);		//���������������� 
		if (pre->rchild==NULL)
			pre->rtag=1;		//������������һ����� 
	 } 
}

//���������������һ�߱���һ�������� 
void InThread(ThreadTree T)
{
	if (T!=NULL)
	{
		InThread(T->lchild);		//������������� 
		visit_thread(T);			//���ʸ���� 
		InThread(T->rchild);		//������������� 
	}
 } 
 
void visit_thread(ThreadNode *now)
{
	if (now->lchild==NULL)			//������Ϊ�գ�����ǰ������  pre<--now
	{
		now->lchild=pre;
		now->ltag=1;
	}
	if (pre!=NULL && pre->rchild==NULL)
	{
		pre->rchild=now;			//����ǰ�����ĺ������  pre---->now
		pre->rtag=1;
	}
	pre=now;
}

//�ҵ���pΪ���������У���һ������������Ľ�� 
ThreadNode *FirstNode(ThreadNode *p)	
{
	while (p->ltag==0)	p=p->lchild;	//ѭ���ҵ������½�㣨��һ����Ҷ��㣩 
	return p; 
 } 

//�������������������ҵ����p�ĺ�̽��
ThreadNode *NextNode(ThreadNode *p)
{
	if (p->rtag==0)	return FirstNode(p->rchild);	//�����������½�� 
	else return p->rchild;	//rtag==1ֱ�ӷ��غ������ 
 } 

//�������������������������������������ʵ�ֵķǵݹ��㷨�� �ռ临�Ӷ�O(1)
void InOrder_O_1(ThreadNode *T)
{
	for (ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
		visit_ordinary(p);
 } 
 
//�ҵ���pΪ���������У����һ������������Ľ��
ThreadNode *LastNode(ThreadNode *p)
{
	while (p->rtag==0) p=p->rchild;
	return p;
 } 
 
//�������������������ҵ����p��ǰ�����
ThreadNode *PreNode(ThreadNode *p)
{
	if (p->ltag==0)	return LastNode(p->lchild);
	else return p->lchild;		//ltag==1ֱ�ӷ���ǰ������ 
 } 
 
//�������������������������������
void ReInOrder(ThreadNode *T)
{
	for (ThreadNode *p=LastNode(T);p!=NULL;p=PreNode(p))
		visit_ordinary(p);
 } 
