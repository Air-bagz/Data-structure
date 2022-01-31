//分块查找：块内无序、块间有序
//1.索引表 顺序查找  or  折半查找
//2.块内   顺序查找 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;

//索引表 
typedef struct
{
	ElemType maxValue;
	int low,high;
 }IndexNode,IndexList[100];
 
typedef struct
{
	IndexList Index;			//IndexNode Index[100];		索引表 
	int Index_len;
	ElemType List[100];		//顺序表存储实际元素 
	int List_len;
}BSList;		//分块查找表 

void InitList(BSList &L);
void show(BSList L);
int Seq_Search_Index(BSList L,ElemType key); 
int Seq_Search_Block(BSList L,ElemType key,int point);
void Block_Search(BSList L,ElemType key);
//----------------------------------------------------------------------------------------
int Binary_Search_Index(BSList L,ElemType key); 
void Block_Search2(BSList L,ElemType key);

int main()
{
	BSList L;
	InitList(L);	//读入索引表和顺序表 
	show(L);
//	int key;	//查找目标 
	Block_Search(L,22);	//pdf例子 
	Block_Search(L,29);	//pdf例子 
	Block_Search(L,50);	//测试最大的一个
	Block_Search(L,51); //测试超出最大
	Block_Search(L,7);	//测试最小 
	Block_Search(L,6);	//测试小于最小 
//------------------------------------------------------------------ 
printf("------------------------------下面是折半查找索引表---------------------------\n");
	Block_Search2(L,30);//pdf例子	
	Block_Search2(L,19);//pdf例子
	Block_Search2(L,54);//pdf例子
	return 0; 
}

void InitList(BSList &L)
{
	FILE *fp;
	fp=fopen("Z:\\Block_Search.txt","r");
	fscanf(fp,"%d",&L.Index_len);	
	for (int i=0; i<L.Index_len; i++)		
	 	fscanf(fp,"%d %d %d",&L.Index[i].maxValue,&L.Index[i].low,&L.Index[i].high);
	fscanf(fp,"%d",&L.List_len);
	for (int i=0; i<L.List_len; i++)
		fscanf(fp,"%d",&L.List[i]);
/*	for (int i=0; i<5; i++)		
	 	printf("%d %d %d\n",L.Index[i].maxValue,L.Index[i].low,L.Index[i].high);
	for (int i=0; i<14; i++)
		printf("%d ",L.List[i]);	*/
}

void show(BSList L)
{
	for (int i=0; i<L.List_len; i++)	
		printf("L[%d]\t",i);
	printf("\n");
	for (int i=0; i<L.List_len; i++)	
		printf("%d\t",L.List[i]);
	printf("\n"); 
}

//顺序查找索引表 并 返回块号（从0开始） 
int Seq_Search_Index(BSList L,ElemType key)	
{
	int i=0;
	while (i<L.Index_len && key>L.Index[i].maxValue)			
		i++;
	return i;		//查找成功返回i所指分块，当key大于所有索引值会返回L.Index_len 
 } 

//块内顺序查找 并 返回数组下标 
int Seq_Search_Block(BSList L,ElemType key,int point)
{
	for (int i=L.Index[point].low; i<=L.Index[point].high; i++)		
		if (L.List[i]==key)	
			return i;
	return -1;		//顺序查找失败 
}

void Block_Search(BSList L,ElemType key)
{
	int point=Seq_Search_Index(L,key);	//顺序查找索引表	返回块号	point_block   
	printf("你的查找目标为:%d\n",key);
//	printf("%d %d",L.Index[point].low,L.Index[point].high);
	if (point==L.Index_len)	
		printf("你给的数太大了,超出了索引表的范围!\n");
	else 
		{	
			int loca=Seq_Search_Block(L,key,point);		//块内顺序查找
			if (loca==-1)	
				printf("失败了,找不到你的%d\n",key);
			else 
				printf("找到了!是顺序表的L[%d]\n",loca);
		}
}
//----------------------------------------------------------------------------------------
int Binary_Search_Index(BSList L,ElemType key)
{
	int low=0,high=L.Index_len-1,mid;
	while (low<=high)
	{
		mid=(low+high)/2;			//取中间位置 
		if (L.Index[mid].maxValue==key)		
			return	mid;			//查找成功则返回元素下标 
		else if (L.Index[mid].maxValue>key)
			high=mid-1;				//从前半部分继续查找 
		else 
			low=mid+1;				//从后半部分继续查找 
	}
	return low;				//若索引表不包含目标关键字，最终会停在low>high，要在low所指分块内查找
}

void Block_Search2(BSList L,ElemType key)
{
	int point=Binary_Search_Index(L,key);	//折半查找索引表	返回块号	point_block  
	printf("你的查找目标为:%d\n",key);
//	printf("%d %d",L.Index[point].low,L.Index[point].high);
	if (point==L.Index_len)	
		printf("你给的数太大了,超出了索引表的范围!\n");
	else 
		{	
			int loca=Seq_Search_Block(L,key,point);		//块内顺序查找
			if (loca==-1)	
				printf("失败了,找不到你的%d\n",key);
			else 
				printf("找到了!是顺序表的L[%d]\n",loca);
		}
}
