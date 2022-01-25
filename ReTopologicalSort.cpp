//����������	�ڽӾ���+ջ/���� 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxVertexNum 100					//������Ŀ�����ֵ 
//------------------------------------------------------------------------------------
//�ڽӾ��󷨴洢ͼ
typedef struct
{
	char Vex[MaxVertexNum];					//����� 
	int Edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬱߱�bool �� ö������ 
	int vexnum,arcnum;						//ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;
//--------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
typedef int ElemType;
#define MaxSize 100				//����ջ��Ԫ�ص������� 
typedef struct
{
	ElemType data[MaxSize];		//��̬������ջ��Ԫ�� 
	int top;					//ջ��ָ�� 
 }SqStack;
//----------------------------------------------------------------------------------------

void Graph_input(MGraph &G);
void Graph_print(MGraph G);
int FirstNeighbor(MGraph G,int x);
int NextNeighbor(MGraph G,int x,int y);
//-----------------------------------------------------------------------------------------
void Init_outdegree_print(MGraph G);
bool ReTopologicalSort(MGraph G); 
void InitStack(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool StackEmpty(SqStack S);
bool StackFull(SqStack S); 

int outdegree[MaxVertexNum];		//indegree[i] ����i�����
int print[MaxVertexNum];		//��¼��������print[1]---print[count]; 
SqStack S;					//�����Ϊ0�Ķ��㣨Ҳ���ö��У� 

int main()
{
	MGraph G;
	Graph_input(G);		//pdf����
	//Graph_print(G);
	Init_outdegree_print(G);
	if ( ReTopologicalSort(G) )
	{
		printf("��������ɹ�,��������Ϊ:");
		for (int i=0; i<G.vexnum; i++)
			printf("%d ",print[i]);
	}
	else printf("��������ʧ�ܣ�����ͼ���л�·");
	
	return 0; 
 } 

void Graph_input(MGraph &G)
{
	FILE *fp;
	fp=fopen("Z:\\Topo_Order.txt","r");
	fscanf(fp,"%d",&G.vexnum);
	for (int i=0; i<G.vexnum; i++)		//ע�⣬��������Ǵ�0��ʼ 
	 for (int j=0; j<G.vexnum; j++)
	 	fscanf(fp,"%d",&G.Edge[i][j]);
}

void Graph_print(MGraph G)
{
	for (int i=0; i<G.vexnum; i++)
	{
		for (int j=0; j<G.vexnum; j++)
			printf("%d ",G.Edge[i][j]);
		printf("\n");
	}
}

int FirstNeighbor(MGraph G,int x)
{
	for (int j=0; j<G.vexnum; j++)    //0�� 
		if (G.Edge[j][x]==1)	//�б�<j,x>	
			return j;
	return -1;	//xû���ڽӵ�
}

int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<G.vexnum; j++ )	//0�� 
		if (G.Edge[j][x]==1)	//�б�<j,x>
			return j;
	return -1; 
}

//-----------------------------------------------------------------------------------------

void Init_outdegree_print(MGraph G)
{
	memset(outdegree,0,G.vexnum*sizeof(int));	//������ 
	for (int i=0; i<G.vexnum; i++)
		for (int j=0; j<G.vexnum; j++)
			outdegree[i]=outdegree[i]+G.Edge[i][j];	//��i��֮���� ����i�ĳ��� 
	memset(print,-1,G.vexnum*sizeof(int));
	for (int i=0; i<G.vexnum; i++)
		printf("%d %d\n",outdegree[i],print[i]);
}

bool ReTopologicalSort(MGraph G)
{
	InitStack(S);		//��ʼ��ջ���洢����Ϊ0�Ķ���
	for (int i=0; i<G.vexnum; i++)
		if (outdegree[i]==0)
			Push(S,i);		//�����г���Ϊ0�Ķ����ջ
	int count=0;			//��������¼��ǰ�Ѿ�����Ķ����� 
	int i;
	while (!StackEmpty(S))		//ջ���գ���������Ϊ0�Ķ��� 
	{
		Pop(S,i);			//ջ��Ԫ�س�ջ 
		print[count++]=i;		//�������i 
		for (int p=FirstNeighbor(G,i); p>=0; p=NextNeighbor(G,i,p))	//��Ŵ�0��ʼ������>=0 
		{//������ָ��i�Ķ���ĳ��ȼ�1������Ϊ0��ѹ��ջS 
			int v=p;
			if (!(--outdegree[v]))
				Push(S,v);		//���Ϊ0������ջ 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//������ʧ�ܣ�����ͼ���л�· 
	else
		return true;		//����������ɹ� 
 } 
 
void InitStack(SqStack &S)		//��ʼ��ջ 
{
	S.top=-1;		//��ʼ��ջ��ָ�� 
}

bool Push(SqStack &S,ElemType x)		//��ջ���� 
{
	if ( StackFull(S) )	return false;		//ջ��������
	S.top=S.top+1;			//ָ����+1 
	S.data[S.top]=x;		//��Ԫ����ջ				
	return true; 			//<=> S.data[++S.top]=x;
 } 

bool Pop(SqStack &S,ElemType &x)		//��ջ���� 
{
	if ( StackEmpty(S) )	return false;	//ջ�գ�����
	x=S.data[S.top];		//ջ��Ԫ���ȳ�ջ 
	S.top=S.top-1;			//ָ���ټ�1 
	return true;			//<=> x=S.data[S.top--]; 
}

bool StackEmpty(SqStack S)		//�ж�ջ�� 
{
	if (S.top==-1)	return true;	//ջ�� 
	else return false;			//���� 
}

bool StackFull(SqStack S)		//�ж�ջ�� 
{
	if (S.top==MaxSize-1)	return true;	//ջ�� 
	else return false;			//���� 
}
