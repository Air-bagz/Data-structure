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
	ST.elem[0]=key;		//guard
	int i=ST.Len;
	while (ST.elem[i]!=key)		//�����ж��Ƿ�Խ�� 
		i--;
	return i; 		//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�0
 } 
 
void InitTable(SeqTable &ST)
{
	ST.elem=(int *)malloc(InitSize*sizeof(int));		
	ST.Len=0;
	
	FILE *fp;
	fp=fopen("Z:\\Seq_Search.txt","r");
	fscanf(fp,"%d",&ST.Len);	
	for (int i=1; i<=ST.Len; i++)		//������±�1��ʼ��		
	 	fscanf(fp,"%d",&ST.elem[i]);
}	
