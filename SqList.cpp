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
	if (ListInsert(L,1,101))		printf("�ѽ�Ԫ��101����λ��1,����ɹ�\n");
	else		printf("λ��1���Ϸ���˳�������,����ʧ��\n"); 
	if (ListInsert(L,2,202))		printf("�ѽ�Ԫ��202����λ��2,����ɹ�\n");
	else		printf("λ��2���Ϸ���˳�������,����ʧ��\n"); 
	if (ListInsert(L,3,303))		printf("�ѽ�Ԫ��303����λ��3,����ɹ�\n");
	else		printf("λ��3���Ϸ���˳�������,����ʧ��\n"); 
		
	PrintList(L);
	
	int e=-1;
	if (ListDelete(L,2,e))
		printf("��ɾ����2��Ԫ��,ɾ��Ԫ��ֵΪ=%d\n",e);
	else
		printf("λ��2���Ϸ�,ɾ��ʧ��\n"); 
		
	PrintList(L);
	
	printf("303��λ��Ϊ%d\n",LocateElem(L,303));
	printf("λ��Ϊ1��Ԫ����%d",GetElem(L,1));
	
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
	//
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

void PrintList(SqList L)
{
	for (int i=0; i<L.length; i++)
		printf("%d\n",L.data[i]);
 } 
