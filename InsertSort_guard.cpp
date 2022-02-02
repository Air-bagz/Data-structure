#include<stdio.h>

void InsertSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={-1,49,38,65,97,76,13,27,49};//��[1]��ʼ�洢 
	InsertSort(a,8);
	Print(a,8);
}


void InsertSort(int A[],int n)
{
	int i,j;
	for (i=2; i<=n; i++)	//���ν�A[2]~A[n]���뵽ǰ������������ 
	{
		if (A[i]<A[i-1])	//��A[i]�ؼ���С����ǰ������A[i]��������� 
		{
			A[0]=A[i];		//����Ϊ�ڱ���A[0]�����Ԫ�� 
			for (j=i-1; A[0]<A[j]; --j)	//�Ӻ���ǰ���Ҵ�����λ�� 
				A[j+1]=A[j];	//���Ųλ 
			A[j+1]=A[0]; 	//���Ƶ�����λ�� 
		}
	}
}

void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
