#include<stdio.h>
#include<stdlib.h> 

//二叉排序树结点
typedef struct BSTNode
{
	int key;
	struct BSTNode *lchild,*rchild;
 }BSTNode,*BSTree;
 
BSTNode *BST_Search(BSTree T,int key);	//非递归 
BSTNode *BSTSearch(BSTree T,int key);	//递归 
int BST_Insert(BSTree &T,int k);		//递归
void Creat_BST(BSTree &T,int str[],int n);	//不断Insert
void PreOrder(BSTree T);
void InOrder(BSTree T);
void visit(BSTNode * p);
 
int main()
{
	BSTree T;
	int str[8]={50,66,60,26,21,30,70,68};
	int n=8;
	
	Creat_BST(T,str,n);
	printf("PreOrder:");	PreOrder(T);	printf("\n");
	printf("InOrder:");		InOrder(T);		printf("\n");
	
	BSTree root;
	int str2[8]={50,26,21,30,66,60,70,68};
	Creat_BST(root,str,n);
	printf("InOrder__:");		InOrder(root);		printf("\n");
 } 
 
//在二叉排序树中查找值为key的结点（非递归） 
BSTNode *BST_Search(BSTree T,int key)	//最坏空间复杂度O(1) 
{
	while (T!=NULL && key!=T->key)		//若树空或等于根结点值，则结束循环 
	{
		if (key<T->key)	T=T->lchild;	//小于，则在左子树上查找 
		else T=T->rchild;				//大于，则在右子树上查找 
	}
	return  T;		//查找成功，返回结点指针；查找失败返回NULL 
 } 

//在二叉排序树中查找值为key的结点（递归实现）
BSTNode *BSTSearch(BSTree T,int key)		//最坏空间复杂度O(h) 
{
	if (T==NULL)	
		return NULL;		//查找失败
	if (key==T->key)	
		return T;			//查找成功
	else if (key<T->key)	
			return BSTSearch(T->lchild,key);	//在左子树中找
		 else	
		 	return BSTSearch(T->rchild,key);	//在右子树中找  
 } 
 
//在二叉排序树插入关键字为k的新结点（递归实现）
int BST_Insert(BSTree &T,int k)				//最坏空间复杂度O(h) 
{
	if (T==NULL)			//原树为空，新插入的结点为根结点 
	{
		T=(BSTNode *)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;			//返回1，插入成功 
	}
	else if (k==T->key)		//树中存在相同关键字的结点，插入失败	
			return 0;
		else if (k<T->key)	//插入到T的左子树 
				return	BST_Insert(T->lchild,k);
			 else			//插入到T的右子树 
			 	return	BST_Insert(T->rchild,k); 
 } 

//按照str[]中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T,int str[],int n)
{
	T=NULL;			//初始时T为空树
	int i=0;
	while (i<n)
	{
		BST_Insert(T,str[i]);
		i++;
	 } 
 } 

void PreOrder(BSTree T)				//先序遍历 
{
	if (T!=NULL)
	{
		visit(T);				//访问根结点 
		PreOrder(T->lchild);	//递归遍历左子树 
		PreOrder(T->rchild);	//递归遍历右子树 
	}
 } 
 
void InOrder(BSTree T)
{
	if (T!=NULL)
	{
		InOrder(T->lchild);		//递归遍历左子树 
		visit(T);				//访问根结点 
		InOrder(T->rchild);		//递归遍历右子树 
	}
 } 
 
void visit(BSTNode * p)
{
	printf("%d ",p->key);
}
