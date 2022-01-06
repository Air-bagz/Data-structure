#include<stdio.h>
#define MaxSize 10		
typedef struct
{
	int data[MaxSize];	   //MaxSize*sizeof(ElemType) 
	int length;	 
 }SqList;		

void InitList(SqList &L);
void DestroyList(SqList &L);

bool ListInsert(SqList &L, int i, int e);
bool ListDelete(SqList &L, int i, int &e);

int LocateElem(SqList L, int e);
int GetElem(SqList L, int i);

int Length(SqList L);
void PrintList(SqList L);
bool Empty(SqList L);

int main()
{
	SqList L;
	InitList(L);
	if (ListInsert(L,1,101))		printf("已将元素101插入位序1,插入成功\n");
	else		printf("位序1不合法或顺序表已满,插入失败\n"); 
	if (ListInsert(L,2,202))		printf("已将元素202插入位序2,插入成功\n");
	else		printf("位序2不合法或顺序表已满,插入失败\n"); 
	if (ListInsert(L,3,303))		printf("已将元素303插入位序3,插入成功\n");
	else		printf("位序3不合法或顺序表已满,插入失败\n"); 
		
	PrintList(L);
	
	int e=-1;
	if (ListDelete(L,2,e))
		printf("已删除第2个元素,删除元素值为=%d\n",e);
	else
		printf("位序2不合法,删除失败\n"); 
		
	PrintList(L);
	
	printf("303的位序为%d\n",LocateElem(L,303));
	printf("位序为1的元素是%d",GetElem(L,1));
	
	return 0;
}

void InitList(SqList &L)
{
//	for (int i=0; i<MaxSize; i++)
//		L.data[i]=0;
	L.length=0;		
}

void DestroyList(SqList &L)
{
	L.length=0;
	//系统自动回收空间 
}

bool ListInsert(SqList &L, int i, int e)	 
{
	if (i<1||i>L.length+1)		
		return false;
	if (L.length>=MaxSize)		
		return false;

	for (int j=L.length; j>=i; j--)		
		L.data[j]=L.data[j-1];		
	L.data[i-1]=e;						
	L.length++;
	
	return true; 
}

 
bool ListDelete(SqList &L, int i, int &e)
{
	if (i<1||i>L.length)			
		return false;
	
	e=L.data[i-1];							
	for (int j=i; j<L.length; j++)		
		L.data[j-1]=L.data[j];		
	L.length--;
	return true;
}

int LocateElem(SqList L, int e)
{
	for (int i=0; i<L.length; i++)
		if (L.data[i]==e)		
			return i+1;		
	return 0;			
}

int GetElem(SqList L, int i)
{
	return L.data[i-1];					
}

int Length(SqList L)
{
	return(L.length);
}

void PrintList(SqList L)
{
	for (int i=0; i<L.length; i++)
		printf("%d\n",L.data[i]);
 } 
 
bool Empty(SqList L)
{
	if (L.length==0)	return true;
	else return false; 
}
