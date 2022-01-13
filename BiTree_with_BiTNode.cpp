#include<stdlib.h> 
//�������Ľ�㣨��ʽ�洢��
struct ElemType
{
	int value;
};

typedef struct BiTNode
{
	ElemType data;						//������ 
	struct BiTNode *lchild,*rchild;		//���Һ���ָ�� 
 }BiTNode,*BiTree;

int main()
{
	//����һ�ÿ��� 
	BiTree root=NULL;
	//��������
	root=(BiTNode *)malloc(sizeof(BiTNode));
	root->data={1};
	root->lchild=NULL;
	root->rchild=NULL;
	//�����½��
	BiTNode *p=(BiTNode *)malloc(sizeof(BiTNode));
	p->data={2};
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;		//��Ϊ���������� 
}

void PreOrder(BiTree T)				//������� 
{
	if (T!=NULL)
	{
		visit(T);				//���ʸ���� 
		PreOrder(T->lchild);	//�ݹ���������� 
		PreOrder(T->rchild);	//�ݹ���������� 
	}
 } 

void InOrder(BiTree T)
{
	if (T!=NULL)
	{
		InOrder(T->lchild);		//�ݹ���������� 
		visit(T);				//���ʸ���� 
		InOrder(T->rchild);		//�ݹ���������� 
	}
 } 
 
void PostOrder(BiTree T)
{
	if (T!=NULL)
	{
		PostOrder(T->lchild);	//�ݹ����������
		PostOrder(T->rchild);	//�ݹ����������
		visit(T);				//���ʸ���� 
	}
 } 

int treeDepth(BiTree T)		//��������ı��� 
{
	if (T==NULL)
		return 0;
	else 
	{
		int l=treeDepth(T->lchild);
		int r=treeDepth(T->rchild);
		return l>r? l+1 : r+1; 		//�������=Max(��������ȣ����������)+1
	}
 } 
//---------��������-------------
//����ʵ���������Ҫ��Ҫ�Ӹ����ָ�� 
/*
typedef struct BiTNode
{
	ElemType data;						//������ 
	struct BiTNode *lchild,*rchild;		//���Һ���ָ�� 
	struct BiTNode *parent;				//�����ָ�� 
 }BiTNode,*BiTree;
 */
