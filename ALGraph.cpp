//邻接表法 
#define MaxVertexNum 100					//顶点数目的最大值 
typedef char VertexType;					//顶点的数据类型 
typedef int Infotype; 						//带权图中边上权值的数据类型 
//边/弧 
typedef struct ArcNode
{
	int adjvex;				//边/弧指向哪个结点
	struct ArcNode *next;	//指向下一条弧的指针 
	//Infotype info;		//边权值 
}
//顶点
typedef struct VNode
{
	VertexType data;		//顶点信息 
	ArcNode *first;			//第一条边/弧 
 }VNode,AdjList[MaxVertexNum];
//用邻接表存储的图
typedef struct
{
	AdjList vertexs;	//vertices		vertexes
	int vexnum,arcnum;
}ALGraph;



