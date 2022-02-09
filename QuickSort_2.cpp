//��ӷ�2:��׼ȡ���һ��	A[high]	 
//[0]---[n-1] ([1]---[n]һ��)
//����while���ɽ��� 
#include<stdio.h> 

void QuickSort(int A[],int low,int high);
int Partition(int A[],int low,int high);
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
		int pivotpos=Partition(A,low,high);	//���� 
		QuickSort(A,low,pivotpos-1);		//�������ӱ� 
		QuickSort(A,pivotpos+1,high);		//�������ӱ� 
	}
 } 

//�õ�һ��Ԫ�ؽ����������л��ֳ�������������
int Partition(int A[],int low,int high)
{
	int pivot=A[high];		//��һ��Ԫ����Ϊ���� 
	while (low<high)		//��low,high�������������λ�� 
	{
		while(low<high && A[low]<=pivot)	++low;
		A[high]=A[low];		//��������Ԫ���ƶ����Ҷ� 
		while(low<high && A[high]>=pivot)	--high; 
		A[low]=A[high];		//������С��Ԫ���ƶ������
	}
	A[low]=pivot;		//����Ԫ�ش�ŵ�����λ�� 
	return low;		//���ش�����������λ�� 
 } 
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
} 