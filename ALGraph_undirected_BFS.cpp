//无向图G，邻接矩阵存储，转化为邻接表，再进行广度优先遍历 			undirected graph
#include<stdio.h>
#include<stdlib.h>
//------------------------------------------------------------------------------------
#define MaxSize 100				//定义队列中元素的最大个数 

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];		//用静态数组存放队列元素 
	int front,rear; 			//队头指针和队尾指针 
}SqQueue;

SqQueue Q;		//全局遍历或每次代入 

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

bool visited[MaxVertexNum];			//访问标记数组 
ArcNode *r;		//尾指针 
//----------------------------------------------------------------------------------------
void Graph_input(MGraph &G);
void Graph_print(MGraph G);
int AM_FirstNeighbor(MGraph G,int x);
int AM_NextNeighbor(MGraph G,int x,int y);
void MGraph_to_ALGraph(MGraph G,ALGraph &GG);
void ALGraph_Print(ALGraph GG); 
//-----------------------------------------------------------------------------------------
void beforeBFS(ALGraph GG); 
void visit(int v);
void BFS(ALGraph GG,int v);
void BFSTraverse(ALGraph GG);
ArcNode *AL_FirstNeighbor(ALGraph GG,int x);
ArcNode *AL_NextNeighbor(ALGraph GG,int x,ArcNode *y);
//------------------------------------------------------------------------------------------
void InitQueue(SqQueue &Q); 
bool EnQueue(SqQueue &Q,ElemType x);
bool DeQueue(SqQueue &Q,ElemType &x);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);
//------------------------------------------------------------------------------------------

int main()
{
	MGraph G;
	Graph_input(G);
	//Graph_print(G);
	ALGraph GG;		
	MGraph_to_ALGraph(G,GG);
	ALGraph_Print(GG); 
	beforeBFS(GG);	printf("从顶点%d出发得到的广度优先遍历序列:",1);	BFS(GG,1);	printf("\n"); 
	beforeBFS(GG);	printf("从顶点%d出发得到的广度优先遍历序列:",2);	BFS(GG,2);	printf("\n");
 	beforeBFS(GG);	printf("从顶点%d出发得到的广度优先遍历序列:",3);	BFS(GG,3);	printf("\n");
	//BFSTraverse(G);		//图G是非连通图再用 
}

void Graph_input(MGraph &G)
{
	FILE *fp;
	fp=fopen("Z:\\MGraph_input.txt","r");
	fscanf(fp,"%d",&G.vexnum);
	for (int i=1; i<=G.vexnum; i++)
	 for (int j=1; j<=G.vexnum; j++)
	 	fscanf(fp,"%d",&G.Edge[i][j]);
}

void Graph_print(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)
	{
		for (int j=1; j<=G.vexnum; j++)
			printf("%d ",G.Edge[i][j]);
		printf("\n");
	}
}

//求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1 
int AM_FirstNeighbor(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)
		if (G.Edge[x][j]==1)	//有边(x,j)	
			return j;
	return -1;	//x没有邻接点
}

//假设图G中顶点y是顶点x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1 
int AM_NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++ )
		if (G.Edge[x][j]==1)	//有边(x,j)
			return j;
	return -1; 
}

void MGraph_to_ALGraph(MGraph G,ALGraph &GG)	//相当于不带头结点的尾插法，先单独处理第一个， 
{
	ArcNode *r;		//尾指针
	for (int i=1; i<=G.vexnum; i++)
		{
			GG.vertexs[i].data=i;
			GG.vertexs[i].firstarc=NULL;
			int w=AM_FirstNeighbor(G,i);
			if	(w>0)	
			{
				GG.vertexs[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
				GG.vertexs[i].firstarc->adjvex=w;
				GG.vertexs[i].firstarc->nextarc=NULL;	//处理完第一个边 
				r=GG.vertexs[i].firstarc;			//尾指针初始 
				for (w=AM_NextNeighbor(G,i,w); w>0; w=AM_NextNeighbor(G,i,w))
				{
					ArcNode *s=(ArcNode *)malloc(sizeof(ArcNode));
					s->adjvex=w;
					r->nextarc=s;
					r=s;
				}
				r->nextarc=NULL;
			}//if 
		}//for
	GG.vexnum=G.vexnum;
}

void ALGraph_Print(ALGraph GG)
{
	printf("顶点表____边表\n");
	for (int i=1; i<=GG.vexnum; i++)
	{
		printf("[%d]:",GG.vertexs[i].data);
			ArcNode *p;
			for (p=GG.vertexs[i].firstarc; p!=NULL; p=p->nextarc)
				printf("--->%d",p->adjvex);
		printf("\n");
	}
}
//---------------------------------------------------------------------------------
void beforeBFS(ALGraph GG)
{
	for (int i=1; i<=GG.vexnum; i++)		//结点编号从1开始
		visited[i]=false;		//访问标记数组初始化
	InitQueue(Q);		//初始化辅助队列Q
}

void visit(int v)
{
	printf("%d ",v);
}

void BFS(ALGraph GG,int v)
{
	visit(v);			//访问初始顶点v 
	visited[v]=true;	//对v做已访问标记 
	EnQueue(Q,v);		//顶点v入队列Q
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,v);	//顶点v出队列 
		for (ArcNode *w=AL_FirstNeighbor(GG,v); w!=NULL; w=AL_NextNeighbor(GG,v,w))
			//检测v所有邻接点
			if (!visited[w->adjvex])	//w为v的尚未访问的邻接顶点 
			{
				visit(w->adjvex);		//访问顶点w 
				visited[w->adjvex]=true;//对w做已访问标记 
				EnQueue(Q,w->adjvex);	//顶点w入队列Q 
			 }//if 
	}//while
}

void BFSTraverse(ALGraph GG)
{
	beforeBFS(GG);
	for (int i=1; i<=GG.vexnum; i++)	//从1号顶点开始遍历 
		if (!visited[i])	//对每个连通分量调用一次BFS 
			BFS(GG,i); 		//vi未访问过，从vi开始BFS 
}

//求图G中顶点x的第一个邻接结点，返回结点p，可能为空 
ArcNode *AL_FirstNeighbor(ALGraph GG,int x)
{
	return GG.vertexs[x].firstarc;	
}

//图G中结点y是顶点x的一个邻接点，返回y的下一个邻接结点，可能为空 
ArcNode *AL_NextNeighbor(ALGraph GG,int x,ArcNode *y)
{
	return y->nextarc; 
}

//-----------------------------------------------------------------------------------
void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}

bool EnQueue(SqQueue &Q,ElemType x)		//入队 
{
	if (QueueFull(Q))	return false;		//队满报错 
	Q.data[Q.rear]=x;				//rear指向下一个应该插入的位置 
	Q.rear=(Q.rear+1)%MaxSize;		//队尾指针后移，[0,1,...,MaxSize-1]环状 
	return true;
}

bool DeQueue(SqQueue &Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;		//队空报错
	x=Q.data[Q.front];				//front指向队头元素 
	Q.front=(Q.front+1)%MaxSize; 	//队头指针后移，环状 
	return true;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.front)	return true;	//队空条件 
	else return false;
}

bool QueueFull(SqQueue Q)
{
	if ( (Q.rear+1)%MaxSize==Q.front )	return true;	//队满条件	牺牲一个 
	else return false;
 } 
