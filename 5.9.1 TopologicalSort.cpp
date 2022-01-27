//拓扑排序	邻接表+栈/队列 
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
//邻接表法 
typedef int VertexType;			//顶点的数据类型 
typedef int Infotype; 				//带权图中边上权值的数据类型 
//边表结点 
typedef struct ArcNode		
{
	int adjvex;				//该弧所指向的顶点的位置 
	struct ArcNode *nextarc;//指向下一条弧的指针 
	Infotype info;		//网的边权值 
}ArcNode; 
//顶点表结点 
typedef struct VNode		
{
	VertexType data;		//顶点信息 
	ArcNode *firstarc;		//指向第一条依附该顶点的弧的指针 
 }VNode,AdjList[MaxVertexNum];
//用邻接表存储的图
typedef struct
{
	AdjList vertexs;	//vertices		vertexes		<=> VNode vertexs[MaxVertexNum];
	int vexnum,arcnum;	//图的顶点数和弧数 
}ALGraph;
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
void ALGraph_print(ALGraph GG);
int FirstNeighbor(MGraph G,int x);
int NextNeighbor(MGraph G,int x,int y);
void MGraph_to_ALGraph(MGraph G,ALGraph &GG);
//-----------------------------------------------------------------------------------------
void Init_indegree_print(MGraph G);
bool TopologicalSort(ALGraph G); 
void InitStack(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool StackEmpty(SqStack S);
bool StackFull(SqStack S); 

int indegree[MaxVertexNum];		//indegree[i] 顶点i的入度
int print[MaxVertexNum];		//记录拓扑序列print[1]---print[count]; 
SqStack S;					//保存度为0的顶点（也可用队列） 

int main()
{
	MGraph G;
	Graph_input(G);		//pdf例子
	//Graph_print(G);
	ALGraph GG;		GG.vexnum=G.vexnum;
	MGraph_to_ALGraph(G,GG);
	//ALGraph_print(GG);
	Init_indegree_print(G);
	if ( TopologicalSort(GG) )
	{
		printf("拓扑排序成功,拓扑序列为:");
		for (int i=0; i<GG.vexnum; i++)
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

void ALGraph_print(ALGraph GG)
{
	printf("顶点表____边表\n");
	for (int i=0; i<GG.vexnum; i++)		//0号 
	{
		printf("[%d]:",GG.vertexs[i].data);
			ArcNode *p;
			for (p=GG.vertexs[i].firstarc; p!=NULL; p=p->nextarc)
				printf("--->%d",p->adjvex);
		printf("\n");
	}
}

//求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1 
int FirstNeighbor(MGraph G,int x)
{
	for (int j=0; j<G.vexnum; j++)    //0号 
		if (G.Edge[x][j]==1)	//有边(x,j)	
			return j;
	return -1;	//x没有邻接点
}

//假设图G中顶点y是顶点x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1 
int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<G.vexnum; j++ )	//0号 
		if (G.Edge[x][j]==1)	//有边(x,j)
			return j;
	return -1; 
}

void MGraph_to_ALGraph(MGraph G,ALGraph &GG)	//相当于不带头结点的尾插法，先单独处理第一个， 
{
	ArcNode *r;		//尾指针 
	for (int i=0; i<G.vexnum; i++)		//0号 
		{
			GG.vertexs[i].data=i;
			GG.vertexs[i].firstarc=NULL;
			int w=FirstNeighbor(G,i);
			if	(w>0)	
			{
				GG.vertexs[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
				GG.vertexs[i].firstarc->adjvex=w;
				GG.vertexs[i].firstarc->nextarc=NULL;	//处理完第一个边 
				r=GG.vertexs[i].firstarc;			//尾指针初始 
				for (w=NextNeighbor(G,i,w); w>0; w=NextNeighbor(G,i,w))
				{
					ArcNode *s=(ArcNode *)malloc(sizeof(ArcNode));
					s->adjvex=w;
					r->nextarc=s;
					r=s;
				}
				r->nextarc=NULL;
			}//if 
		}//for
}
//-----------------------------------------------------------------------------------------

void Init_indegree_print(MGraph G)
{
	memset(indegree,0,G.vexnum);	//先清零 
	for (int i=0; i<G.vexnum; i++)
		for (int j=0; j<G.vexnum; j++)
			indegree[i]=indegree[i]+G.Edge[j][i];	//第i列之和是 顶点i的入度 
	memset(print,-1,G.vexnum);
	//for (int i=0; i<G.vexnum; i++)
	//	printf("%d %d\n",indegree[i],print[i]);
}

bool TopologicalSort(ALGraph G)
{
	InitStack(S);		//初始化栈，存储入度为0的顶点
	for (int i=0; i<G.vexnum; i++)
		if (indegree[i]==0)
			Push(S,i);		//将所有入度为0的顶点进栈
	int count=0;			//计数，记录当前已经输出的顶点数 
	int i;
	while (!StackEmpty(S))		//栈不空，则存在入度为0的顶点 
	{
		Pop(S,i);			//栈顶元素出栈 
		print[count++]=i;		//输出顶点i 
		for (ArcNode *p=G.vertexs[i].firstarc; p; p=p->nextarc)
		{//将所有i指向的顶点的入度减1，并且将入度减为0的顶点压入栈S 
			int v=p->adjvex;
			if (!(--indegree[v]))
				Push(S,v);		//入度为0，则入栈 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//排序失败，有向图中有回路 
	else
		return true;		//拓扑排序成功 
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
