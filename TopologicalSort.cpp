//��������	�ڽӱ�+ջ/���� 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
//----------------------------------------------------------------------------------------
typedef int ElemType;
#define MaxSize 100				//����ջ��Ԫ�ص������� 
typedef struct
{
	ElemType data[MaxSize];		//��̬������ջ��Ԫ�� 
	int top;					//ջ��ָ�� 
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

int indegree[MaxVertexNum];		//indegree[i] ����i�����
int print[MaxVertexNum];		//��¼��������print[1]---print[count]; 
SqStack S;					//�����Ϊ0�Ķ��㣨Ҳ���ö��У� 

int main()
{
	MGraph G;
	Graph_input(G);		//pdf����
	//Graph_print(G);
	ALGraph GG;		GG.vexnum=G.vexnum;
	MGraph_to_ALGraph(G,GG);
	//ALGraph_print(GG);
	Init_indegree_print(G);
	if ( TopologicalSort(GG) )
	{
		printf("��������ɹ�,��������Ϊ:");
		for (int i=0; i<GG.vexnum; i++)
			printf("%d ",print[i]);
	}
	else printf("��������ʧ�ܣ�����ͼ���л�·");
	return 0; 
 } 

void Graph_input(MGraph &G)
{
	FILE *fp;
	fp=fopen("Z:\\Topo_Order.txt","r");
	fscanf(fp,"%d",&G.vexnum);
	for (int i=0; i<G.vexnum; i++)		//ע�⣬��������Ǵ�0��ʼ 
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
	printf("�����____�߱�\n");
	for (int i=0; i<GG.vexnum; i++)		//0�� 
	{
		printf("[%d]:",GG.vertexs[i].data);
			ArcNode *p;
			for (p=GG.vertexs[i].firstarc; p!=NULL; p=p->nextarc)
				printf("--->%d",p->adjvex);
		printf("\n");
	}
}

//��ͼG�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���š���xû���ڽӵ��ͼ�в�����x���򷵻�-1 
int FirstNeighbor(MGraph G,int x)
{
	for (int j=0; j<G.vexnum; j++)    //0�� 
		if (G.Edge[x][j]==1)	//�б�(x,j)	
			return j;
	return -1;	//xû���ڽӵ�
}

//����ͼG�ж���y�Ƕ���x��һ���ڽӵ㣬���س�y֮�ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1 
int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<G.vexnum; j++ )	//0�� 
		if (G.Edge[x][j]==1)	//�б�(x,j)
			return j;
	return -1; 
}

void MGraph_to_ALGraph(MGraph G,ALGraph &GG)	//�൱�ڲ���ͷ����β�巨���ȵ��������һ���� 
{
	ArcNode *r;		//βָ�� 
	for (int i=0; i<G.vexnum; i++)		//0�� 
		{
			GG.vertexs[i].data=i;
			GG.vertexs[i].firstarc=NULL;
			int w=FirstNeighbor(G,i);
			if	(w>0)	
			{
				GG.vertexs[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
				GG.vertexs[i].firstarc->adjvex=w;
				GG.vertexs[i].firstarc->nextarc=NULL;	//�������һ���� 
				r=GG.vertexs[i].firstarc;			//βָ���ʼ 
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
	memset(indegree,0,G.vexnum);	//������ 
	for (int i=0; i<G.vexnum; i++)
		for (int j=0; j<G.vexnum; j++)
			indegree[i]=indegree[i]+G.Edge[j][i];	//��i��֮���� ����i����� 
	memset(print,-1,G.vexnum);
	//for (int i=0; i<G.vexnum; i++)
	//	printf("%d %d\n",indegree[i],print[i]);
}

bool TopologicalSort(ALGraph G)
{
	InitStack(S);		//��ʼ��ջ���洢���Ϊ0�Ķ���
	for (int i=0; i<G.vexnum; i++)
		if (indegree[i]==0)
			Push(S,i);		//���������Ϊ0�Ķ����ջ
	int count=0;			//��������¼��ǰ�Ѿ�����Ķ����� 
	int i;
	while (!StackEmpty(S))		//ջ���գ���������Ϊ0�Ķ��� 
	{
		Pop(S,i);			//ջ��Ԫ�س�ջ 
		print[count++]=i;		//�������i 
		for (ArcNode *p=G.vertexs[i].firstarc; p; p=p->nextarc)
		{//������iָ��Ķ������ȼ�1�����ҽ���ȼ�Ϊ0�Ķ���ѹ��ջS 
			int v=p->adjvex;
			if (!(--indegree[v]))
				Push(S,v);		//���Ϊ0������ջ 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//����ʧ�ܣ�����ͼ���л�· 
	else
		return true;		//��������ɹ� 
 } 
 
void InitStack(SqStack &S)		//��ʼ��ջ 
{
	S.top=-1;		//��ʼ��ջ��ָ�� 
}

bool Push(SqStack &S,ElemType x)		//��ջ���� 
{
	if ( StackFull(S) )	return false;		//ջ��������
	S.top=S.top+1;			//ָ����+1 
	S.data[S.top]=x;		//��Ԫ����ջ				
	return true; 			//<=> S.data[++S.top]=x;
 } 

bool Pop(SqStack &S,ElemType &x)		//��ջ���� 
{
	if ( StackEmpty(S) )	return false;	//ջ�գ�����
	x=S.data[S.top];		//ջ��Ԫ���ȳ�ջ 
	S.top=S.top-1;			//ָ���ټ�1 
	return true;			//<=> x=S.data[S.top--]; 
}

bool StackEmpty(SqStack S)		//�ж�ջ�� 
{
	if (S.top==-1)	return true;	//ջ�� 
	else return false;			//���� 
}

bool StackFull(SqStack S)		//�ж�ջ�� 
{
	if (S.top==MaxSize-1)	return true;	//ջ�� 
	else return false;			//���� 
}
