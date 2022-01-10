#include<stdio.h>
#include<string.h>
typedef char ElemType;
#define MaxSize 100
typedef struct
{
	ElemType data[MaxSize];		
	int top;					//Õ»¶¥Ö¸Õë 
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
			Push(S,str[i]);				//É¨Ãèµ½×óÀ¨ºÅ£¬ÈëÕ» 
		else if (str[i]==')' || str[i]==']' || str[i]=='}')
				{	//É¨Ãèµ½ÓÒÀ¨ºÅ£¬ÇÒµ±Ç°Õ»¿Õ£¬ÔòÆ¥ÅäÊ§°Ü 
					if (StackEmpty(S))	return false;		
					
					char topElem;
					Pop(S,topElem);		//Õ»¶¥ÔªËØ³öÕ» 
					if (str[i]==')' && topElem!='(')	return false;
					if (str[i]==']' && topElem!='[')	return false;
					if (str[i]=='}' && topElem!='{')	return false; 
				}
	}
	return StackEmpty(S);		//¼ìË÷ÍêÈ«²¿À¨ºÅºó£¬Õ»¿ÕËµÃ÷Æ¥Åä³É¹¦	
}

void InitStack(SqStack &S)		//³õÊ¼»¯Õ» 
{
	S.top=-1;		
}

void DestroyStack(SqStack &S)
{
	S.top=-1;
}

bool Push(SqStack &S,ElemType x)		//ÈëÕ»²Ù×÷ 
{
	if (StackFull(S))	return false;		//Õ»Âú£¬±¨´í
	S.top=S.top+1;			
	S.data[S.top]=x;					
	return true; 			//<=> S.data[++S.top]=x;
 } 

bool Pop(SqStack &S,ElemType &x)		//³öÕ»²Ù×÷ 
{
	if (StackEmpty(S))	return false;	//Õ»¿Õ£¬±¨´í
	x=S.data[S.top];	
	S.top=S.top-1;			
	return true;			//<=> x=S.data[S.top--]; 
}

bool GetTop(SqStack S,ElemType &x)		//¶ÁÕ»¶¥ÔªËØ 
{
	if (StackEmpty(S))	return false;	//Õ»¿Õ£¬±¨´í
	x=S.data[S.top];			
	return true;
}

bool StackEmpty(SqStack S)		//ÅÐ¶ÏÕ»¿Õ 
{
	if (S.top==-1)	return true;
	else return false;		
}

bool StackFull(SqStack S)		//ÅÐ¶ÏÕ»Âú 
{
	if (S.top==MaxSize-1)	return true;
	else return false;		
}
