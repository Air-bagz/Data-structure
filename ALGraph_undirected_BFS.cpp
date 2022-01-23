//����ͼG���ڽӾ���洢��ת��Ϊ�ڽӱ��ٽ��й�����ȱ��� 			undirected graph
#include<stdio.h>
#include<stdlib.h>
//------------------------------------------------------------------------------------
#define MaxSize 100				//���������Ԫ�ص������� 

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];		//�þ�̬�����Ŷ���Ԫ�� 
	int front,rear; 			//��ͷָ��Ͷ�βָ�� 
}SqQueue;

SqQueue Q;		//ȫ�ֱ�����ÿ�δ��� 

#define MaxVertexNum 100					//������Ŀ�����ֵ 
//------------------------------------------------------------------------------------
//�ڽӾ��󷨴洢ͼ
typedef struct
{
	char Vex[MaxVertexNum];					//����� 
	int Edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬱߱�bool �� ö������ 
	int vexnum,arcnum;						//ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;
//--------------------------------------------------------------------------------------
//�ڽӱ� 
typedef int VertexType;			//������������� 
typedef int Infotype; 				//��Ȩͼ�б���Ȩֵ���������� 
//�߱��� 
typedef struct ArcNode		
{
	int adjvex;				//�û���ָ��Ķ����λ�� 
	struct ArcNode *nextarc;//ָ����һ������ָ�� 
	Infotype info;		//���ı�Ȩֵ 
}ArcNode; 
//������� 
typedef struct VNode		
{
	VertexType data;		//������Ϣ 
	ArcNode *firstarc;		//ָ���һ�������ö���Ļ���ָ�� 
 }VNode,AdjList[MaxVertexNum];
//���ڽӱ�洢��ͼ
typedef struct
{
	AdjList vertexs;	//vertices		vertexes		<=> VNode vertexs[MaxVertexNum];
	int vexnum,arcnum;	//ͼ�Ķ������ͻ��� 
}ALGraph;

bool visited[MaxVertexNum];			//���ʱ������ 
ArcNode *r;		//βָ�� 
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
	beforeBFS(GG);	printf("�Ӷ���%d�����õ��Ĺ�����ȱ�������:",1);	BFS(GG,1);	printf("\n"); 
	beforeBFS(GG);	printf("�Ӷ���%d�����õ��Ĺ�����ȱ�������:",2);	BFS(GG,2);	printf("\n");
 	beforeBFS(GG);	printf("�Ӷ���%d�����õ��Ĺ�����ȱ�������:",3);	BFS(GG,3);	printf("\n");
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

//��ͼG�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���š���xû���ڽӵ��ͼ�в�����x���򷵻�-1 
int AM_FirstNeighbor(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)
		if (G.Edge[x][j]==1)	//�б�(x,j)	
			return j;
	return -1;	//xû���ڽӵ�
}

//����ͼG�ж���y�Ƕ���x��һ���ڽӵ㣬���س�y֮�ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1 
int AM_NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++ )
		if (G.Edge[x][j]==1)	//�б�(x,j)
			return j;
	return -1; 
}

void MGraph_to_ALGraph(MGraph G,ALGraph &GG)	//�൱�ڲ���ͷ����β�巨���ȵ��������һ���� 
{
	ArcNode *r;		//βָ��
	for (int i=1; i<=G.vexnum; i++)
		{
			GG.vertexs[i].data=i;
			GG.vertexs[i].firstarc=NULL;
			int w=AM_FirstNeighbor(G,i);
			if	(w>0)	
			{
				GG.vertexs[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
				GG.vertexs[i].firstarc->adjvex=w;
				GG.vertexs[i].firstarc->nextarc=NULL;	//�������һ���� 
				r=GG.vertexs[i].firstarc;			//βָ���ʼ 
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
	printf("�����____�߱�\n");
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
	for (int i=1; i<=GG.vexnum; i++)		//����Ŵ�1��ʼ
		visited[i]=false;		//���ʱ�������ʼ��
	InitQueue(Q);		//��ʼ����������Q
}

void visit(int v)
{
	printf("%d ",v);
}

void BFS(ALGraph GG,int v)
{
	visit(v);			//���ʳ�ʼ����v 
	visited[v]=true;	//��v���ѷ��ʱ�� 
	EnQueue(Q,v);		//����v�����Q
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,v);	//����v������ 
		for (ArcNode *w=AL_FirstNeighbor(GG,v); w!=NULL; w=AL_NextNeighbor(GG,v,w))
			//���v�����ڽӵ�
			if (!visited[w->adjvex])	//wΪv����δ���ʵ��ڽӶ��� 
			{
				visit(w->adjvex);		//���ʶ���w 
				visited[w->adjvex]=true;//��w���ѷ��ʱ�� 
				EnQueue(Q,w->adjvex);	//����w�����Q 
			 }//if 
	}//while
}

void BFSTraverse(ALGraph GG)
{
	beforeBFS(GG);
	for (int i=1; i<=GG.vexnum; i++)	//��1�Ŷ��㿪ʼ���� 
		if (!visited[i])	//��ÿ����ͨ��������һ��BFS 
			BFS(GG,i); 		//viδ���ʹ�����vi��ʼBFS 
}

//��ͼG�ж���x�ĵ�һ���ڽӽ�㣬���ؽ��p������Ϊ�� 
ArcNode *AL_FirstNeighbor(ALGraph GG,int x)
{
	return GG.vertexs[x].firstarc;	
}

//ͼG�н��y�Ƕ���x��һ���ڽӵ㣬����y����һ���ڽӽ�㣬����Ϊ�� 
ArcNode *AL_NextNeighbor(ALGraph GG,int x,ArcNode *y)
{
	return y->nextarc; 
}

//-----------------------------------------------------------------------------------
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
