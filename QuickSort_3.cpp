//������:��׼ȡ�м�λ��Ԫ��	A[(low+high)/2]	 
//[0]---[n-1] 	([1]---[n]һ��)
//��Partitionд��������Ҫi��j 
//����while�ɽ��� 
#include<stdio.h> 

void QuickSort(int A[],int low,int high);
int Partition(int A[],int low,int high);
void Print(int A[],int n);
void swap(int &a,int &b);

int main()
{
	int a[]={49,38,65,97,76,13,27,49};
	QuickSort(a,0,7);
	Print(a,8);
}

void QuickSort(int A[],int low,int high)
{
	int i,j,mid;        //ʵ��Ӧ���У�����ı����ɶ����ȫ�ֱ����Խ�ʡջ�ռ�
	i=low;
	j=high;
	mid=A[(i+j)/2];        //����ǰ�������м�λ�õ�������Ϊ�м�����׼
	while(i<=j)	//ע����������еȺ�
	{
		while (A[i]<mid)	i++;	//����벿��Ѱ�ұ��м��������
		while (A[j]>mid)	j--;	//���Ұ벿��Ѱ�ұ��м���С����
		if (i<=j)		//���ҵ�һ��������Ŀ�겻һ�µ������򽻻�����
		{
			swap(A[i],A[j]);
			i++;	//������
			j--;
		}
	}
	if (low<j)	QuickSort(A,low,j);		//��������1�����ϵ����أ���ݹ�������������
	if (i<high)	QuickSort(A,i,high);
}
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
} 

//����
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
 } 
