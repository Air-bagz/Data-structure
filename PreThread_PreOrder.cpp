#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
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
void PreOrder_O_n(ThreadTree T);
void visit_ordinary(ThreadNode * p);
//--------------------1.���������������ݹ������������----------------------------------------------------------
void CreatePreThread(ThreadTree &T);
void PreThread(ThreadTree T);
void visit_thread(ThreadNode *now);
//--------------------2.�������������������õ���������������-----------------------------------------------------
ThreadNode *FirstNode(ThreadNode *p);
ThreadNode *NextNode(ThreadNode *p);
void PreOrder_O_1(ThreadNode *T);
//--------------------3.�������������������������������һ����㿪ʼ�����������̣�����ʵ���������-------------------------- 
void Print(ThreadNode * x);	//���� 
//----------------------��������һ���ֶ������������ķ�����ԭʼ�򵥣�---------------------------
ThreadNode *CreateNode(ElemType data);	
void CreateBiTree_simple(ThreadTree &T); 

int main()
{
	ThreadTree T=NULL;
	CreateBiTree(T);		//1.1����������
			printf("PreOrder_O_n:");
		PreOrder_O_n(T);	//1.2�ݹ����������ͬʱ�������������ɹ���� 
			printf("\n");
	CreatePreThread(T);		//2.������������������ 
//	Print(T);
//	Print(T->lchild); 
//	Print(T->lchild->lchild);
//	Print(T->lchild->lchild->lchild);
//	Print(T->lchild->lchild->rchild);
//	Print(T->lchild->rchild);
//	Print(T->rchild);
//	Print(T->rchild->lchild);
//	Print(T->rchild->lchild->rchild);
			printf("PreOrder_O_1:");
		PreOrder_O_1(T);	//3.�ǵݹ�������� 
			printf("\n");
	
	ThreadTree root;
	CreateBiTree_simple(root);	//��һ�ַ������������� 
	PreOrder_O_n(root);		printf("\n");
	CreatePreThread(root);
	PreOrder_O_1(root);
	
	return 0;
}

void Print(ThreadNode * x)
{
	if (x==NULL)	printf("NULL!\n");
	else
	printf("data:%c  ltag:%d  rtag:%d\n",x->data,x->ltag,x->rtag);
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

void PreOrder_O_n(ThreadTree T)			//������� 	�ռ临�Ӷ�O(n)	������֤�����������ɹ��� 
{
	if (T!=NULL)
	{
		visit_ordinary(T);				//���ʸ���� 
		PreOrder_O_n(T->lchild);	//�ݹ���������� 
		PreOrder_O_n(T->rchild);	//�ݹ���������� 
	}
 } 

void visit_ordinary(ThreadNode * p)
{
	printf("%c",p->data);
}

void CreatePreThread(ThreadTree &T)
{
	pre=NULL;		//pre��ʼΪNULL
	if (T!=NULL)	//�ǿն��������������� 
	{
		PreThread(T);		//���������������� 
		if (pre->rchild==NULL)
			pre->rtag=1;		//������������һ����� 
	 } 
}

//���������������һ�߱���һ�������� 
void PreThread(ThreadTree T)
{
	if (T!=NULL)
	{
		visit_thread(T);					//�ȷ��ʸ���� 
		if (T->ltag==0)	//lchildָ�����ӣ�����ǰ������ ����ֹ����תȦѭ�� 
			PreThread(T->lchild);		//������������� 
		if (T->rtag==0)  PreThread(T->rchild);		//������������� 	�޸�֮ǰPreThread(T->rchild);
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
	return p; 
 } 

//�������������������ҵ����p�ĺ�̽��
ThreadNode *NextNode(ThreadNode *p)
{
	if (p->rtag==0)	
		{
			if (p->lchild!=NULL && p->ltag==0)	return FirstNode(p->lchild);	//��������(�����Ǽٵ����ӣ�������p�����Ӽ������������������һ��������p��������Ϊp������ 
			else 	return FirstNode(p->rchild); 	//�������ӣ�����p���Һ��������������������һ��������p��������Ϊp���Һ���
		 } 
	else return p->rchild;	//rtag==1ֱ�ӷ��غ������ 
 } 
 
//�������������������������������������ʵ�ֵķǵݹ��㷨�� �ռ临�Ӷ�O(1)
void PreOrder_O_1(ThreadNode *T)
{
	for (ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
		visit_ordinary(p);
 } 
//������D�����ָ��գ����Թ���Dָ��B��ǰ��������D->lchild=B,D->ltag=1
//��ʱֱ��PreThread(D->lchild)�ֻص���B 
//�ܽ᣺����������visit_thread����һ���ж���Ч����ʹnow->lchild=pre,������pre=now;
//��ֱ��ִ��PreThread(T->lchild) T�ֻص�֮ǰ��preλ�ã�֮��㲻��ѭ����ȥ;�������Ӽ�pdf�е�B��D��� 

//Ҳ���� ��������� �� �� ��      ��Ȼ���ܳ��ָ������pre��������now����� 
//��pre��now�ĸ����ʱ������now��pre��ǰ��������now->lchildָ��pre����PreThread(now->lchild)�ͻ���ݵ������ 
//���ѭ���� �������Ӽ�pdf�е�B��D��� 		������D��Ϊ�Լ������ӿ��Է��ʵĴ�� 

//�ڶ����жϿ���ʹpre->rchild=now,������pre=now
//ͬ�����ܳ��ָ������pre��������now�����
//���������pre�����û���Һ��ӣ�now��pre������
//�Ὠ��now��pre��ǰ������ now->lchild=pre	ͬʱ����pre��now�ĺ������ pre->rchild=now
//֮������nowû�к���ջ�ռ�ص������pre��ִ��PreThread(pre->rchild)ʱ���ʵ������һ����㣨ʵ����pre�Ѿ�ָ�����ˣ� 
//�������Ӽ�pdf�е�C��F��� 	����F����ָ��Ϊ�գ�F->rchild=F,F->rtag=1;
//֮�����PreThread(F->rchild)��ѭ����ȥ 

ThreadNode *CreateNode(ElemType data)
{
	ThreadNode *p=(ThreadNode *)malloc(sizeof(ThreadNode));
	p->data=data;
	p->ltag=0;			p->rtag=0;
	p->lchild=NULL;		p->rchild=NULL;
	return p;
}
	
void CreateBiTree_simple(ThreadTree &T)
{
	T=CreateNode('A');
	T->lchild=CreateNode('B');		T->rchild=CreateNode('C');
	T->lchild->lchild=CreateNode('D');	T->lchild->rchild=CreateNode('E');	T->rchild->lchild=CreateNode('F');
	T->lchild->lchild->rchild=CreateNode('G');
}
