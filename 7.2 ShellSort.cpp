#include<stdio.h>

void ShellSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={-1,49,38,65,97,76,13,27,49};//从[1]开始存储 
	ShellSort(a,8);
	Print(a,8);
}

//希尔排序
void ShellSort(int A[],int n)
{
	int d,i,j;
	//A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
	for (d=n/2; d>=1; d=d/2)	//步长变化 
		for (i=1+d; i<=n; ++i)
			if (A[i]<A[i-d])	//需将A[i]插入有序增量子表 
			{
				A[0]=A[i];		//暂存在A[0]
				for (j=i-d; j>0 && A[0]<A[j]; j-=d)
					A[j+d]=A[j];	//记录后移，查找插入的位置
				A[j+d]=A[0];	//插入 
			 }//if 
 } 
 
void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
