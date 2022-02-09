//[0]---[n-1]
#include<stdio.h> 

void SelectSort(int A[],int n);
void swap(int &a,int &b);
void Print(int A[],int n); 

int main()
{
	int a[]={49,38,65,97,76,13,27,49};
	SelectSort(a,8);
	Print(a,8);
}

void SelectSort(int A[],int n)
{
	for (int i=0; i<n-1; i++)	//һ������n-1�� 
	{
		int min=i;		//��¼��СԪ��λ��
		for (int j=i+1; j<n; j++)	//��A[i...n-1]��ѡ���С��Ԫ��
			if (A[j]<A[min])	min=j;	//������СԪ��λ��
		if (min!=i)	swap(A[i],A[min]);	//��װ��swap()�������ƶ�Ԫ��3�� 
	}
}

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
