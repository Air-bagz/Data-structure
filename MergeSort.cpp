//[0]--[n-1]	递增序列 

#include<stdio.h>
#include<stdlib.h>
#define N 6

void MergeSort(int A[],int low,int high);
void Merge(int A[],int low,int mid,int high);
void Print(int A[],int n);

int *B=(int *)malloc(N*sizeof(int));	//辅助数组B

int main()
{
	int a[]={49,38,65,97,76,13,27};
	MergeSort(a,0,6);
	Print(a,7);
}

void MergeSort(int A[],int low,int high)
{
	if (low<high)
	{
		int mid=(low+high)/2;		//从中间划分
		MergeSort(A,low,mid);		//对左半部分归并排序
		MergeSort(A,mid+1,high);	//对右半部分归并排序
		Merge(A,low,mid,high);		//归并 
	}//if 
}

//A[low..mid]和A[mid+1..high]各自有序，将两个部分归并
void Merge(int A[],int low,int mid,int high)
{
	int i,j,k;
	for (k=low; k<=high; k++)
		B[k]=A[k];		//将A中所有元素复制到B中
	for (i=low,j=mid+1,k=i; i<=mid&&j<=high; k++)
	{
		if (B[i]<=B[j])		//稳定 
			A[k]=B[i++];		//将较小值复制到A中 
		else 
			A[k]=B[j++];
	 }//for
	while (i<=mid)	A[k++]=B[i++];
	while (j<=high)	A[k++]=B[j++];
 } 
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
} 
