//С����	�ݼ����� 
//[1]---[n] 
#include<stdio.h>

void HeapSort(int A[],int len);
void BuildMinHeap(int A[],int len);
void HeadAdjust(int A[],int k,int len);
void swap(int &a,int &b);
void Print(int A[],int n);

int main()
{
	int a[]={-1,53,17,78,9,45,65,87,32};	//pdf���� 
	BuildMinHeap(a,8);		Print(a,8);		//��ϰ�� 
//	HeapSort(a,8);			Print(a,8);
}

//������������߼�
void HeapSort(int A[],int len)
{
	BuildMinHeap(A,len);		//��ʼ���� 
	for (int i=len; i>1; i--)	//n-1�˵Ľ����ͽ��ѹ��� 
	{
		swap(A[i],A[1]);		//�Ѷ�Ԫ�غͶѵ�Ԫ�ؽ��� 
		HeadAdjust(A,1,i-1);	//��ʣ��Ĵ�����Ԫ������ɶ� 
	}
 } 
 
//����С����
void BuildMinHeap(int A[],int len)
{
	for (int i=len/2; i>0; i--)		//�Ӻ���ǰ�������з��ն˽�� 
		HeadAdjust(A,i,len);
 } 
 
//���� k Ϊ������������ΪС����
void HeadAdjust(int A[],int k,int len)
{
	A[0]=A[k];						//A[0]�ݴ������ĸ���� 
	for (int i=2*k; i<=len; i*=2)	//��keyֵ��С���ӽ������ɸѡ 
	{
		if (i<len && A[i]>A[i+1])
			i++;					//ȡkeyֵ��С���ӽ����±� 
		if (A[0]<A[i])	break;		//ɸѡ���� 
		else
		{
			A[k]=A[i];				//��A[i]������˫�׽���� 
			k=i;					//�޸�kֵ���Ա��������ɸѡ 
		}
	}
	A[k]=A[0];						//��ɸѡ����ֵ��������λ�� 
 } 
 
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
 } 
 
void Print(int A[],int n)
{
	for (int i=1; i<=n; i++)
		printf("%d ",A[i]);
	printf("\n");
}
