#include<stdio.h>

void InsertSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={49,38,65,97,76,13,27,49};//��[0]��ʼ�洢 
	InsertSort(a,8);
	Print(a,8);
}

//ֱ�Ӳ�������
void InsertSort(int A[],int n)
{
	int i,j,temp;
	for (i=1; i<n; i++)		//����Ԫ�ز������ź���������� 
		if (A[i]<A[i-1])	//��A[i]�ؼ���С��ǰ�� 
		{
			temp=A[i];		//��temp�ݴ�A[i] 
			for (j=i-1;j>=0 && A[j]>temp; --j)	//�������ǰ�����ź����Ԫ�� 
				A[j+1]=A[j];	//���д���temp��Ԫ�ض����Ųλ 
			A[j+1]=temp;	//���Ƶ�����λ�� 
		}
 } 
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
