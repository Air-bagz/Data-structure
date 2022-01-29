//顺序查找无哨兵：查找成功，则返回元素下标；查找失败，则返回-1
//顺序查找有哨兵：查找成功，则返回元素下标；查找失败，则返回0

typedef struct			//查找表的数据结构(顺序表) 
{
	ElemType *elem;		//动态数组基址 
	int Len;			//表的长度 
}SeqTable;

//顺序查找----pdf写法 
int Seq_Search(SeqTable ST,ElemType key)
{
	int i;
	for (i=0; i<ST.len && ST.elem[i]!=key; i++);
	//查找成功，则返回元素下标；查找失败，则返回-1
	return i==ST.Len? -1 : i; 
 } 

//顺序查找----我的写法 
int Seq_Search(SeqTable ST,ElemType key)
{
	int i=0;
	while (i<ST.Len && ST.elem[i]!=key)			
		i++;
	//查找成功，则返回元素下标；查找失败，则返回-1
	return i==ST.Len? -1 : i; 
}

//顺序查找----线性表写法 
int Seq_Search(SeqTable ST,ElemType key)
{
	for (int i=0; i<L.length; i++)
		if (ST.elem[i]==key)		
			return i;		//下标 
	return -1;	//失败 
}
/* 
int LocateElem(SqList L, int e)		//线性表 
{
	for (int i=0; i<L.length; i++)
		if (L.data[i]==e)		
			return i+1;		//位序 
	return 0;			
}
*/
//--------------------------------------------------------------------------------------------- 
//顺序查找，有哨兵----pdf写法
int Seq_Search(SeqTable ST,ElemType key)
{
	ST.elem[0]=key;		//哨兵 
	int i;
	for (i=ST.Len; ST.elem[i]!=key; i--);	//从后往前找 
	return i; 		//查找成功，则返回元素下标；查找失败，则返回0
 } 

//顺序查找，有哨兵----我的写法
int Seq_Search(SeqTable ST,ElemType key)
{
	ST.elem[0]=key;		//guard
	int i=ST.Len;
	while (ST.elem[i]!=key)		//无需判断是否越界 
		i--;
	return i; 		//查找成功，则返回元素下标；查找失败，则返回0
 } 
 
//顺序查找，有哨兵----线性表写法 
int Seq_Search(SeqTable ST,ElemType key)
{
	for (int i=ST.Len; ; i--)
		if (ST.elem[i]==key)		
			return i;		//下标 
}
