//无向图G，邻接矩阵存储，进行深度优先遍历 			undirected graph_DFS
#include<stdio.h>
//----------------------------------------------------------------------
//邻接矩阵法存储图
#define MaxVertexNum 100					//顶点数目的最大值 
typedef struct
{
	char Vex[MaxVertexNum];					//顶点表 
	int Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表；bool 或 枚举类型 
	int vexnum,arcnum;						//图的当前顶点数和边数/弧数 
}MGraph;

bool visited[MaxVertexNum];			//访问标记数组 
//------------------------------------------------------------------------
void Graph_input(MGraph &G);
void Graph_print(MGraph G);
void beforeDFS(MGraph G); 
void visit(int v);
void DFS(MGraph G,int v);
void DFSTraverse(MGraph G);
int FirstNeighbor(MGraph G,int x);
int NextNeighbor(MGraph G,int x,int y);
//-----------------------------------------------------------------------------------------

int main()
{
	MGraph G;
	Graph_input(G);
	//Graph_print(G);
	beforeDFS(G);	printf("从顶点%d出发得到的深度优先遍历序列:",1);	DFS(G,1);	printf("\n"); 
	beforeDFS(G);	printf("从顶点%d出发得到的深度优先遍历序列:",2);	DFS(G,2);	printf("\n");
 	beforeDFS(G);	printf("从顶点%d出发得到的深度优先遍历序列:",3);	DFS(G,3);	printf("\n");
	//DFSTraverse(G);		//图G是非连通图再用 
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

//DFS之前需要初始化标记数组 
void beforeDFS(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//结点编号从1开始
		visited[i]=false;		//访问标记数组初始化
}

void visit(int v)
{
	printf("%d ",v);
}

//深度优先遍历
void DFS(MGraph G,int v)	//从顶点v出发，深度优先遍历图G 
{
	visit(v);
	visited[v]=true;
	for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			if (!visited[w])	//w为v的尚未访问的邻接顶点 
			{
				DFS(G,w);
			 }//if  
}

void DFSTraverse(MGraph G)	//对图G进行深度优先遍历 
{
	beforeDFS(G);
	for (int i=1; i<=G.vexnum; i++)		//从顶点1开始遍历 
		if (!visited[i])
			DFS(G,i);
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
