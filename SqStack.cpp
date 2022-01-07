#include<stdio.h>
typedef int ElemType;
#define MaxSize 3				//����ջ��Ԫ�ص������� 
typedef struct
{
	ElemType data[MaxSize];		//��̬������ջ��Ԫ�� 
	int top;					//ջ��ָ�� 
 }SqStack;

void InitStack(SqStack &S);
void DestroyStack(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool GetTop(SqStack S,ElemType &x);
bool StackEmpty(SqStack S);
bool StackFull(SqStack S); 

int main()
{
	SqStack S;	//����һ��˳��ջ(����ռ�) 
	InitStack(S);
	Push(S,101);	Push(S,202);	Push(S,303);
	int x;
	Pop(S,x);	printf("pop is %d\n",x);
	GetTop(S,x);	printf("top is %d\n",x);
	if (StackEmpty(S))	printf("empty\n");	else printf("not empty\n");
	Push(S,404);
	if (StackFull(S))	printf("full\n");	else printf("not full\n");
}

void InitStack(SqStack &S)		//��ʼ��ջ 
{
	S.top=-1;		//��ʼ��ջ��ָ�� 
}

void DestroyStack(SqStack &S)
{
	S.top=-1;
}

bool Push(SqStack &S,ElemType x)		//��ջ���� 
{
	if (S.top==MaxSize-1)	return false;		//ջ��������
	S.top=S.top+1;			//ָ����+1 
	S.data[S.top]=x;		//��Ԫ����ջ				
	return true; 			//<=> S.data[++S.top]=x;
 } 

bool Pop(SqStack &S,ElemType &x)		//��ջ���� 
{
	if (S.top==-1)	return false;	//ջ�գ�����
	x=S.data[S.top];		//ջ��Ԫ���ȳ�ջ 
	S.top=S.top-1;			//ָ���ټ�1 
	return true;			//<=> x=S.data[S.top--]; 
}

bool GetTop(SqStack S,ElemType &x)		//��ջ��Ԫ�� 
{
	if (S.top==-1)	return false;	//ջ�գ�����
	x=S.data[S.top];				//x��¼ջ��Ԫ�� 
	return true;
}

bool StackEmpty(SqStack S)		//�ж�ջ�� 
{
	if (S.top==-1)	return true;	//ջ�� 
	else return false;			//���� 
}

bool StackFull(SqStack S)		//�ж�ջ�� 
{
	if (S.top==MaxSize-1)	return true;	//ջ�� 
	else return false;			//���� 
}
