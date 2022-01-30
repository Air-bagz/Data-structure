#include<stdio.h>
#include<stdlib.h> 

//�������������
typedef struct BSTNode
{
	int key;
	struct BSTNode *lchild,*rchild;
 }BSTNode,*BSTree;
 
BSTNode *BST_Search(BSTree T,int key);	//�ǵݹ� 
BSTNode *BSTSearch(BSTree T,int key);	//�ݹ� 
int BST_Insert(BSTree &T,int k);	//�ǵݹ� 
int BSTInsert(BSTree &T,int k);		//�ݹ�
void Creat_BST(BSTree &T,int str[],int n);	//����Insert
void PreOrder(BSTree T);
void InOrder(BSTree T);
void visit(BSTNode * p);
 
int main()
{
	int n=8;
	
	BSTree T;
	int str[8]={50,66,60,26,21,30,70,68};		//pdf��1 
	Creat_BST(T,str,n);
	printf("str_PreOrder:");	PreOrder(T);	printf("\n");
	printf("str_InOrder:");		InOrder(T);		printf("\n");
	
	BSTree root;
	int str2[8]={50,26,21,30,66,60,70,68};		//pdf��2
	Creat_BST(root,str2,n);
	printf("str2_PreOrder:");	PreOrder(root);	printf("\n");
	printf("str2_InOrder:");	InOrder(root);	printf("\n");
	
	BSTree zz;
	int str3[8]={26,21,30,50,60,66,68,70};		//pdf��3
	Creat_BST(zz,str3,n);
	printf("str3_PreOrder:");	PreOrder(zz);	printf("\n");
	printf("str3_InOrder:");	InOrder(zz);	printf("\n");
 } 
 
//�ڶ����������в���ֵΪkey�Ľ�㣨�ǵݹ飩 
BSTNode *BST_Search(BSTree T,int key)	//��ռ临�Ӷ�O(1) 
{
	while (T!=NULL && key!=T->key)		//�����ջ���ڸ����ֵ�������ѭ�� 
	{
		if (key<T->key)	T=T->lchild;	//С�ڣ������������ϲ��� 
		else T=T->rchild;				//���ڣ������������ϲ��� 
	}
	return  T;		//���ҳɹ������ؽ��ָ�룻����ʧ�ܷ���NULL 
 } 

//�ڶ����������в���ֵΪkey�Ľ�㣨�ݹ�ʵ�֣�
BSTNode *BSTSearch(BSTree T,int key)		//��ռ临�Ӷ�O(h) 
{
	if (T==NULL)	
		return NULL;		//����ʧ��
	if (key==T->key)	
		return T;			//���ҳɹ�
	else if (key<T->key)	
			return BSTSearch(T->lchild,key);	//������������
		 else	
		 	return BSTSearch(T->rchild,key);	//������������  
 } 
 
//�ڶ�������������ؼ���Ϊk���½�㣨�ǵݹ�ʵ�֣�
int BST_Insert(BSTree &T,int k)				
{ 
	if (T==NULL)	//Ϊ��ʱ���ȰѸ�������������Ȼ��Զ�Ƕ�p�������˳���������ʧ 
	{
		T=(BSTNode *)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;			//����1������ɹ� 
	}
	else  
	{
		BSTNode *p=T;
		BSTNode *pre=NULL;		//ָ��ǰ���ʽ��p�ĸ����
		int tag=-1;
		while (p!=NULL)
		{
			if (k==p->key)	return 0;		//���ò��ˣ��Ѿ�����
			else if (k<p->key)	
					{
						pre=p; 
						p=p->lchild;
						tag=0;			//��ʾp��pre������ 
					}	
				else 
					{
						pre=p; 
						p=p->rchild; 
						tag=1;			//��ʾp��pre���Һ��� 
					}
		}
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;
		p->lchild=p->rchild=NULL;
		if (tag==0)	
			pre->lchild=p;			//pre��p������ 
		else	
			pre->rchild=p;	 		//pre��p������
		return 1;			//����1������ɹ� 
	}
 } 
 
//�ڶ�������������ؼ���Ϊk���½�㣨�ݹ�ʵ�֣�pdf
int BSTInsert(BSTree &T,int k)				//��ռ临�Ӷ�O(h) 
{
	if (T==NULL)			//ԭ��Ϊ�գ��²���Ľ��Ϊ����� 
	{
		T=(BSTNode *)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;			//����1������ɹ� 
	}
	else if (k==T->key)		//���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��	
			return 0;
		else if (k<T->key)	//���뵽T�������� 
				return	BSTInsert(T->lchild,k);
			 else			//���뵽T�������� 
			 	return	BSTInsert(T->rchild,k); 
 } 

//����str[]�еĹؼ������н�������������
void Creat_BST(BSTree &T,int str[],int n)
{
	T=NULL;			//��ʼʱTΪ����
	int i=0;
	printf("�ǵݹ����BST_Insert\n");		//printf("�ݹ����BSTInsert\n");
	while (i<n)
	{
		BST_Insert(T,str[i]);
		i++;
	 } 
 } 

void PreOrder(BSTree T)				//������� 
{
	if (T!=NULL)
	{
		visit(T);				//���ʸ���� 
		PreOrder(T->lchild);	//�ݹ���������� 
		PreOrder(T->rchild);	//�ݹ���������� 
	}
 } 
 
void InOrder(BSTree T)
{
	if (T!=NULL)
	{
		InOrder(T->lchild);		//�ݹ���������� 
		visit(T);				//���ʸ���� 
		InOrder(T->rchild);		//�ݹ���������� 
	}
 } 
 
void visit(BSTNode * p)
{
	printf("%d ",p->key);
}
