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
void InOrder_O_n(ThreadTree T);
void visit_ordinary(ThreadNode * p);
//------------------1.建立二叉树，并递归中序遍历检验------------------------------------------------------------------------
void CreateInThread(ThreadTree &T); 
void InThread(ThreadTree T);
void visit_thread(ThreadNode *q);
//-----------------2.中序线索化二叉树，得到中序线索二叉树-------------------------------------------------------------------- 
ThreadNode *FirstNode(ThreadNode *p);
ThreadNode *NextNode(ThreadNode *p);
void InOrder_O_1(ThreadNode *T);
//-----------------3.利用中序线索二叉树，从中序遍历第一个结点开始不断找中序后继，进而实现中序遍历-------------------------------- 
ThreadNode *LastNode(ThreadNode *p);
ThreadNode *PreNode(ThreadNode *p);
void ReInOrder(ThreadNode *T);
//-----------------4.利用中序线索二叉树，从中序遍历最后一个结点开始不断找中序前驱，进而实现逆向中序遍历------------------------- 

int main()
{			 
	//scanf("%s",xulie);
	ThreadTree T=NULL;
	CreateBiTree(T);		//1.1建立二叉树 
			printf("InOrder_O_n:");
		InOrder_O_n(T);		//1.2递归中序遍历，同时检查二叉树建立成功与否 
			printf("\n");
	CreateInThread(T);		//2.建立中序线索二叉树 
			printf("InOrder_O_1:");
		InOrder_O_1(T);		//3.非递归中序遍历 
			printf("\n");
			printf("ReInOrder_O_1:");
		ReInOrder(T); 		//4.非递归逆向中序遍历	
			printf("\n");
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

void InOrder_O_n(ThreadTree T)		//空间复杂度O(n)		用于验证二叉树建立成功否 
{
	if (T!=NULL)
	{
		InOrder_O_n(T->lchild);		//递归遍历左子树 
		visit_ordinary(T);				//访问根结点 
		InOrder_O_n(T->rchild);		//递归遍历右子树 
	}
 } 

void visit_ordinary(ThreadNode * p)
{
	printf("%c",p->data);
}

void CreateInThread(ThreadTree &T)
{
	pre=NULL;		//pre初始为NULL
	if (T!=NULL)	//非空二叉树才能线索化 
	{
		InThread(T);		//中序线索化二叉树 
		if (pre->rchild==NULL)
			pre->rtag=1;		//处理遍历的最后一个结点 
	 } 
}

//中序遍历二叉树，一边遍历一边线索化 
void InThread(ThreadTree T)
{
	if (T!=NULL)
	{
		InThread(T->lchild);		//中序遍历左子树 
		visit_thread(T);			//访问根结点 
		InThread(T->rchild);		//中序遍历右子树 
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

//找到以p为根的子树中，第一个被中序遍历的结点 
ThreadNode *FirstNode(ThreadNode *p)	
{
	while (p->ltag==0)	p=p->lchild;	//循环找到最左下结点（不一定是叶结点） 
	return p; 
 } 

//在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p)
{
	if (p->rtag==0)	return FirstNode(p->rchild);	//右子树最左下结点 
	else return p->rchild;	//rtag==1直接返回后继线索 
 } 

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法） 空间复杂度O(1)
void InOrder_O_1(ThreadNode *T)
{
	for (ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
		visit_ordinary(p);
 } 
 
//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *p)
{
	while (p->rtag==0) p=p->rchild;
	return p;
 } 
 
//在中序线索二叉树中找到结点p的前驱结点
ThreadNode *PreNode(ThreadNode *p)
{
	if (p->ltag==0)	return LastNode(p->lchild);
	else return p->lchild;		//ltag==1直接返回前驱线索 
 } 
 
//对中序线索二叉树进行逆向中序遍历
void ReInOrder(ThreadNode *T)
{
	for (ThreadNode *p=LastNode(T);p!=NULL;p=PreNode(p))
		visit_ordinary(p);
 } 
