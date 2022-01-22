//邻接矩阵按照序号增序转化未邻接表，建立边表使用后插法，保持邻接顶点序号递增 
//MGraph G----->ALGraph GG
#include<stdio.h>
#include<stdlib.h>
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

void Graph_input(MGraph &G);
void Graph_print(MGraph G);
int FirstNeighbor(MGraph G,int x);
int NextNeighbor(MGraph G,int x,int y);
void MGraph_to_ALGraph(MGraph G,ALGraph &GG);
void Convert(ALGraph G,int n,int arcs[10][10]);  //王道p214

int main()
{
	MGraph G;
	Graph_input(G);
	//Graph_print(G);
	ALGraph GG;		GG.vexnum=G.vexnum;
	MGraph_to_ALGraph(G,GG);
	printf("顶点表____边表\n");
	for (int i=1; i<=G.vexnum; i++)
	{
		printf("[%d]:",GG.vertexs[i].data);
			ArcNode *p;
			for (p=GG.vertexs[i].firstarc; p!=NULL; p=p->nextarc)
				printf("--->%d",p->adjvex);
		printf("\n");
	}
	
	printf("ALGraph_to_MGraph:\n"); 
	int arcs[10][10]; 
	Convert(GG,8,arcs);
	for (int i=1; i<=8; i++)
	{
		for (int j=1; j<=8; j++)
			printf("%d ",arcs[i][j]);
		printf("\n");
	}
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

void MGraph_to_ALGraph(MGraph G,ALGraph &GG)	//相当于不带头结点的尾插法，先单独处理第一个， 
{
	ArcNode *r;		//尾指针 
	for (int i=1; i<=G.vexnum; i++)
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

void Convert(ALGraph G,int n,int arcs[10][10])	//参考王道p214 
{
	//此算法将邻接表方式表示的图G转换为邻接矩阵arcs
	ArcNode *p;
	for (int i=1; i<=n; i++)		//依次遍历各顶点表结点为头的边链表
	{
		p=(G.vertexs[i].firstarc);		//取出顶点i的第一条出边
		while (p!=NULL)			//遍历边链表 
		{
			arcs[i][p->adjvex]=1;//取下一条出边 	G.Edge[][]
			p=p->nextarc;
		 }//while 
	}//for
}
