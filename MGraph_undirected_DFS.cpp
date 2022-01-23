//����ͼG���ڽӾ���洢������������ȱ��� 			undirected graph_DFS
#include<stdio.h>
//----------------------------------------------------------------------
//�ڽӾ��󷨴洢ͼ
#define MaxVertexNum 100					//������Ŀ�����ֵ 
typedef struct
{
	char Vex[MaxVertexNum];					//����� 
	int Edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬱߱�bool �� ö������ 
	int vexnum,arcnum;						//ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;

bool visited[MaxVertexNum];			//���ʱ������ 
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
	beforeDFS(G);	printf("�Ӷ���%d�����õ���������ȱ�������:",1);	DFS(G,1);	printf("\n"); 
	beforeDFS(G);	printf("�Ӷ���%d�����õ���������ȱ�������:",2);	DFS(G,2);	printf("\n");
 	beforeDFS(G);	printf("�Ӷ���%d�����õ���������ȱ�������:",3);	DFS(G,3);	printf("\n");
	//DFSTraverse(G);		//ͼG�Ƿ���ͨͼ���� 
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

//DFS֮ǰ��Ҫ��ʼ��������� 
void beforeDFS(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//����Ŵ�1��ʼ
		visited[i]=false;		//���ʱ�������ʼ��
}

void visit(int v)
{
	printf("%d ",v);
}

//������ȱ���
void DFS(MGraph G,int v)	//�Ӷ���v������������ȱ���ͼG 
{
	visit(v);
	visited[v]=true;
	for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			if (!visited[w])	//wΪv����δ���ʵ��ڽӶ��� 
			{
				DFS(G,w);
			 }//if  
}

void DFSTraverse(MGraph G)	//��ͼG����������ȱ��� 
{
	beforeDFS(G);
	for (int i=1; i<=G.vexnum; i++)		//�Ӷ���1��ʼ���� 
		if (!visited[i])
			DFS(G,i);
}

//��ͼG�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���š���xû���ڽӵ��ͼ�в�����x���򷵻�-1 
int FirstNeighbor(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)
		if (G.Edge[x][j]==1)	//�б�(x,j)	
			return j;
	return -1;	//xû���ڽӵ�
}

//����ͼG�ж���y�Ƕ���x��һ���ڽӵ㣬���س�y֮�ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1 
int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++ )
		if (G.Edge[x][j]==1)	//�б�(x,j)
			return j;
	return -1; 
}
