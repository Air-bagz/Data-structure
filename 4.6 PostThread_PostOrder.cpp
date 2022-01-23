#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
//线索二叉树结点
typedef char ElemType;

typedef struct ThreadNode
{
	ElemType data;							//数据域 
	struct ThreadNode *lchild,*rchild;		//左、右孩子指针 
	int ltag,rtag;							//左右线索标志 
 }ThreadNode,*ThreadTree; 
 
ThreadNode *pre=NULL;		//全局变量pre，指向当前访问结点的前驱 
char xulie[MaxSize]={"ABD#G##E##CF###"};	//PPT例；必须全局变量，否则需要每次传入 
int num=0;				//必须全局变量，否则需要每次传入 

void CreateBiTree(ThreadTree &T);
void PostOrder_O_n(ThreadTree T);
void visit_ordinary(ThreadNode * p);
//------------------1.建立二叉树，并递归后序遍历检验------------------------------------------------------------------------
void CreatePostThread(ThreadTree &T); 
void PostThread(ThreadTree T);
void visit_thread(ThreadNode *q);
//-----------------2.后序线索化二叉树，得到后序线索二叉树-------------------------------------------------------------------- 


int main()
{			 
	//scanf("%s",xulie);
	ThreadTree T=NULL;
	CreateBiTree(T);		//1.1建立二叉树 
			printf("PostOrder_O_n:");
		PostOrder_O_n(T);		//1.2递归后序遍历，同时检查二叉树建立成功与否 
			printf("\n");
	CreatePostThread(T);		//2.建立后序线索二叉树 
			printf("PostOrder_O_1:");
//		PostOrder_O_1(T);		//3.非递归后序遍历 
//			printf("\n");
	return 0;
}

void CreateBiTree(ThreadTree &T)	//读入先序遍历序列来建立二叉树，空孩子用#表示 
{
	char ch;
	ch=xulie[num++]; //离线操作
	if (ch=='#') T=NULL;
	else
	{
		T=(ThreadNode *)malloc(sizeof(ThreadNode));
		T->data=ch; //生成根节点
		T->ltag=0;	T->rtag=0;	//必须初始化，否则输出不对 
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
}

void PostOrder_O_n(ThreadTree T)		//空间复杂度O(n)		用于验证二叉树建立成功否 
{
	if (T!=NULL)
	{
		PostOrder_O_n(T->lchild);		//递归遍历左子树 
		PostOrder_O_n(T->rchild);		//递归遍历右子树 
		visit_ordinary(T);				//访问根结点 
	}
 } 

void visit_ordinary(ThreadNode * p)
{
	printf("%c",p->data);
}

void CreatePostThread(ThreadTree &T)
{
	pre=NULL;		//pre初始为NULL
	if (T!=NULL)	//非空二叉树才能线索化 
	{
		PostThread(T);		//后序线索化二叉树 
		if (pre->rchild==NULL)
			pre->rtag=1;		//处理遍历的最后一个结点 
	 } 
}

//后序遍历二叉树，一边遍历一边线索化 
void PostThread(ThreadTree T)
{
	if (T!=NULL)
	{
		PostThread(T->lchild);		//后序遍历左子树  
		PostThread(T->rchild);		//后序遍历右子树 
		visit_thread(T);					//访问根结点
	}
 } 
 
void visit_thread(ThreadNode *now)
{
	if (now->lchild==NULL)			//左子树为空，建立前驱线索  pre<--now
	{
		now->lchild=pre;
		now->ltag=1;
	}
	if (pre!=NULL && pre->rchild==NULL)
	{
		pre->rchild=now;			//建立前驱结点的后继线索  pre---->now
		pre->rtag=1;
	}
	pre=now;
}
