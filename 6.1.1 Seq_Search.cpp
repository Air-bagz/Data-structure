#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define InitSize 20
typedef int ElemType;

typedef struct			//查找表的数据结构(顺序表) 
{
	ElemType *elem;		//动态数组基址 
	int Len;			//表的长度 
}SeqTable;

int Seq_Search(SeqTable ST,ElemType key);
void InitTable(SeqTable &ST);

int main()
{
	SeqTable ST;
	InitTable(ST);
	printf("66元素的下标为:%d\n",Seq_Search(ST,66));
	printf("41元素的下标为:%d\n",Seq_Search(ST,41));
	return 0;
}

//顺序查找
int Seq_Search(SeqTable ST,ElemType key)
{
	int i=0;
	while (i<ST.Len && ST.elem[i]!=key)
		i++;
	//查找成功，则返回元素下标；查找失败，则返回-1
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
