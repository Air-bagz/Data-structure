//无向图G，邻接矩阵存储，转化为邻接表，再进行深度优先遍历 			undirected graph
#include<stdio.h>
#include<stdlib.h>
//------------------------------------------------------------------------------------
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
void beforeDFS(ALGraph GG); 
void visit(int v);
void DFS(ALGraph GG,int v);
void DFSTraverse(ALGraph GG);
ArcNode *AL_FirstNeighbor(ALGraph GG,int x);
ArcNode *AL_NextNeighbor(ALGraph GG,int x,ArcNode *y);
//------------------------------------------------------------------------------------------

int main()
{
	MGraph G;
	Graph_input(G);
	//Graph_print(G);
	ALGraph GG;		
	MGraph_to_ALGraph(G,GG);
	//ALGraph_Print(GG); 
	beforeDFS(GG);	printf("从顶点%d出发得到的深度优先遍历序列:",1);	DFS(GG,1);	printf("\n"); 
	beforeDFS(GG);	printf("从顶点%d出发得到的深度优先遍历序列:",2);	DFS(GG,2);	printf("\n");
 	beforeDFS(GG);	printf("从顶点%d出发得到的深度优先遍历序列:",3);	DFS(GG,3);	printf("\n");
	//DFSTraverse(GG);		//图G是非连通图再用 
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
//DFS之前需要初始化标记数组 
void beforeDFS(ALGraph GG)
{
	for (int i=1; i<=GG.vexnum; i++)		//结点编号从1开始
		visited[i]=false;		//访问标记数组初始化
}

void visit(int v)
{
	printf("%d ",v);
}

//深度优先遍历
void DFS(ALGraph GG,int v)	//从顶点v出发，深度优先遍历图G 
{
	visit(v);
	visited[v]=true;
	for (ArcNode *w=AL_FirstNeighbor(GG,v); w!=NULL; w=AL_NextNeighbor(GG,v,w))
			if (!visited[w->adjvex])	//w为v的尚未访问的邻接顶点 
			{
				DFS(GG,w->adjvex);
			 }//if  
}

void DFSTraverse(ALGraph GG)	//对图G进行深度优先遍历 
{
	beforeDFS(GG);
	for (int i=1; i<=GG.vexnum; i++)		//从顶点1开始遍历 
		if (!visited[i])
			DFS(GG,i);
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
