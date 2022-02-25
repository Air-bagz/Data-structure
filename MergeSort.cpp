//[0]--[n-1]	�������� 

#include<stdio.h>
#include<stdlib.h>
#define N 6

void MergeSort(int A[],int low,int high);
void Merge(int A[],int low,int mid,int high);
void Print(int A[],int n);

int *B=(int *)malloc(N*sizeof(int));	//��������B

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
		int mid=(low+high)/2;		//���м仮��
		MergeSort(A,low,mid);		//����벿�ֹ鲢����
		MergeSort(A,mid+1,high);	//���Ұ벿�ֹ鲢����
		Merge(A,low,mid,high);		//�鲢 
	}//if 
}

//A[low..mid]��A[mid+1..high]�������򣬽��������ֹ鲢
void Merge(int A[],int low,int mid,int high)
{
	int i,j,k;
	for (k=low; k<=high; k++)
		B[k]=A[k];		//��A������Ԫ�ظ��Ƶ�B��
	for (i=low,j=mid+1,k=i; i<=mid&&j<=high; k++)
	{
		if (B[i]<=B[j])		//�ȶ� 
			A[k]=B[i++];		//����Сֵ���Ƶ�A�� 
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
