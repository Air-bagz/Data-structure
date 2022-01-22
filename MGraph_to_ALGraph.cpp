//�ڽӾ������������ת��δ�ڽӱ������߱�ʹ�ú�巨�������ڽӶ�����ŵ��� 
//MGraph G----->ALGraph GG
#include<stdio.h>
#include<stdlib.h>
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

void Graph_input(MGraph &G);
void Graph_print(MGraph G);
int FirstNeighbor(MGraph G,int x);
int NextNeighbor(MGraph G,int x,int y);
void MGraph_to_ALGraph(MGraph G,ALGraph &GG);
void Convert(ALGraph G,int n,int arcs[10][10]);  //����p214

int main()
{
	MGraph G;
	Graph_input(G);
	//Graph_print(G);
	ALGraph GG;		GG.vexnum=G.vexnum;
	MGraph_to_ALGraph(G,GG);
	printf("�����____�߱�\n");
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

void MGraph_to_ALGraph(MGraph G,ALGraph &GG)	//�൱�ڲ���ͷ����β�巨���ȵ��������һ���� 
{
	ArcNode *r;		//βָ�� 
	for (int i=1; i<=G.vexnum; i++)
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

void Convert(ALGraph G,int n,int arcs[10][10])	//�ο�����p214 
{
	//���㷨���ڽӱ�ʽ��ʾ��ͼGת��Ϊ�ڽӾ���arcs
	ArcNode *p;
	for (int i=1; i<=n; i++)		//���α������������Ϊͷ�ı�����
	{
		p=(G.vertexs[i].firstarc);		//ȡ������i�ĵ�һ������
		while (p!=NULL)			//���������� 
		{
			arcs[i][p->adjvex]=1;//ȡ��һ������ 	G.Edge[][]
			p=p->nextarc;
		 }//while 
	}//for
}
