//�������Ľ�㣨��ʽ�洢��
typedef char ElemType;

typedef struct BiTNode
{
	ElemType data;						//������ 
	struct BiTNode *lchild,*rchild;		//���Һ���ָ�� 
 }BiTNode,*BiTree;
 
//�������������
typedef char ElemType;

typedef struct ThreadNode
{
	ElemType data;							//������ 
	struct ThreadNode *lchild,*rchild;		//���Һ���ָ�� 
	int ltag,rtag;							//����������־ 
 }ThreadNode,*ThreadTree; 
