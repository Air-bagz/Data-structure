//��ӷ�1.1:��׼ȡ��һ��	A[low]	 
//[0]---[n-1] 				([1]---[n]һ��)
//��Partitionд��������Ҫi��j 
//����while���ɽ��� 
#include<stdio.h> 

void QuickSort(int A[],int low,int high);
//int Partition(int A[],int low,int high);		
void Print(int A[],int n);

int main()
{
	int a[]={49,38,65,97,76,13,27,49};
	QuickSort(a,0,7);
	Print(a,8);
}

//��������
void QuickSort(int A[],int low,int high)
{
	if (low<high)	//�ݹ����������� 
	{
		int pivot=A[low];		//��һ��Ԫ����Ϊ���� 
		int i=low;
		int j=high;
		while (i<j)		//��low,high�������������λ�� 
		{
			while(i<j && A[j]>=pivot)	--j; 
			A[i]=A[j];		//������С��Ԫ���ƶ������
			while(i<j && A[i]<=pivot)	++i;
			A[j]=A[i];		//��������Ԫ���ƶ����Ҷ� 
		}
		A[i]=pivot;		//����Ԫ�ش�ŵ�����λ�� 
		int pivotpos=i;	//���� 
		QuickSort(A,low,pivotpos-1);		//�������ӱ� 
		QuickSort(A,pivotpos+1,high);		//�������ӱ� 
	}
 } 

//�õ�һ��Ԫ�ؽ����������л��ֳ�������������
int Partition(int A[],int low,int high)
{
	
 } 
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
} 
