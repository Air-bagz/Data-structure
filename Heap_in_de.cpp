//小根堆为例	插入	删除
//[1]---[n]
#include<stdio.h>

void BuildMinHeap(int A[],int len);
void HeadAdjust(int A[],int k,int len);
void swap(int &a,int &b);
void Print(int A[],int n); 
void HeapInsert(int A[],int len,int x);
void HeapDelete(int A[],int len,int i); 

int main()
{
	int a[]={-1,53,17,78,9,45,65,87,32};	//pdf例子 
	BuildMinHeap(a,8);		
		printf("建立小根堆:\t");		Print(a,8);		//建立小根堆 
	HeapInsert(a,8,13);		//插入13 
		printf("插入13:\t\t");		Print(a,9);
	HeapInsert(a,9,46);		//插入46 
		printf("插入46:\t\t");		Print(a,10);
	HeapDelete(a,10,2);		//删除a[2]
		printf("删除A[2]:\t");		Print(a,9);
	HeapDelete(a,9,3);		//删除a[3]
		printf("删除A[3]:\t");		Print(a,8);
}

 
//建立小根堆
void BuildMinHeap(int A[],int len)
{
	for (int i=len/2; i>0; i--)		//从后往前调整所有非终端结点 
		HeadAdjust(A,i,len);
 } 
 
//将以 k 为根的子树调整为小根堆
void HeadAdjust(int A[],int k,int len)
{
	A[0]=A[k];						//A[0]暂存子树的根结点 
	for (int i=2*k; i<=len; i*=2)	//沿key值较小的子结点向下筛选 
	{
		if (i<len && A[i]>A[i+1])
			i++;					//取key值较小的子结点的下标 
		if (A[0]<A[i])	break;		//筛选结束 
		else
		{
			A[k]=A[i];				//将A[i]调整到双亲结点上 
			k=i;					//修改k值，以便继续向下筛选 
		}
	}
	A[k]=A[0];						//被筛选结点的值放入最终位置 
 } 
 
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
 } 
 
void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}

void HeapInsert(int A[],int len,int x)	//插入元素x 
{
	A[len+1]=x;		//新元素放到表尾 
	int i=len+1;
	while (A[i]<A[i/2])		//新元素比父结点更小，则将二者交换，一路上升，直到无法继续上升为止 
		{
			swap(A[i],A[i/2]);
			i=i/2;
		}
}

void HeapDelete(int A[],int len,int i)	//删除A[i] 
{
	A[i]=A[len];		//被删除的元素用堆底元素替代
	HeadAdjust(A,i,len-1);		//让该元素不断下坠，直到无法下坠为止 
}
