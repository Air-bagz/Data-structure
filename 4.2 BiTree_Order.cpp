#include<stdio.h>
#include<stdlib.h> 
//二叉树的结点（链式存储）
typedef char ElemType;

typedef struct BiTNode
{
	ElemType data;						//数据域 
	struct BiTNode *lchild,*rchild;		//左、右孩子指针 
 }BiTNode,*BiTree;

void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
int treeDepth(BiTree T);
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
	
	printf("PreOrder:\n");	PreOrder(root);		printf("\n");
	printf("InOrder:\n");	InOrder(root);		printf("\n");
	printf("PostOrder:\n");	PostOrder(root);	printf("\n");
	
	printf("depth:%d\n",treeDepth(root));
}

void PreOrder(BiTree T)				//先序遍历 
{
	if (T!=NULL)
	{
		visit(T);				//访问根结点 
		PreOrder(T->lchild);	//递归遍历左子树 
		PreOrder(T->rchild);	//递归遍历右子树 
	}
 } 

void InOrder(BiTree T)
{
	if (T!=NULL)
	{
		InOrder(T->lchild);		//递归遍历左子树 
		visit(T);				//访问根结点 
		InOrder(T->rchild);		//递归遍历右子树 
	}
 } 
 
void PostOrder(BiTree T)
{
	if (T!=NULL)
	{
		PostOrder(T->lchild);	//递归遍历左子树
		PostOrder(T->rchild);	//递归遍历右子树
		visit(T);				//访问根结点 
	}
 } 

int treeDepth(BiTree T)		//后序遍历的变种 
{
	if (T==NULL)
		return 0;
	else 
	{
		int l=treeDepth(T->lchild);
		int r=treeDepth(T->rchild);
		return l>r? l+1 : r+1; 		//树的深度=Max(左子树深度，右子树深度)+1
	}
 } 
 
void visit(BiTNode * p)
{
	printf("%c\n",p->data);
}

//---------三叉链表-------------
//根据实际需求决定要不要加父结点指针 
/*
typedef struct BiTNode
{
	ElemType data;						//数据域 
	struct BiTNode *lchild,*rchild;		//左、右孩子指针 
	struct BiTNode *parent;				//父结点指针 
 }BiTNode,*BiTree;
 */
