#include<stdio.h>

void InsertSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={49,38,65,97,76,13,27,49};//��[0]��ʼ�洢 
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
		while (temp<A[j] && j>=0)	//j>=0��Ҫ����ȻA[-1]δ֪ 
		{
			A[j+1]=A[j];	//��ĺ���(�ϸ�>) 
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
