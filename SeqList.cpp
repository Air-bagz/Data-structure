#include<stdio.h>
#include<stdlib.h>
#define InitSize 10		
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
	
	if (ListInsert(L,1,101))		printf("�ѽ�Ԫ��101����λ��1,����ɹ�\n");
	else		printf("λ��1���Ϸ���˳�������,����ʧ��\n"); 
	if (ListInsert(L,2,202))		printf("�ѽ�Ԫ��202����λ��2,����ɹ�\n");
	else		printf("λ��2���Ϸ���˳�������,����ʧ��\n"); 
	if (ListInsert(L,3,303))		printf("�ѽ�Ԫ��303����λ��3,����ɹ�\n");
	else		printf("λ��3���Ϸ���˳�������,����ʧ��\n"); 
	
	IncreaseSize(L,5);	
	printf("L.length=%d\n",L.length);
	printf("L.MaxSize=%d\n",L.MaxSize);	
	PrintList(L);
	
	int e=-1;
	if (ListDelete(L,2,e))
		printf("��ɾ����2��Ԫ��,ɾ��Ԫ��ֵΪ=%d\n",e);
	else
		printf("λ��2���Ϸ�,ɾ��ʧ��\n"); 
		
	PrintList(L);
	
	printf("303��λ��Ϊ%d\n",LocateElem(L,303));
	printf("λ��Ϊ1��Ԫ����%d\n",GetElem(L,1));
	
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
		return false;

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

void PrintList(SeqList L)
{
	for (int i=0; i<L.length; i++)
		printf("%d\n",L.data[i]);
 } 
