#include<stdio.h>

void ShellSort(int A[],int n);
void Print(int A[],int n);

int main()
{
	int a[]={-1,49,38,65,97,76,13,27,49};//��[1]��ʼ�洢 
	ShellSort(a,8);
	Print(a,8);
}

//ϣ������
void ShellSort(int A[],int n)
{
	int d,i,j;
	//A[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ���ѵ�
	for (d=n/2; d>=1; d=d/2)	//�����仯 
		for (i=1+d; i<=n; ++i)
			if (A[i]<A[i-d])	//�轫A[i]�������������ӱ� 
			{
				A[0]=A[i];		//�ݴ���A[0]
				for (j=i-d; j>0 && A[0]<A[j]; j-=d)
					A[j+d]=A[j];	//��¼���ƣ����Ҳ����λ��
				A[j+d]=A[0];	//���� 
			 }//if 
 } 
 
void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
