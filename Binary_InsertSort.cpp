//�۰��������	A[0]���ڱ�
#include<stdio.h>

typedef int ElemType; 

void Binary_InsertSort(ElemType A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={-1,20,30,40,50,60,70,80,55,60,90,10};//��[1]��ʼ�洢 
	Binary_InsertSort(a,11);
	Print(a,11);
}

void Binary_InsertSort(ElemType A[],int n)
{
	int i,j,low,high,mid;
	for (i=2; i<=n; i++)	//���ν�A[2]~A[n]����ǰ������������� 
	{
		A[0]=A[i];	//��A[i]�ݴ浽A[0] 
		low=1; high=i-1;	//�����۰���ҵķ�Χ 
		while (low<=high)		//�۰���ң�Ĭ�ϵ������� 
		{
			mid=(low+high)/2;		//ȡ�м�� 
			if (A[mid]>A[0])	high=mid-1;		//��������ӱ� 
			else	low=mid+1;		//�����Ұ��ӱ� 	����A[mid]==A[0]����֤�ȶ��� 
		}
		for (j=i-1; j>=low; --j)	//low == high+1
			A[j+1]=A[j];		//ͳһ����Ԫ�أ��ճ�����λ�� 
		A[low]=A[0];			//������� 
	}
 } 
 
void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
