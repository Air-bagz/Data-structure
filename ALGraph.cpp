//�ڽӱ� 
#define MaxVertexNum 100					//������Ŀ�����ֵ 
typedef char VertexType;					//������������� 
typedef int Infotype; 						//��Ȩͼ�б���Ȩֵ���������� 
//��/�� 
typedef struct ArcNode
{
	int adjvex;				//��/��ָ���ĸ����
	struct ArcNode *next;	//ָ����һ������ָ�� 
	//Infotype info;		//��Ȩֵ 
}
//����
typedef struct VNode
{
	VertexType data;		//������Ϣ 
	ArcNode *first;			//��һ����/�� 
 }VNode,AdjList[MaxVertexNum];
//���ڽӱ�洢��ͼ
typedef struct
{
	AdjList vertexs;	//vertices		vertexes
	int vexnum,arcnum;
}ALGraph;



