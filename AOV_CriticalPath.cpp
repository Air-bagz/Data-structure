//Critical Path _ AOV
#include<stdio.h>
#include<limits.h>
#include<string.h>		//memset
//------------------------------------------------------------------------------------
//�ڽӾ��󷨴洢��Ȩͼ������ 
#define MaxVertexNum 10				//������Ŀ�����ֵ 
#define MaxArcNum 34		//����Ŀ�����ֵ 

typedef char VertexType;					//������������� 
typedef int EdgeType; 						//��Ȩͼ�б���Ȩֵ���������� 
typedef struct
{
	VertexType Vex[MaxVertexNum];					//���� 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];		//�ߵ�Ȩ 
	int vexnum,arcnum;								//ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;
//--------------------------------------------------------------------------------------
typedef int ElemType;
#define MaxSize 10				//����ջ��Ԫ�ص������� 
typedef struct
{
	ElemType data[MaxSize];		//��̬������ջ��Ԫ�� 
	int top;					//ջ��ָ�� 
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
int indegree[MaxVertexNum];		//indegree[i] ����i�����
int Topo_Order[MaxVertexNum];		//��¼��������Topo_Order[1]---Topo_Order[count]; 
SqStack S_in;					//�������Ϊ0�Ķ��㣨Ҳ���ö��У� 

int outdegree[MaxVertexNum];		//outdegree[i] ����i�ĳ���
int ReTopo_Order[MaxVertexNum];		//��¼����������ReTopo_Order[1]---ReTopo_Order[count]; 
SqStack S_out;					//�������Ϊ0�Ķ��㣨Ҳ���ö��У� 

int ve[MaxVertexNum];	//��������(�¼�)�����緢��ʱ�� 
int vl[MaxVertexNum];	//��������(�¼�)����ٷ���ʱ�� 

int e[MaxArcNum];	//������(�)�����緢��ʱ�� 
int l[MaxArcNum]; 	//������(�)����ٷ���ʱ�� 

int d[MaxArcNum];	//������(�)��ʱ������ 

typedef struct 	ArcNode			//���ﲻ��д Edge_Weight_List �� 
{
	int k;	//��β 
	int j;	//��ͷ		k-->j
	int weight;	//Ȩ�� 
}ArcNode,Edge_Weight_List[MaxArcNum];	//��Ȩ�� 

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
		printf("��������ɹ�,��������Ϊ:");
		for (int i=1; i<=G.vexnum; i++)
			printf("%d ",Topo_Order[i]);
		printf("\n");
	}
	else printf("��������ʧ�ܣ�����ͼ���л�·\n");
	
	Init_outdegree_print(G);
	if ( ReTopologicalSort(G) )
	{
		printf("����������ɹ�,����������Ϊ:");
		for (int i=1; i<=G.vexnum; i++)
			printf("%d ",ReTopo_Order[i]);
		printf("\n");
	}
	else printf("����������ʧ�ܣ�����ͼ���л�·\n");
	
	//1.���������������е�˳���������������緢��ʱ��ve[]
	seek_ve(G); 
	
	//2.�����������������е�˳��������������ٷ���ʱ��vl[]
	seek_vl(G);
	
	//���ڽӾ���õ�������ŵ����ı�Ȩ��E[]���б��������� 
	EWL(G); 
	
	//3.���ձ����У��ɶ����ve[]�����б�(�)�����緢��ʱ��e[] 
	seek_e(G);
	
	//4.���ձ����У��ɶ����vl[]�ͱ�Ȩ�����б�(�)����ٷ���ʱ��l[] 
	seek_l(G); 
	
	//5.���ձ����У��ɱߵ�e[]��l[]���(�)��ʱ������d[]
	seek_d(G);
	
	//д���ؼ���͹ؼ�·�� 
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
		if (G.Edge[x][j]>0 && G.Edge[x][j]<INT_MAX)	//x���� ����<x,j>	
			return j;
	return -1;	//xû���ڽӵ�
}

int NextNeighbor_xj(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++)	
		if (G.Edge[x][j]>0 && G.Edge[x][j]<INT_MAX)	//x���� ����<x,j>
			return j;
	return -1; 
}

void Init_indegree_print(MGraph G)
{
	memset(indegree,0,sizeof(indegree));	//������ 
	for (int i=1; i<=G.vexnum; i++)
		for (int j=1; j<=G.vexnum; j++)
		{
			//printf("%d",G.Edge[j][i]);
			if (G.Edge[j][i]>0 && G.Edge[j][i]<INT_MAX)
				indegree[i]++;		//��i������������ ����i����� 
		}
	memset(Topo_Order,-1,sizeof(Topo_Order));
//	for (int i=1; i<=G.vexnum; i++)
//		printf("%d %d\n",indegree[i],print[i]);
}

bool TopologicalSort(MGraph G)
{
	InitStack(S_in);		//��ʼ��ջ���洢���Ϊ0�Ķ���
	for (int i=1; i<=G.vexnum; i++)
		if (indegree[i]==0)
			Push(S_in,i);		//���������Ϊ0�Ķ����ջ
	int count=0;			//��������¼��ǰ�Ѿ�����Ķ����� 
	int i;
	while (!StackEmpty(S_in))		//ջ���գ���������Ϊ0�Ķ��� 
	{
		Pop(S_in,i);			//ջ��Ԫ�س�ջ 
		count++;
		Topo_Order[count]=i;		//�������i 
		for (int p=FirstNeighbor_xj(G,i); p>0; p=NextNeighbor_xj(G,i,p))
		{//������iָ��Ķ������ȼ�1�����ҽ���ȼ�Ϊ0�Ķ���ѹ��ջS 
			int v=p;
			if (!(--indegree[v]))
				Push(S_in,v);		//���Ϊ0������ջ 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//����ʧ�ܣ�����ͼ���л�· 
	else
		return true;		//��������ɹ� 
 } 
//---------------------------------------------------------------------------------------- 
int FirstNeighbor_jx(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)   
		if (G.Edge[j][x]>0 && G.Edge[j][x]<INT_MAX)	//���<j,x>	
			return j;
	return -1;	//xû���ڽӵ�
}

int NextNeighbor_jx(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++)	 
		if (G.Edge[j][x]>0 && G.Edge[j][x]<INT_MAX)	//���<j,x>
			return j;
	return -1; 
}

void Init_outdegree_print(MGraph G)
{
	memset(outdegree,0,sizeof(outdegree));	//������ 
	for (int i=1; i<=G.vexnum; i++)
		for (int j=1; j<=G.vexnum; j++)
		{
			//printf("%d",G.Edge[j][i]);
			if (G.Edge[i][j]>0 && G.Edge[i][j]<INT_MAX)
				outdegree[i]++;		//��i������������ ����i�ĳ��� 
		}
	memset(ReTopo_Order,-1,sizeof(ReTopo_Order));
//	for (int i=1; i<=G.vexnum; i++)
//		printf("%d %d\n",outdegree[i],ReTopo_Order[i]);
}

bool ReTopologicalSort(MGraph G)
{
	InitStack(S_out);		//��ʼ��ջ���洢����Ϊ0�Ķ���
	for (int i=1; i<=G.vexnum; i++)
		if (outdegree[i]==0)
			Push(S_out,i);		//�����г���Ϊ0�Ķ����ջ
	int count=0;			//��������¼��ǰ�Ѿ�����Ķ����� 
	int i;
	while (!StackEmpty(S_out))		//ջ���գ���������Ϊ0�Ķ��� 
	{
		Pop(S_out,i);			//ջ��Ԫ�س�ջ 
		count++;
		ReTopo_Order[count]=i;		//�������i 
		for (int p=FirstNeighbor_jx(G,i); p>0; p=NextNeighbor_jx(G,i,p))	//����Ŵ�0��ʼ������>=0 
		{//������ָ��i�Ķ���ĳ��ȼ�1������Ϊ0��ѹ��ջS 
			int v=p;
			if (!(--outdegree[v]))
				Push(S_out,v);		//����Ϊ0������ջ 
		}
	 } //while
	 if (count<G.vexnum)
	 	return false;		//������ʧ�ܣ�����ͼ���л�· 
	else
		return true;		//����������ɹ� 
 } 
//----------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------
void seek_ve(MGraph G)
{
	memset(ve,0,sizeof(ve));	//��ʼ��veΪ��Сʱ��0 
	ve[Topo_Order[1]]=0;			//ve(Դ��)=0 		Դ�������˵�һ�� 
	for (int i=2; i<=G.vexnum; i++)		//�������еڶ��������һ�� 
	{
		int k=Topo_Order[i];   //��vk 
		for (int j=1; j<=G.vexnum; j++)	//��vk�����緢��ʱ���ǰ���� 
		{
			if (G.Edge[j][k]>0 && G.Edge[j][k]<INT_MAX) //vj��vk��ǰ��   <vj,vk> 
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
		vl[i]=INT_MAX; 	//��ʼ��vlΪ����ʱ��INT_MAX 
	vl[ReTopo_Order[1]]=ve[ReTopo_Order[1]];	//vl(���)=ve(���)		����������˵�һ�� 
	for (int i=2; i<=G.vexnum; i++)		//���������еڶ��������һ��
	{
		int k=ReTopo_Order[i];   //��vk
		for (int j=1; j<=G.vexnum; j++)	//��vk����ٷ���ʱ��Ӻ����
		{
			if (G.Edge[k][j]>0 && G.Edge[k][j]<INT_MAX) //vj��vk�ĺ��   <vk,vj> 
				vl[k]=vl[j]-G.Edge[k][j] < vl[k] ? vl[j]-G.Edge[k][j] : vl[k];
		 } 		//vl(k)=Min{vl(j)-Weight(vk,vj)}
	 } 
	printf("vl[1--6]:");
	for (int i=1; i<=G.vexnum; i++)
		printf("%d ",vl[i]);
	printf("\n");
}

void EWL(MGraph G)		//��Ȩ�� 
{
	int count=0;		//��ǰ� 
	for (int k=1; k<=G.vexnum; k++)
		for (int j=1; j<=G.vexnum; j++) 
			if (G.Edge[k][j]>0 && G.Edge[k][j]<INT_MAX) //��<vk,vj>��ʾ�ai
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

void seek_e(MGraph G)	//�ڽӾ���洢��һ���б������Ա�֤�ߵĶ����ŵ����� ���Ӷ���Ӧ�� 
{
	for (int i=1; i<=G.arcnum; i++)	//��<vk,vj>��ʾ�ai
		e[i]=ve[ E[i].k ];	//e(i)=ve(k)
	printf("e[1--8]:");
	for (int i=1; i<=G.arcnum; i++)
		printf("%d ",e[i]);
	printf("\n");
}

void seek_l(MGraph G)	//�ڽӾ���洢��һ���б������Ա�֤�ߵĶ����ŵ����� ���Ӷ���Ӧ�� 
{
	for (int i=1; i<=G.arcnum; i++)	//��<vk,vj>��ʾ�ai
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
