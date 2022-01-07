#include<stdio.h>
typedef int ElemType;
#define MaxSize 3				//定义栈中元素的最大个数 
typedef struct
{
	ElemType data[MaxSize];		//静态数组存放栈中元素 
	int top;					//栈顶指针 
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
	SqStack S;	//声明一个顺序栈(分配空间) 
	InitStack(S);
	Push(S,101);	Push(S,202);	Push(S,303);
	int x;
	Pop(S,x);	printf("pop is %d\n",x);
	GetTop(S,x);	printf("top is %d\n",x);
	if (StackEmpty(S))	printf("empty\n");	else printf("not empty\n");
	Push(S,404);
	if (StackFull(S))	printf("full\n");	else printf("not full\n");
}

void InitStack(SqStack &S)		//初始化栈 
{
	S.top=-1;		//初始化栈顶指针 
}

void DestroyStack(SqStack &S)
{
	S.top=-1;
}

bool Push(SqStack &S,ElemType x)		//入栈操作 
{
	if (S.top==MaxSize-1)	return false;		//栈满，报错
	S.top=S.top+1;			//指针先+1 
	S.data[S.top]=x;		//新元素入栈				
	return true; 			//<=> S.data[++S.top]=x;
 } 

bool Pop(SqStack &S,ElemType &x)		//出栈操作 
{
	if (S.top==-1)	return false;	//栈空，报错
	x=S.data[S.top];		//栈顶元素先出栈 
	S.top=S.top-1;			//指针再减1 
	return true;			//<=> x=S.data[S.top--]; 
}

bool GetTop(SqStack S,ElemType &x)		//读栈顶元素 
{
	if (S.top==-1)	return false;	//栈空，报错
	x=S.data[S.top];				//x记录栈顶元素 
	return true;
}

bool StackEmpty(SqStack S)		//判断栈空 
{
	if (S.top==-1)	return true;	//栈空 
	else return false;			//不空 
}

bool StackFull(SqStack S)		//判断栈满 
{
	if (S.top==MaxSize-1)	return true;	//栈满 
	else return false;			//不满 
}
