//Complete Binary Tree 1
#include<stdio.h>
#define MaxSize 100

typedef int ElemType;

struct TreeNode
{
	ElemType value;		//结点中的数据元素
	char isEmpty;		//结点是否为空 
 };
struct TreeNode t[MaxSize];		//存储完全二叉树的各个结点
//空出t[0]，保证数组下标和结点编号一致
//初始化所有结点标记为空 

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
	ElemType value;		//结点中的数据元素
	char isEmpty;		//结点是否为空 
 }CoBiTree[MaxSize];

int main()
{
	CoBiTree T;		//Complete Binary Tree
	for (int i=0; i<MaxSize; i++)
		T[i].isEmpty=true;
	printf("%d\n",sizeof(T));
	return 0;
}
