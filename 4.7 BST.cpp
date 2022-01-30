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
int BST_Insert(BSTree &T,int k);	//非递归 
int BSTInsert(BSTree &T,int k);		//递归
void Creat_BST(BSTree &T,int str[],int n);	//不断Insert
void PreOrder(BSTree T);
void InOrder(BSTree T);
void visit(BSTNode * p);
 
int main()
{
	int n=8;
	
	BSTree T;
	int str[8]={50,66,60,26,21,30,70,68};		//pdf例1 
	Creat_BST(T,str,n);
	printf("str_PreOrder:");	PreOrder(T);	printf("\n");
	printf("str_InOrder:");		InOrder(T);		printf("\n");
	
	BSTree root;
	int str2[8]={50,26,21,30,66,60,70,68};		//pdf例2
	Creat_BST(root,str2,n);
	printf("str2_PreOrder:");	PreOrder(root);	printf("\n");
	printf("str2_InOrder:");	InOrder(root);	printf("\n");
	
	BSTree zz;
	int str3[8]={26,21,30,50,60,66,68,70};		//pdf例3
	Creat_BST(zz,str3,n);
	printf("str3_PreOrder:");	PreOrder(zz);	printf("\n");
	printf("str3_InOrder:");	InOrder(zz);	printf("\n");
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
 
//在二叉排序树插入关键字为k的新结点（非递归实现）
int BST_Insert(BSTree &T,int k)				
{ 
	if (T==NULL)	//为空时得先把根给建起来，不然永远是对p操作，退出函数即消失 
	{
		T=(BSTNode *)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;			//返回1，插入成功 
	}
	else  
	{
		BSTNode *p=T;
		BSTNode *pre=NULL;		//指向当前访问结点p的父结点
		int tag=-1;
		while (p!=NULL)
		{
			if (k==p->key)	return 0;		//不用插了，已经有了
			else if (k<p->key)	
					{
						pre=p; 
						p=p->lchild;
						tag=0;			//表示p是pre的左孩子 
					}	
				else 
					{
						pre=p; 
						p=p->rchild; 
						tag=1;			//表示p是pre的右孩子 
					}
		}
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;
		p->lchild=p->rchild=NULL;
		if (tag==0)	
			pre->lchild=p;			//pre与p连起来 
		else	
			pre->rchild=p;	 		//pre与p连起来
		return 1;			//返回1，插入成功 
	}
 } 
 
//在二叉排序树插入关键字为k的新结点（递归实现）pdf
int BSTInsert(BSTree &T,int k)				//最坏空间复杂度O(h) 
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
				return	BSTInsert(T->lchild,k);
			 else			//插入到T的右子树 
			 	return	BSTInsert(T->rchild,k); 
 } 

//按照str[]中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T,int str[],int n)
{
	T=NULL;			//初始时T为空树
	int i=0;
	printf("非递归插入BST_Insert\n");		//printf("递归插入BSTInsert\n");
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
