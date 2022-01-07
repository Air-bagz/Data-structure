#define MaxSize 10			//静态链表的最大长度 
typedef struct				//静态链表结构类型的定义 
{					
	ElemType data;			//存储数据元素 
	int next;				//下一个元素的数组下标 
 }SLinkList[MaxSize]; 
 
void testSLinkList()
{
	SLinkList a;
	//
 } 

void InitSLinkList(SLinkList &a)
{
	a[0].next=-1;					//头结点后面连接为空 
	for (int i=1;i<MaxSize;i++)
		a[i].next=-2;				//表示结点空闲 
}

/*
分别等价 
struct Node
{
	ELemType data;
	int next;
}
typedef struct Node SLinkList[MaxSize];

void testSLinkList()
{
	struct Node a[MaxSize];
	//
}
*/
