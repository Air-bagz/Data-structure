#include<stdio.h>
#include<string.h>
typedef char ElemType;
#define MaxSize 100
typedef struct
{
	ElemType data[MaxSize];		
	int top;					//栈顶指针 
 }SqStack;
 
void InitStack(SqStack &S);
void DestroyStack(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool GetTop(SqStack S,ElemType &x);
bool StackEmpty(SqStack S);
bool StackFull(SqStack S); 
bool bracketCheck(char str[],int length);

int main()
{
	char str[MaxSize];
	//scanf("%s",str);
	strcpy(str,"123(sadas[46d78as{f4a6f4}Fafw]fdrghtht)h46e(wqfewr)[[]]grrger{QWFewgrebhtny}");
	if ( bracketCheck(str,strlen(str)) )	printf("check success!");
	else printf("check failed");
}

bool bracketCheck(char str[],int length)
{
	SqStack S;	
	InitStack(S);
	for (int i=0;i<length;i++)
	{
		if (str[i]=='(' || str[i]=='[' || str[i]=='{')
			Push(S,str[i]);				//扫描到左括号，入栈 
		else if (str[i]==')' || str[i]==']' || str[i]=='}')
				{	//扫描到右括号，且当前栈空，则匹配失败 
					if (StackEmpty(S))	return false;		
					
					char topElem;
					Pop(S,topElem);		//栈顶元素出栈 
					if (str[i]==')' && topElem!='(')	return false;
					if (str[i]==']' && topElem!='[')	return false;
					if (str[i]=='}' && topElem!='{')	return false; 
				}
	}
	return StackEmpty(S);		//检索完全部括号后，栈空说明匹配成功	
}

void InitStack(SqStack &S)		//初始化栈 
{
	S.top=-1;		
}

void DestroyStack(SqStack &S)
{
	S.top=-1;
}

bool Push(SqStack &S,ElemType x)		//入栈操作 
{
	if (StackFull(S))	return false;		//栈满，报错
	S.top=S.top+1;			
	S.data[S.top]=x;					
	return true; 			//<=> S.data[++S.top]=x;
 } 

bool Pop(SqStack &S,ElemType &x)		//出栈操作 
{
	if (StackEmpty(S))	return false;	//栈空，报错
	x=S.data[S.top];	
	S.top=S.top-1;			
	return true;			//<=> x=S.data[S.top--]; 
}

bool GetTop(SqStack S,ElemType &x)		//读栈顶元素 
{
	if (StackEmpty(S))	return false;	//栈空，报错
	x=S.data[S.top];			
	return true;
}

bool StackEmpty(SqStack S)		//判断栈空 
{
	if (S.top==-1)	return true;
	else return false;		
}

bool StackFull(SqStack S)		//判断栈满 
{
	if (S.top==MaxSize-1)	return true;
	else return false;		
}
