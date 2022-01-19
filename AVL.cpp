//平衡二叉树结点
typedef struct AVLNode
{
	int key;		//数据域 
	int balance;	//平衡因子 
	struct AVLNode *lchild,*rchild;
 }AVLNode,*AVLTree;
 
//只有右孩子才能左旋，只有左孩子才能右旋
AVLNode *unbalan		//unbalanced node
AVLNode *unbalan_dad	
ABLNode *unbalan_son

//A是根结点，B是A的左孩子	
//B的左子树增加了一个结点，以A为根的子树失去平衡（最小不平衡子树）
//此为 LL ----- 在A的左孩子的左子树中插入导致不平衡
//调整：B(A的左孩子结点)右旋
A->lchild=B->rchild;
B->rchild=A;
grandfa->lchild/rchild=B;
//B完成右旋 

//A是根结点，B是A的右孩子	
//B的右子树增加了一个结点，以A为根的子树失去平衡（最小不平衡子树）
//此为 RR ----- 在A的右孩子的右子树中插入导致不平衡
//调整：B(A的右孩子结点)左旋
A->rchild=B->lchild;
B->lchild=A;
grandfa->lchild/rchild=B;
//B完成左旋 

//A是根结点，B是A的左孩子，C是B的右孩子	
//B的右子树增加了一个结点(增加到C的左子树或右子树)，以A为根的子树失去平衡（最小不平衡子树）
//此为 LR ----- 在A的左孩子的右子树中插入导致不平衡
//调整：C(A的左孩子的右孩子)先左旋再右旋
B->rchild=C->lchild;
C->lchild=B;
A->lchild=C;
//C完成左旋
A->lchild=C->rchild;
C->rchild=A;
grandfa->lchild/rchild=C;
//C完成右旋 

//A是根结点，B是A的右孩子，C是B的左孩子	
//B的左子树增加了一个结点(增加到C的左子树或右子树)，以A为根的子树失去平衡（最小不平衡子树）
//此为 RL ----- 在A的右孩子的左子树中插入导致不平衡
//调整：C(A的右孩子的左孩子)先右旋再左旋
B->lchild=C->rchild;
C->rchild=B;
A->rchild=C;
//C完成右旋 
A->rchild=C->lchild;
C->lchild=A;
grandfa->lchild/rchild=C;
//C完成左旋 
