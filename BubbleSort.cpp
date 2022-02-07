//�Ӻ���ǰ	[0]--[n-1]�洢 
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

//ð������
void BubbleSort(int A[],int n)
{
	for (int i=0; i<n-1; i++)
	{
		bool flag=false;		//��ʾ����ð���Ƿ��������ı�־ 
		for (int j=n-1; j>i; j--)	//һ��ð�ݹ��� 
			if (A[j-1]>A[j])	//��Ϊ���� 
			{	
				swap(A[j-1],A[j]);	//���� 
				flag=true;
			}
		if (flag==false)
			return;		//���˱�����û�з���������˵�����Ѿ����� 
	}
 } 
 
//����
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
