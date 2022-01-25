//逆拓扑排序	邻接矩阵+栈/队列 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxVertexNum 100					//顶点数目的最大值 
//------------------------------------------------------------------------------------
//邻接矩阵法存储图
typedef struct
{
	char Vex[MaxVertexNum];					//顶点表 
	int Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表；bool 或 枚举类型 
	int vexnum,arcnum;						//图的当前顶点数和边数/弧数 
}MGraph;
//--------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
typedef int ElemType;
#define MaxSize 100				//定义栈中元素的最大个数 
typedef struct
{
	ElemType data[MaxSize];		//静态数组存放栈中元素 
	int top;					//栈顶指针 
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

int outdegree[MaxVertexNum];		//indegree[i] 顶点i的入度
int print[MaxVertexNum];		//记录拓扑序列print[1]---print[count]; 
SqStack S;					//保存度为0的顶点（也可用队列） 

int main()
{
	MGraph G;
	Graph_input(G);		//pdf例子
	//Graph_print(G);
	Init_outdegree_print(G);
	if ( ReTopologicalSort(G) )
	{
		printf("拓扑排序成功,拓扑序列为:");
		for (int i=0; i<G.vexnum; i++)
			printf("%d ",print[i]);
	}
	else printf("拓扑排序失败，有向图中有回路");
	
	return 0; 
 } 

void Graph_input(MGraph &G)
{
	FILE *fp;
	fp=fopen("Z:\\Topo_Order.txt","r");
	fscanf(fp,"%d",&G.vexnum);
	for (int i=0; i<G.vexnum; i++)		//注意，这个例子是从0开始 
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
	for (int j=0; j<G.vexnum; j++)    //0号 
		if (G.Edge[j][x]==1)	//有边<j,x>	
			return j;
	return -1;	//x没有邻接点
}

int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<G.vexnum; j++ )	//0号 
		if (G.Edge[j][x]==1)	//有边<j,x>
			return j;
	return -1; 
}

//-----------------------------------------------------------------------------------------

void Init_outdegree_print(MGraph G)
{
	memset(outdegree,0,G.vexnum*sizeof(int));	//先清零 
	for (int i=0; i<G.vexnum; i++)
		for (int j=0; j<G.vexnum; j++)
			outdegree[i]=outdegree[i]+G.Edge[i][j];	//第i行之和是 顶点i的出度 
	memset(print,-1,G.vexnum*sizeof(int));
	for (int i=0; i<G.vexnum; i++)
		printf("%d %d\n",outdegree[i],print[i]);
}

bool ReTopologicalSort(MGraph G)
{
	InitStack(S);		//初始化栈，存储出度为0的顶点
	for (int i=0; i<G.vexnum; i++)
		if (outdegree[i]==0)
			Push(S,i);		//将所有出度为0的顶点进栈
	int count=0;			//计数，记录当前已经输出的顶点数 
	int i;
	while (!StackEmpty(S))		//栈不空，则存在入度为0的顶点 
	{
		Pop(S,i);			//栈顶元素出栈 
		print[count++]=i;		//输出顶点i 
		for (int p=FirstNeighbor(G,i); p>=0; p=NextNeighbor(G,i,p))	//编号从0开始，必须>=0 
		{//将所有指向i的顶点的出度减1，若减为0则压入栈S 
			int v=p;
			if (!(--outdegree[v]))
				Push(S,v);		//入度为0，则入栈 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//逆排序失败，有向图中有回路 
	else
		return true;		//逆拓扑排序成功 
 } 
 
void InitStack(SqStack &S)		//初始化栈 
{
	S.top=-1;		//初始化栈顶指针 
}

bool Push(SqStack &S,ElemType x)		//入栈操作 
{
	if ( StackFull(S) )	return false;		//栈满，报错
	S.top=S.top+1;			//指针先+1 
	S.data[S.top]=x;		//新元素入栈				
	return true; 			//<=> S.data[++S.top]=x;
 } 

bool Pop(SqStack &S,ElemType &x)		//出栈操作 
{
	if ( StackEmpty(S) )	return false;	//栈空，报错
	x=S.data[S.top];		//栈顶元素先出栈 
	S.top=S.top-1;			//指针再减1 
	return true;			//<=> x=S.data[S.top--]; 
}

bool StackEmpty(SqStack S)		//判断栈空 
{
	if (S.top==-1)	return true;	//栈空 
	else return false;			//不空 
}

bool StackFull(SqStack S)		//判断栈满 
{
	if (S.top==MaxSize-1)	return true;	//栈满 
	else return false;			//不满 
}
