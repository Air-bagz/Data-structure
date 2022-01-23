//无向图连通G，邻接矩阵存储，广度优先遍历求单源最短路径 		undirected graph
#include<stdio.h>
#include<limits.h>
//----------------------------------------------------------------------
#define MaxSize 100				//定义队列中元素的最大个数 

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];		//用静态数组存放队列元素 
	int front,rear; 			//队头指针和队尾指针 
}SqQueue;

SqQueue Q;		//全局遍历或每次代入 
//-----------------------------------------------------------------------
//邻接矩阵法存储图
#define MaxVertexNum 100					//顶点数目的最大值 
typedef struct
{
	char Vex[MaxVertexNum];					//顶点表 
	int Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表；bool 或 枚举类型 
	int vexnum,arcnum;						//图的当前顶点数和边数/弧数 
}MGraph;

bool visited[MaxVertexNum];			//访问标记数组 
int dist[MaxVertexNum];	//各个顶点到源点最短路径的长度 		dist[i]=x    i---start  min_distance==x 
int path[MaxVertexNum];	//每个顶点在这个最短路径上的直接前驱 	path[i]=j    start-->...--->j--->i-->...

//------------------------------------------------------------------------
void Graph_input(MGraph &G);
void Graph_print(MGraph G);
void beforeBFS(MGraph G); 
//void visit(int v);
void BFS_dist(MGraph G,int v);
void BFS_MIN_Distance(MGraph G,int st);
int FirstNeighbor(MGraph G,int x);
int NextNeighbor(MGraph G,int x,int y);
//--------------------------------------------------
void InitQueue(SqQueue &Q); 
bool EnQueue(SqQueue &Q,ElemType x);
bool DeQueue(SqQueue &Q,ElemType &x);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);

int main()
{
	MGraph G;
	Graph_input(G);
	//Graph_print(G);
	int st=2;	//起点 
	BFS_MIN_Distance(G,st);	//图G需是连通图 ,2为源点 		BFS求单源最短路径 
//	for (int i=1; i<=G.vexnum; i++)
//		printf("%d ",dist[i]);
//	printf("\n");
//	for (int i=1; i<=G.vexnum; i++)
//		printf("%d ",path[i]);
	int en=8;	//终点 
	printf("%d到%d的最短路径长度 = d[%d] = %d\n",st,en,en,dist[en]);
	printf("通过path数组可知,%d到%d的最短路径为: %d",st,en,en);
	for (int i=path[en]; i!=-1; i=path[i])
		printf("<---%d",i); 
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

//BFS之前需要初始化辅助队列和标记数组 
void beforeBFS_MIN_Distance(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//结点编号从1开始
		visited[i]=false;		//访问标记数组初始化
	InitQueue(Q);		//初始化辅助队列Q
	//d[i]表示u到i结点的最短路径长度 
	for (int i=1; i<=G.vexnum; i++)
	{
		dist[i]=INT_MAX;	//初始化路径长度 
		path[i]=-1;		//最短路径从哪个顶点过来 
	}
}

void visit(int v)
{
	printf("%d ",v);
}

void BFS_dist(MGraph G,int v) //从顶点v出发，广度优先遍历图G 
{
	dist[v]=0;		//+
	//visit(v);
	visited[v]=true;	//对v做已访问标记 
	EnQueue(Q,v);		//顶点v入队列Q 
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,v);	//顶点v出队列 
		for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			//检测v所有邻接点
			if (!visited[w])	//w为v的尚未访问的邻接顶点 
			{
				//visit(w);		
				dist[w]=dist[v]+1;		//+ 
				path[w]=v;				//+
				visited[w]=true;//对w做已访问标记 
				EnQueue(Q,w);	//顶点w入队列Q 
			 }//if 
	}//while
}

void BFS_MIN_Distance(MGraph G,int st)	//求顶点start到其他顶点的最短路径 
{
	beforeBFS_MIN_Distance(G);	//准备工作 
	BFS_dist(G,st); 		
}

//求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1 
int FirstNeighbor(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)
		if (G.Edge[x][j]==1)	//有边(x,j)	
			return j;
	return -1;	//x没有邻接点
}

//假设图G中顶点y是顶点x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1 
int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++ )
		if (G.Edge[x][j]==1)	//有边(x,j)
			return j;
	return -1; 
}

//---------------------------------------------------------------
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
