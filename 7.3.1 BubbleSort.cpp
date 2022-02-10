//从后往前	[0]--[n-1]存储 
#include<stdio.h>

void BubbleSort(int A[],int n);
void swap(int &a,int &b);
void Print(int A[],int n);

int main()
{
	int a[]={49,38,65,97,76,13,27,49};
	BubbleSort(a,8);
	Print(a,8);
}

//冒泡排序
void BubbleSort(int A[],int n)
{
	for (int i=0; i<n-1; i++)
	{
		bool flag=false;		//表示本趟冒泡是否发生交换的标志 
		for (int j=n-1; j>i; j--)	//一趟冒泡过程 
			if (A[j-1]>A[j])	//若为逆序 
			{	
				swap(A[j-1],A[j]);	//交换 
				flag=true;
			}
		if (flag==false)
			return;		//本趟遍历后没有发生交换，说明表已经有序 
	}
 } 
 
//交换
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
 } 
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
