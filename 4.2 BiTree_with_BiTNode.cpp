#include<stdlib.h> 
//二叉树的结点（链式存储）
struct ElemType
{
	int value;
};

typedef struct BiTNode
{
	ElemType data;						//数据域 
	struct BiTNode *lchild,*rchild;		//左、右孩子指针 
 }BiTNode,*BiTree;

int main()
{
	//定义一棵空树 
	BiTree root=NULL;
	//插入根结点
	root=(BiTNode *)malloc(sizeof(BiTNode));
	root->data={1};
	root->lchild=NULL;
	root->rchild=NULL;
	//插入新结点
	BiTNode *p=(BiTNode *)malloc(sizeof(BiTNode));
	p->data={2};
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;		//作为根结点的左孩子 
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
