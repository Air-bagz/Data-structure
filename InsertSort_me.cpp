#include<stdio.h>

void InsertSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={49,38,65,97,76,13,27,49};//从[0]开始存储 
	InsertSort(a,8);
	Print(a,8);
	//printf("%d",a[-2]);
}

void InsertSort(int A[],int n)
{
	int i,j,temp;
	for (i=1; i<n; i++)
	{
		j=i-1;		temp=A[i];
		while (temp<A[j] && j>=0)	//j>=0必要，不然A[-1]未知 
		{
			A[j+1]=A[j];	//大的后移(严格>) 
			j--;
		}
		A[j+1]=temp;
	}
}

void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
