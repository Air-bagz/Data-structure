//����ͼG���ڽӾ���洢�����й�����ȱ��� 			undirected graph
#include<stdio.h>
//----------------------------------------------------------------------
#define MaxSize 100				//���������Ԫ�ص������� 

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];		//�þ�̬�����Ŷ���Ԫ�� 
	int front,rear; 			//��ͷָ��Ͷ�βָ�� 
}SqQueue;

SqQueue Q;		//ȫ�ֱ�����ÿ�δ��� 
//-----------------------------------------------------------------------
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
void beforeBFS(MGraph G); 
void visit(int v);
void BFS(MGraph G,int v);
void BFSTraverse(MGraph G);
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
	beforeBFS(G);	printf("�Ӷ���%d�����õ��Ĺ�����ȱ�������:",1);	BFS(G,1);	printf("\n"); 
	beforeBFS(G);	printf("�Ӷ���%d�����õ��Ĺ�����ȱ�������:",2);	BFS(G,2);	printf("\n");
 	beforeBFS(G);	printf("�Ӷ���%d�����õ��Ĺ�����ȱ�������:",3);	BFS(G,3);	printf("\n");
	//BFSTraverse(G);		//ͼG�Ƿ���ͨͼ���� 
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

//BFS֮ǰ��Ҫ��ʼ���������кͱ������ 
void beforeBFS(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//����Ŵ�1��ʼ
		visited[i]=false;		//���ʱ�������ʼ��
	InitQueue(Q);		//��ʼ����������Q
}

void visit(int v)
{
	printf("%d ",v);
}

//������ȱ���
void BFS(MGraph G,int v) //�Ӷ���v������������ȱ���ͼG 
{
	 
	visit(v);			//���ʳ�ʼ����v 
	visited[v]=true;	//��v���ѷ��ʱ�� 
	EnQueue(Q,v);		//����v�����Q 
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,v);	//����v������ 
		for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			//���v�����ڽӵ�
			if (!visited[w])	//wΪv����δ���ʵ��ڽӶ��� 
			{
				visit(w);		//���ʶ���w 
				visited[w]=true;//��w���ѷ��ʱ�� 
				EnQueue(Q,w);	//����w�����Q 
			 }//if 
	}//while
}

void BFSTraverse(MGraph G)	//��ͼG���й�����ȱ��� 
{
	beforeBFS(G);	
	for (int i=1; i<=G.vexnum; i++)	//��1�Ŷ��㿪ʼ���� 
		if (!visited[i])	//��ÿ����ͨ��������һ��BFS 
			BFS(G,i); 		//viδ���ʹ�����vi��ʼBFS 
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

//---------------------------------------------------------------
void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}

bool EnQueue(SqQueue &Q,ElemType x)		//��� 
{
	if (QueueFull(Q))	return false;		//�������� 
	Q.data[Q.rear]=x;				//rearָ����һ��Ӧ�ò����λ�� 
	Q.rear=(Q.rear+1)%MaxSize;		//��βָ����ƣ�[0,1,...,MaxSize-1]��״ 
	return true;
}

bool DeQueue(SqQueue &Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;		//�ӿձ���
	x=Q.data[Q.front];				//frontָ���ͷԪ�� 
	Q.front=(Q.front+1)%MaxSize; 	//��ͷָ����ƣ���״ 
	return true;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.front)	return true;	//�ӿ����� 
	else return false;
}

bool QueueFull(SqQueue Q)
{
	if ( (Q.rear+1)%MaxSize==Q.front )	return true;	//��������	����һ�� 
	else return false;
 } 
