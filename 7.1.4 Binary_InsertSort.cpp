//折半插入排序	A[0]作哨兵
#include<stdio.h>

typedef int ElemType; 

void Binary_InsertSort(ElemType A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={-1,20,30,40,50,60,70,80,55,60,90,10};//从[1]开始存储 
	Binary_InsertSort(a,11);
	Print(a,11);
}

void Binary_InsertSort(ElemType A[],int n)
{
	int i,j,low,high,mid;
	for (i=2; i<=n; i++)	//依次将A[2]~A[n]插入前面的已排序序列 
	{
		A[0]=A[i];	//将A[i]暂存到A[0] 
		low=1; high=i-1;	//设置折半查找的范围 
		while (low<=high)		//折半查找（默认递增有序） 
		{
			mid=(low+high)/2;		//取中间点 
			if (A[mid]>A[0])	high=mid-1;		//查找左半子表 
			else	low=mid+1;		//查找右半子表 	包括A[mid]==A[0]，保证稳定性 
		}
		for (j=i-1; j>=low; --j)	//low == high+1
			A[j+1]=A[j];		//统一后移元素，空出插入位置 
		A[low]=A[0];			//插入操作 
	}
 } 
 
void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
