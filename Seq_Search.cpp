#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define InitSize 20
typedef int ElemType;

typedef struct			//���ұ�����ݽṹ(˳���) 
{
	ElemType *elem;		//��̬�����ַ 
	int Len;			//��ĳ��� 
}SeqTable;

int Seq_Search(SeqTable ST,ElemType key);
void InitTable(SeqTable &ST);

int main()
{
	SeqTable ST;
	InitTable(ST);
	printf("66Ԫ�ص��±�Ϊ:%d\n",Seq_Search(ST,66));
	printf("41Ԫ�ص��±�Ϊ:%d\n",Seq_Search(ST,41));
	return 0;
}

//˳�����
int Seq_Search(SeqTable ST,ElemType key)
{
	int i=0;
	while (i<ST.Len && ST.elem[i]!=key)
		i++;
	//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�-1
	return i==ST.Len? -1 : i; 
 } 
 
void InitTable(SeqTable &ST)
{
	ST.elem=(int *)malloc(InitSize*sizeof(int));		
	ST.Len=0;
	
	FILE *fp;
	fp=fopen("Z:\\Seq_Search.txt","r");
	fscanf(fp,"%d",&ST.Len);	
	for (int i=0; i<ST.Len; i++)		
	 	fscanf(fp,"%d",&ST.elem[i]);
}	
