#define MaxSize 10			//��̬�������󳤶� 
typedef struct				//��̬����ṹ���͵Ķ��� 
{					
	ElemType data;			//�洢����Ԫ�� 
	int next;				//��һ��Ԫ�ص������±� 
 }SLinkList[MaxSize]; 
 
void testSLinkList()
{
	SLinkList a;
	//
 } 

void InitSLinkList(SLinkList &a)
{
	a[0].next=-1;					//ͷ����������Ϊ�� 
	for (int i=1;i<MaxSize;i++)
		a[i].next=-2;				//��ʾ������ 
}

/*
�ֱ�ȼ� 
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
