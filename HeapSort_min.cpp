//小根堆	递减序列 
//[1]---[n] 
#include<stdio.h>

void HeapSort(int A[],int len);
void BuildMinHeap(int A[],int len);
void HeadAdjust(int A[],int k,int len);
void swap(int &a,int &b);
void Print(int A[],int n);

int main()
{
	int a[]={-1,53,17,78,9,45,65,87,32};	//pdf例子 
	BuildMinHeap(a,8);		Print(a,8);		//练习题 
//	HeapSort(a,8);			Print(a,8);
}

//堆排序的完整逻辑
void HeapSort(int A[],int len)
{
	BuildMinHeap(A,len);		//初始建堆 
	for (int i=len; i>1; i--)	//n-1趟的交换和建堆过程 
	{
		swap(A[i],A[1]);		//堆顶元素和堆底元素交换 
		HeadAdjust(A,1,i-1);	//把剩余的待排序元素整理成堆 
	}
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
