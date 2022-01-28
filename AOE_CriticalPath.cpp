//Critical Path _ AOE
#include<stdio.h>
#include<limits.h>
#include<string.h>		//memset
//------------------------------------------------------------------------------------
//邻接矩阵法存储带权图（网） 
#define MaxVertexNum 10				//顶点数目的最大值 
#define MaxArcNum 34		//边数目的最大值 

typedef char VertexType;					//顶点的数据类型 
typedef int EdgeType; 						//带权图中边上权值的数据类型 
typedef struct
{
	VertexType Vex[MaxVertexNum];					//顶点 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];		//边的权 
	int vexnum,arcnum;								//图的当前顶点数和边数/弧数 
}MGraph;
//--------------------------------------------------------------------------------------
typedef int ElemType;
#define MaxSize 10				//定义栈中元素的最大个数 
typedef struct
{
	ElemType data[MaxSize];		//静态数组存放栈中元素 
	int top;					//栈顶指针 
 }SqStack;
 

//----------------------------------------------------------------------------------------
void Init_edge(MGraph &G);
void Graph_input(MGraph &G);
void Graph_print(MGraph G);
//----------------------------------------------------------------------------------------
int FirstNeighbor_xj(MGraph G,int x);
int NextNeighbor_xj(MGraph G,int x,int y);
void Init_indegree_print(MGraph G);
bool TopologicalSort(MGraph G); 
//----------------------------------------------------------------------------------------
int FirstNeighbor_jx(MGraph G,int x);
int NextNeighbor_jx(MGraph G,int x,int y);
void Init_outdegree_print(MGraph G);
bool ReTopologicalSort(MGraph G); 
//----------------------------------------------------------------------------------------
void InitStack(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool StackEmpty(SqStack S);
bool StackFull(SqStack S); 
//----------------------------------------------------------------------------------------
void seek_ve(MGraph G);
void seek_vl(MGraph G);
void EWL(MGraph G);
void seek_e(MGraph G);
void seek_l(MGraph G); 
void seek_d(MGraph G);
void Critical_Activity_and_critical_path(MGraph G);
//----------------------------------------------------------------------------------------
int indegree[MaxVertexNum];		//indegree[i] 顶点i的入度
int Topo_Order[MaxVertexNum];		//记录拓扑序列Topo_Order[1]---Topo_Order[count]; 
SqStack S_in;					//保存入度为0的顶点（也可用队列） 

int outdegree[MaxVertexNum];		//outdegree[i] 顶点i的出度
int ReTopo_Order[MaxVertexNum];		//记录逆拓扑序列ReTopo_Order[1]---ReTopo_Order[count]; 
SqStack S_out;					//保存出度为0的顶点（也可用队列） 

int ve[MaxVertexNum];	//各个顶点(事件)的最早发生时间 
int vl[MaxVertexNum];	//各个顶点(事件)的最迟发生时间 

int e[MaxArcNum];	//各个边(活动)的最早发生时间 
int l[MaxArcNum]; 	//各个边(活动)的最迟发生时间 

int d[MaxArcNum];	//各个边(活动)的时间余量 

typedef struct 	ArcNode			//这里不能写 Edge_Weight_List 了 
{
	int k;	//弧尾 
	int j;	//弧头		k-->j
	int weight;	//权重 
}ArcNode,Edge_Weight_List[MaxArcNum];	//边权表 

Edge_Weight_List E;			//ArcNode E[MaxArcNum]; 
//----------------------------------------------------------------------------------------
int main()
{
	MGraph G;
	//printf("%d",sizeof(G));
	Graph_input(G);
	//Graph_print(G);
	Init_indegree_print(G);
	if ( TopologicalSort(G) )
	{
		printf("拓扑排序成功,拓扑序列为:");
		for (int i=1; i<=G.vexnum; i++)
			printf("%d ",Topo_Order[i]);
		printf("\n");
	}
	else printf("拓扑排序失败，有向图中有回路\n");
	
	Init_outdegree_print(G);
	if ( ReTopologicalSort(G) )
	{
		printf("逆拓扑排序成功,逆拓扑序列为:");
		for (int i=1; i<=G.vexnum; i++)
			printf("%d ",ReTopo_Order[i]);
		printf("\n");
	}
	else printf("逆拓扑排序失败，有向图中有回路\n");
	
	//1.按照拓扑排序序列的顺序，求各个顶点的最早发生时间ve[]
	seek_ve(G); 
	
	//2.按照逆拓扑排序序列的顺序，求各个顶点的最迟发生时间vl[]
	seek_vl(G);
	
	//由邻接矩阵得到顶点序号单增的边权表E[]，有边序列依据 
	EWL(G); 
	
	//3.按照边序列，由顶点的ve[]求所有边(活动)的最早发生时间e[] 
	seek_e(G);
	
	//4.按照边序列，由顶点的vl[]和边权求所有边(活动)的最迟发生时间l[] 
	seek_l(G); 
	
	//5.按照边序列，由边的e[]和l[]求边(活动)的时间余量d[]
	seek_d(G);
	
	//写出关键活动和关键路径 
	Critical_Activity_and_critical_path(G);
	
	return 0; 
}
//----------------------------------------------------------------------------------------
void Init_edge(MGraph &G)
{
	for (int i=1; i<=MaxVertexNum-1; i++)
		for (int j=1; j<=MaxVertexNum-1; j++)
		{
			if (i==j)	
				G.Edge[i][j]=0;
			else 
				G.Edge[i][j]=INT_MAX; 
		}
}

void Graph_input(MGraph &G)
{
	FILE *fp;
	fp=fopen("Z:\\CriticalPath_input.txt","r");
	fscanf(fp,"%d",&G.arcnum);	//printf("%d",G.arcnum);
	int x1,x2,value,vemax=0;
	Init_edge(G);
	for (int i=1; i<=G.arcnum; i++)	
	{
		fscanf(fp,"%d %d %d",&x1,&x2,&value);	//printf("%d\n",value);
		G.Edge[x1][x2]=value;
		if (x1>vemax)	vemax=x1;
		if (x2>vemax)	vemax=x2;
	}
	G.vexnum=vemax;
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
//----------------------------------------------------------------------------------------
int FirstNeighbor_xj(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)     
		if (G.Edge[x][j]>0 && G.Edge[x][j]<INT_MAX)	//x行找 出边<x,j>	
			return j;
	return -1;	//x没有邻接点
}

int NextNeighbor_xj(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++)	
		if (G.Edge[x][j]>0 && G.Edge[x][j]<INT_MAX)	//x行找 出边<x,j>
			return j;
	return -1; 
}

void Init_indegree_print(MGraph G)
{
	memset(indegree,0,sizeof(indegree));	//先清零 
	for (int i=1; i<=G.vexnum; i++)
		for (int j=1; j<=G.vexnum; j++)
		{
			//printf("%d",G.Edge[j][i]);
			if (G.Edge[j][i]>0 && G.Edge[j][i]<INT_MAX)
				indegree[i]++;		//第i列正数个数是 顶点i的入度 
		}
	memset(Topo_Order,-1,sizeof(Topo_Order));
//	for (int i=1; i<=G.vexnum; i++)
//		printf("%d %d\n",indegree[i],print[i]);
}

bool TopologicalSort(MGraph G)
{
	InitStack(S_in);		//初始化栈，存储入度为0的顶点
	for (int i=1; i<=G.vexnum; i++)
		if (indegree[i]==0)
			Push(S_in,i);		//将所有入度为0的顶点进栈
	int count=0;			//计数，记录当前已经输出的顶点数 
	int i;
	while (!StackEmpty(S_in))		//栈不空，则存在入度为0的顶点 
	{
		Pop(S_in,i);			//栈顶元素出栈 
		count++;
		Topo_Order[count]=i;		//输出顶点i 
		for (int p=FirstNeighbor_xj(G,i); p>0; p=NextNeighbor_xj(G,i,p))
		{//将所有i指向的顶点的入度减1，并且将入度减为0的顶点压入栈S 
			int v=p;
			if (!(--indegree[v]))
				Push(S_in,v);		//入度为0，则入栈 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//排序失败，有向图中有回路 
	else
		return true;		//拓扑排序成功 
 } 
//---------------------------------------------------------------------------------------- 
int FirstNeighbor_jx(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)   
		if (G.Edge[j][x]>0 && G.Edge[j][x]<INT_MAX)	//入边<j,x>	
			return j;
	return -1;	//x没有邻接点
}

int NextNeighbor_jx(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++)	 
		if (G.Edge[j][x]>0 && G.Edge[j][x]<INT_MAX)	//入边<j,x>
			return j;
	return -1; 
}

void Init_outdegree_print(MGraph G)
{
	memset(outdegree,0,sizeof(outdegree));	//先清零 
	for (int i=1; i<=G.vexnum; i++)
		for (int j=1; j<=G.vexnum; j++)
		{
			//printf("%d",G.Edge[j][i]);
			if (G.Edge[i][j]>0 && G.Edge[i][j]<INT_MAX)
				outdegree[i]++;		//第i行正数个数是 顶点i的出度 
		}
	memset(ReTopo_Order,-1,sizeof(ReTopo_Order));
//	for (int i=1; i<=G.vexnum; i++)
//		printf("%d %d\n",outdegree[i],ReTopo_Order[i]);
}

bool ReTopologicalSort(MGraph G)
{
	InitStack(S_out);		//初始化栈，存储出度为0的顶点
	for (int i=1; i<=G.vexnum; i++)
		if (outdegree[i]==0)
			Push(S_out,i);		//将所有出度为0的顶点进栈
	int count=0;			//计数，记录当前已经输出的顶点数 
	int i;
	while (!StackEmpty(S_out))		//栈不空，则存在入度为0的顶点 
	{
		Pop(S_out,i);			//栈顶元素出栈 
		count++;
		ReTopo_Order[count]=i;		//输出顶点i 
		for (int p=FirstNeighbor_jx(G,i); p>0; p=NextNeighbor_jx(G,i,p))	//若编号从0开始，必须>=0 
		{//将所有指向i的顶点的出度减1，若减为0则压入栈S 
			int v=p;
			if (!(--outdegree[v]))
				Push(S_out,v);		//出度为0，则入栈 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//逆排序失败，有向图中有回路 
	else
		return true;		//逆拓扑排序成功 
 } 
//----------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------
void seek_ve(MGraph G)
{
	memset(ve,0,sizeof(ve));	//初始化ve为最小时刻0 
	ve[Topo_Order[1]]=0;			//ve(源点)=0 		源点是拓扑第一个 
	for (int i=2; i<=G.vexnum; i++)		//拓扑序列第二个到最后一个 
	{
		int k=Topo_Order[i];   //点vk 
		for (int j=1; j<=G.vexnum; j++)	//点vk的最早发生时间从前驱算 
		{
			if (G.Edge[j][k]>0 && G.Edge[j][k]<INT_MAX) //vj是vk的前驱   <vj,vk> 
				ve[k]=ve[j]+G.Edge[j][k] > ve[k] ? ve[j]+G.Edge[j][k] : ve[k];
		}		//ve(k) = Max{ ve(j) + Weight(vk,vj) }
	}
	printf("ve[1--6]:");
	for (int i=1; i<=G.vexnum; i++)
		printf("%d ",ve[i]);
	printf("\n");
}

void seek_vl(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)
		vl[i]=INT_MAX; 	//初始化vl为最晚时刻INT_MAX 
	vl[ReTopo_Order[1]]=ve[ReTopo_Order[1]];	//vl(汇点)=ve(汇点)		汇点是逆拓扑第一个 
	for (int i=2; i<=G.vexnum; i++)		//逆拓扑序列第二个到最后一个
	{
		int k=ReTopo_Order[i];   //点vk
		for (int j=1; j<=G.vexnum; j++)	//点vk的最迟发生时间从后继算
		{
			if (G.Edge[k][j]>0 && G.Edge[k][j]<INT_MAX) //vj是vk的后继   <vk,vj> 
				vl[k]=vl[j]-G.Edge[k][j] < vl[k] ? vl[j]-G.Edge[k][j] : vl[k];
		 } 		//vl(k)=Min{vl(j)-Weight(vk,vj)}
	 } 
	printf("vl[1--6]:");
	for (int i=1; i<=G.vexnum; i++)
		printf("%d ",vl[i]);
	printf("\n");
}

void EWL(MGraph G)		//边权表 
{
	int count=0;		//当前活动 
	for (int k=1; k<=G.vexnum; k++)
		for (int j=1; j<=G.vexnum; j++) 
			if (G.Edge[k][j]>0 && G.Edge[k][j]<INT_MAX) //边<vk,vj>表示活动ai
			{
				count++;
				E[count].weight=G.Edge[k][j]; 
				E[count].k=k;
				E[count].j=j;
			}
	printf("\nE[1--8]:\n");
	for (int i=1; i<=G.arcnum; i++)
		printf("a[%d]:%d %d %d\n",i,E[i].k,E[i].j,E[i].weight);
	printf("\n");
}

void seek_e(MGraph G)	//邻接矩阵存储，一行行遍历可以保证边的顶点编号单调增 ，从而对应边 
{
	for (int i=1; i<=G.arcnum; i++)	//边<vk,vj>表示活动ai
		e[i]=ve[ E[i].k ];	//e(i)=ve(k)
	printf("e[1--8]:");
	for (int i=1; i<=G.arcnum; i++)
		printf("%d ",e[i]);
	printf("\n");
}

void seek_l(MGraph G)	//邻接矩阵存储，一行行遍历可以保证边的顶点编号单调增 ，从而对应边 
{
	for (int i=1; i<=G.arcnum; i++)	//边<vk,vj>表示活动ai
		l[i]=vl[ E[i].j ]-E[i].weight;	//l(i)=vl(j)-weight(vk,vj)
	printf("l[1--8]:");
	for (int i=1; i<=G.arcnum; i++)
		printf("%d ",l[i]);
	printf("\n");
}

void seek_d(MGraph G)
{
	memset(d,-1,sizeof(d)); 
	for (int i=1; i<=G.arcnum; i++)
		d[i]=l[i]-e[i];
	printf("d[1--8]:");
	for (int i=1; i<=G.arcnum; i++)
		printf("%d ",d[i]);
	printf("\n");
}

void Critical_Activity_and_critical_path(MGraph G)
{
	printf("\nCritical Activity:");
	for (int i=1; i<=G.arcnum; i++)
		if (d[i]==0)	printf("a%d  ",i);
	printf("\n"); 
	
	printf("\ncritical_path:");
	for (int i=1; i<=G.arcnum; i++)
		if (d[i]==0)	printf("V%d-->",E[i].k);
	printf("V%d",E[G.arcnum].j);
	printf("\n"); 
}
