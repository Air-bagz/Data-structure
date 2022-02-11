//С����Ϊ��	����	ɾ��
//[1]---[n]
#include<stdio.h>

void BuildMinHeap(int A[],int len);
void HeadAdjust(int A[],int k,int len);
void swap(int &a,int &b);
void Print(int A[],int n); 
void HeapInsert(int A[],int len,int x);
void HeapDelete(int A[],int len,int i); 

int main()
{
	int a[]={-1,53,17,78,9,45,65,87,32};	//pdf���� 
	BuildMinHeap(a,8);		
		printf("����С����:\t");		Print(a,8);		//����С���� 
	HeapInsert(a,8,13);		//����13 
		printf("����13:\t\t");		Print(a,9);
	HeapInsert(a,9,46);		//����46 
		printf("����46:\t\t");		Print(a,10);
	HeapDelete(a,10,2);		//ɾ��a[2]
		printf("ɾ��A[2]:\t");		Print(a,9);
	HeapDelete(a,9,3);		//ɾ��a[3]
		printf("ɾ��A[3]:\t");		Print(a,8);
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

void HeapInsert(int A[],int len,int x)	//����Ԫ��x 
{
	A[len+1]=x;		//��Ԫ�طŵ���β 
	int i=len+1;
	while (A[i]<A[i/2])		//��Ԫ�رȸ�����С���򽫶��߽�����һ·������ֱ���޷���������Ϊֹ 
		{
			swap(A[i],A[i/2]);
			i=i/2;
		}
}

void HeapDelete(int A[],int len,int i)	//ɾ��A[i] 
{
	A[i]=A[len];		//��ɾ����Ԫ���öѵ�Ԫ�����
	HeadAdjust(A,i,len-1);		//�ø�Ԫ�ز�����׹��ֱ���޷���׹Ϊֹ 
}
