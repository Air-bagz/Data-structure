//Complete Binary Tree 1
#include<stdio.h>
#define MaxSize 100

typedef int ElemType;

struct TreeNode
{
	ElemType value;		//����е�����Ԫ��
	char isEmpty;		//����Ƿ�Ϊ�� 
 };
struct TreeNode t[MaxSize];		//�洢��ȫ�������ĸ������
//�ճ�t[0]����֤�����±�ͽ����һ��
//��ʼ�����н����Ϊ�� 

int main()
{
	for (int i=0; i<MaxSize; i++)
		t[i].isEmpty=true;
	printf("%d\n",sizeof(t));
	return 0;
}

//----------------------------
//Complete Binary Tree 2
#include<stdio.h>
#define MaxSize 100

typedef int ElemType;

typedef struct TreeNode
{
	ElemType value;		//����е�����Ԫ��
	char isEmpty;		//����Ƿ�Ϊ�� 
 }CoBiTree[MaxSize];

int main()
{
	CoBiTree T;		//Complete Binary Tree
	for (int i=0; i<MaxSize; i++)
		T[i].isEmpty=true;
	printf("%d\n",sizeof(T));
	return 0;
}
