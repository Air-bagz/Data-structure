//ƽ����������
typedef struct AVLNode
{
	int key;		//������ 
	int balance;	//ƽ������ 
	struct AVLNode *lchild,*rchild;
 }AVLNode,*AVLTree;
 
//ֻ���Һ��Ӳ���������ֻ�����Ӳ�������
AVLNode *unbalan		//unbalanced node
AVLNode *unbalan_dad	
ABLNode *unbalan_son

//A�Ǹ���㣬B��A������	
//B��������������һ����㣬��AΪ��������ʧȥƽ�⣨��С��ƽ��������
//��Ϊ LL ----- ��A�����ӵ��������в��뵼�²�ƽ��
//������B(A�����ӽ��)����
A->lchild=B->rchild;
B->rchild=A;
grandfa->lchild/rchild=B;
//B������� 

//A�Ǹ���㣬B��A���Һ���	
//B��������������һ����㣬��AΪ��������ʧȥƽ�⣨��С��ƽ��������
//��Ϊ RR ----- ��A���Һ��ӵ��������в��뵼�²�ƽ��
//������B(A���Һ��ӽ��)����
A->rchild=B->lchild;
B->lchild=A;
grandfa->lchild/rchild=B;
//B������� 

//A�Ǹ���㣬B��A�����ӣ�C��B���Һ���	
//B��������������һ�����(���ӵ�C����������������)����AΪ��������ʧȥƽ�⣨��С��ƽ��������
//��Ϊ LR ----- ��A�����ӵ��������в��뵼�²�ƽ��
//������C(A�����ӵ��Һ���)������������
B->rchild=C->lchild;
C->lchild=B;
A->lchild=C;
//C�������
A->lchild=C->rchild;
C->rchild=A;
grandfa->lchild/rchild=C;
//C������� 

//A�Ǹ���㣬B��A���Һ��ӣ�C��B������	
//B��������������һ�����(���ӵ�C����������������)����AΪ��������ʧȥƽ�⣨��С��ƽ��������
//��Ϊ RL ----- ��A���Һ��ӵ��������в��뵼�²�ƽ��
//������C(A���Һ��ӵ�����)������������
B->lchild=C->rchild;
C->rchild=B;
A->rchild=C;
//C������� 
A->rchild=C->lchild;
C->lchild=A;
grandfa->lchild/rchild=C;
//C������� 
