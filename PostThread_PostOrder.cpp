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
void PostOrder_O_n(ThreadTree T);
void visit_ordinary(ThreadNode * p);
//------------------1.���������������ݹ�����������------------------------------------------------------------------------
void CreatePostThread(ThreadTree &T); 
void PostThread(ThreadTree T);
void visit_thread(ThreadNode *q);
//-----------------2.�������������������õ���������������-------------------------------------------------------------------- 


int main()
{			 
	//scanf("%s",xulie);
	ThreadTree T=NULL;
	CreateBiTree(T);		//1.1���������� 
			printf("PostOrder_O_n:");
		PostOrder_O_n(T);		//1.2�ݹ���������ͬʱ�������������ɹ���� 
			printf("\n");
	CreatePostThread(T);		//2.������������������ 
			printf("PostOrder_O_1:");
//		PostOrder_O_1(T);		//3.�ǵݹ������� 
//			printf("\n");
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

void PostOrder_O_n(ThreadTree T)		//�ռ临�Ӷ�O(n)		������֤�����������ɹ��� 
{
	if (T!=NULL)
	{
		PostOrder_O_n(T->lchild);		//�ݹ���������� 
		PostOrder_O_n(T->rchild);		//�ݹ���������� 
		visit_ordinary(T);				//���ʸ���� 
	}
 } 

void visit_ordinary(ThreadNode * p)
{
	printf("%c",p->data);
}

void CreatePostThread(ThreadTree &T)
{
	pre=NULL;		//pre��ʼΪNULL
	if (T!=NULL)	//�ǿն��������������� 
	{
		PostThread(T);		//���������������� 
		if (pre->rchild==NULL)
			pre->rtag=1;		//������������һ����� 
	 } 
}

//���������������һ�߱���һ�������� 
void PostThread(ThreadTree T)
{
	if (T!=NULL)
	{
		PostThread(T->lchild);		//�������������  
		PostThread(T->rchild);		//������������� 
		visit_thread(T);					//���ʸ����
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
