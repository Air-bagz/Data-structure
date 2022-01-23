#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
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
void PreOrder_O_n(ThreadTree T);
void visit_ordinary(ThreadNode * p);
//--------------------1.建立二叉树，并递归先序遍历检验----------------------------------------------------------
void CreatePreThread(ThreadTree &T);
void PreThread(ThreadTree T);
void visit_thread(ThreadNode *now);
//--------------------2.先序线索化二叉树，得到先序线索二叉树-----------------------------------------------------
ThreadNode *FirstNode(ThreadNode *p);
ThreadNode *NextNode(ThreadNode *p);
void PreOrder_O_1(ThreadNode *T);
//--------------------3.利用先序线索二叉树，从先序遍历第一个结点开始不断找先序后继，进而实现先序遍历-------------------------- 
void Print(ThreadNode * x);	//测试 
//----------------------下面是另一种手动建立二叉树的方法（原始简单）---------------------------
ThreadNode *CreateNode(ElemType data);	
void CreateBiTree_simple(ThreadTree &T); 

int main()
{
	ThreadTree T=NULL;
	CreateBiTree(T);		//1.1建立二叉树
			printf("PreOrder_O_n:");
		PreOrder_O_n(T);	//1.2递归先序遍历，同时检查二叉树建立成功与否 
			printf("\n");
	CreatePreThread(T);		//2.建立先序线索二叉树 
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
		PreOrder_O_1(T);	//3.非递归先序遍历 
			printf("\n");
	
	ThreadTree root;
	CreateBiTree_simple(root);	//另一种方法建立二叉树 
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

void PreOrder_O_n(ThreadTree T)			//先序遍历 	空间复杂度O(n)	用于验证二叉树建立成功否 
{
	if (T!=NULL)
	{
		visit_ordinary(T);				//访问根结点 
		PreOrder_O_n(T->lchild);	//递归遍历左子树 
		PreOrder_O_n(T->rchild);	//递归遍历右子树 
	}
 } 

void visit_ordinary(ThreadNode * p)
{
	printf("%c",p->data);
}

void CreatePreThread(ThreadTree &T)
{
	pre=NULL;		//pre初始为NULL
	if (T!=NULL)	//非空二叉树才能线索化 
	{
		PreThread(T);		//先序线索化二叉树 
		if (pre->rchild==NULL)
			pre->rtag=1;		//处理遍历的最后一个结点 
	 } 
}

//先序遍历二叉树，一边遍历一边线索化 
void PreThread(ThreadTree T)
{
	if (T!=NULL)
	{
		visit_thread(T);					//先访问根结点 
		if (T->ltag==0)	//lchild指向左孩子，不是前驱线索 ；防止出现转圈循环 
			PreThread(T->lchild);		//先序遍历左子树 
		if (T->rtag==0)  PreThread(T->rchild);		//先序遍历右子树 	修改之前PreThread(T->rchild);
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
//找到以p为根的子树中，第一个被先序遍历的结点 
ThreadNode *FirstNode(ThreadNode *p)	
{
	return p; 
 } 

//在先序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p)
{
	if (p->rtag==0)	
		{
			if (p->lchild!=NULL && p->ltag==0)	return FirstNode(p->lchild);	//若有左孩子(不能是假的左孩子），由于p的左孩子即是左子树先序遍历第一个，所以p的先序后继为p的左孩子 
			else 	return FirstNode(p->rchild); 	//若无左孩子，由于p的右孩子是右子树先序遍历第一个，所以p的先序后继为p的右孩子
		 } 
	else return p->rchild;	//rtag==1直接返回后继线索 
 } 
 
//对先序线索二叉树进行先序遍历（利用线索实现的非递归算法） 空间复杂度O(1)
void PreOrder_O_1(ThreadNode *T)
{
	for (ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
		visit_ordinary(p);
 } 
//例子中D结点左指针空，所以构建D指向B的前驱线索，D->lchild=B,D->ltag=1
//此时直接PreThread(D->lchild)又回到了B 
//总结：先序线索化visit_thread若第一个判断生效，则使now->lchild=pre,结束后pre=now;
//若直接执行PreThread(T->lchild) T又回到之前的pre位置，之后便不断循环下去;具体例子见pdf中的B、D结点 

//也就是 先序遍历是 根 左 右      当然可能出现父结点是pre，孩子是now的情况 
//当pre是now的父结点时，增加now到pre的前驱线索，now->lchild指向pre，再PreThread(now->lchild)就会回溯到父结点 
//造成循环， 具体例子见pdf中的B、D结点 		不能让D以为自己有左孩子可以访问的错觉 

//第二个判断可能使pre->rchild=now,结束后pre=now
//同样可能出现父结点是pre，孩子是now的情况
//特殊情况是pre父结点没有右孩子，now是pre的左孩子
//会建立now到pre的前驱线索 now->lchild=pre	同时建立pre到now的后继线索 pre->rchild=now
//之后由于now没有孩子栈空间回到父结点pre，执行PreThread(pre->rchild)时访问的是最后一个结点（实际上pre已经指向它了） 
//具体例子见pdf中的C、F结点 	由于F左右指针为空，F->rchild=F,F->rtag=1;
//之后访问PreThread(F->rchild)会循环下去 

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
