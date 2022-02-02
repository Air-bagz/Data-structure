#include<stdio.h>

void InsertSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={-1,49,38,65,97,76,13,27,49};//从[1]开始存储 
	InsertSort(a,8);
	Print(a,8);
}


void InsertSort(int A[],int n)
{
	int i,j;
	for (i=2; i<=n; i++)	//依次将A[2]~A[n]插入到前面已排序序列 
	{
		if (A[i]<A[i-1])	//若A[i]关键码小于其前驱，将A[i]插入有序表 
		{
			A[0]=A[i];		//复制为哨兵，A[0]不存放元素 
			for (j=i-1; A[0]<A[j]; --j)	//从后往前查找待插入位置 
				A[j+1]=A[j];	//向后挪位 
			A[j+1]=A[0]; 	//复制到插入位置 
		}
	}
}

void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
