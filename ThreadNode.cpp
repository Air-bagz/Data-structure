//二叉树的结点（链式存储）
typedef char ElemType;

typedef struct BiTNode
{
	ElemType data;						//数据域 
	struct BiTNode *lchild,*rchild;		//左、右孩子指针 
 }BiTNode,*BiTree;
 
//线索二叉树结点
typedef char ElemType;

typedef struct ThreadNode
{
	ElemType data;							//数据域 
	struct ThreadNode *lchild,*rchild;		//左、右孩子指针 
	int ltag,rtag;							//左右线索标志 
 }ThreadNode,*ThreadTree; 
