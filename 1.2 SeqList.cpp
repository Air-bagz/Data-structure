#include<stdio.h>
#include<stdlib.h>
#define InitSize 2
typedef struct
{
	int *data;	 		
	int MaxSize;	
	int length;	 	
 }SeqList;

void InitList(SeqList &L);
void IncreaseSize(SeqList &L,int len);
void DestroyList(SeqList &L);

bool ListInsert(SeqList &L, int i, int e);
bool ListDelete(SeqList &L, int i, int &e);

int LocateElem(SeqList L, int e);
int GetElem(SeqList L, int i);

int Length(SeqList L);
void PrintList(SeqList L);
bool Empty(SeqList L);

int main()
{
	SeqList L;
	InitList(L);
	printf("L.length=%d\n",L.length);
	printf("L.MaxSize=%d\n",L.MaxSize);
	
	if (ListInsert(L,1,101))		printf("已将元素101插入位序1,插入成功\n");
	else		printf("位序1不合法或顺序表已满,插入失败\n"); 
	if (ListInsert(L,2,202))		printf("已将元素202插入位序2,插入成功\n");
	else		printf("位序2不合法或顺序表已满,插入失败\n"); 
	if (ListInsert(L,3,303))		printf("已将元素303插入位序3,插入成功\n");
	else		printf("位序3不合法或顺序表已满,插入失败\n"); 
	
	printf("L.length=%d\n",L.length);
	printf("L.MaxSize=%d\n",L.MaxSize);	
	PrintList(L);
	
	int e=-1;
	if (ListDelete(L,2,e))
		printf("已删除第2个元素,删除元素值为=%d\n",e);
	else
		printf("位序2不合法,删除失败\n"); 
		
	PrintList(L);
	
	printf("303的位序为%d\n",LocateElem(L,303));
	printf("位序为1的元素是%d\n",GetElem(L,1));
	
	printf("L.length=%d\n",L.length);
	printf("L.MaxSize=%d\n",L.MaxSize);
	
	DestroyList(L);
	printf("L.length=%d\n",L.length);
	printf("L.MaxSize=%d\n",L.MaxSize);
	
	return 0;
}

void InitList(SeqList &L)
{
	L.data=(int *)malloc(InitSize*sizeof(int));		
	L.length=0;
	L.MaxSize=InitSize;;
		 }	

void IncreaseSize(SeqList &L,int len)
{
	int *p=L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));	
	for (int i=0; i<L.length; i++)
		L.data[i]=p[i];		
	L.MaxSize=L.MaxSize+len;	
	free(p);		
}

void DestroyList(SeqList &L)
{
	free(L.data);
	L.length=0;
	L.MaxSize=0;
}

bool ListInsert(SeqList &L, int i, int e)	 
{
	if (i<1||i>L.length+1)		
		return false;
	if (L.length>=L.MaxSize)		
		//return false;
		IncreaseSize(L,10);

	for (int j=L.length; j>=i; j--)		
		L.data[j]=L.data[j-1];		
	L.data[i-1]=e;						
	L.length++;
	
	return true; 
}

 
bool ListDelete(SeqList &L, int i, int &e)
{
	if (i<1||i>L.length)			
		return false;
	
	e=L.data[i-1];							
	for (int j=i; j<L.length; j++)		
		L.data[j-1]=L.data[j];		
	L.length--;
	return true;
}

int LocateElem(SeqList L, int e)
{
	for (int i=0; i<L.length; i++)
		if (L.data[i]==e)		
			return i+1;		
	return 0;			
}

int GetElem(SeqList L, int i)
{
	return L.data[i-1];					
}

int Length(SeqList L)
{
	return(L.length);
}

void PrintList(SeqList L)
{
	for (int i=0; i<L.length; i++)
		printf("%d\n",L.data[i]);
 } 
 
bool Empty(SeqList L)
{
	if (L.length==0)	return true;
	else return false; 
}
