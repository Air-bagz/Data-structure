//折半查找：
//1.元素升序排列
//2.数组下标从0开始存储
//3.mid=(low+high)/2  是向下取整    

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

int Binary_Search(SeqTable L,ElemType key);
void InitTable(SeqTable &L);

int main()
{
	SeqTable L;
	InitTable(L);
	printf("12元素的下标为:%d\n",Binary_Search(L,12));
	printf("33元素的下标为:%d\n",Binary_Search(L,33));
	return 0;
}

//折半查找
int Binary_Search(SeqTable L,ElemType key)
{
	int low=0,high=L.Len-1,mid;
	while (low<=high)
	{
		mid=(low+high)/2;			//取中间位置 
		if (L.elem[mid]==key)		
			return	mid;			//查找成功则返回元素下标 
		else if (L.elem[mid]>key)
			high=mid-1;				//从前半部分继续查找 
		else 
			low=mid+1;				//从后半部分继续查找 
	}
	return -1;				//查找失败，返回-1 
}

void InitTable(SeqTable &L)
{
	L.elem=(int *)malloc(InitSize*sizeof(int));		
	L.Len=0;
	
	FILE *fp;
	fp=fopen("Z:\\Binary_Search.txt","r");
	fscanf(fp,"%d",&L.Len);	
	for (int i=0; i<L.Len; i++)		
	 	fscanf(fp,"%d",&L.elem[i]);
}	
