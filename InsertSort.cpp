#include<stdio.h>

void InsertSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={49,38,65,97,76,13,27,49};//从[0]开始存储 
	InsertSort(a,8);
	Print(a,8);
}

//直接插入排序
void InsertSort(int A[],int n)
{
	int i,j,temp;
	for (i=1; i<n; i++)		//依次将A[1]~A[n-1]插入已排好序的序列中 
		if (A[i]<A[i-1])	//若A[i]关键字小于前驱 
		{
			temp=A[i];		//用temp暂存A[i] 
			for (j=i-1;j>=0 && A[j]>temp; --j)	//检查所有前面已排好序的元素 
				A[j+1]=A[j];	//所有大于temp的元素都向后挪位 
			A[j+1]=temp;	//复制到插入位置 
		}
 } 
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
