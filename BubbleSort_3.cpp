//��ǰ����	[0]--[n-1]�洢 
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
	for (int i=n-1; i>=1; i--)
	{
		bool flag=false;		//��ʾ����ð���Ƿ��������ı�־ 
		for (int j=0; j<i; j++)	//һ��ð�ݹ��� 
			if (A[j]>A[j+1])	//��Ϊ���� 
			{	
				swap(A[j],A[j+1]);	//���� 
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

/*
void bubble_sort(int a[],int n)
{//��a�����������������г���С�����������������
    for (i=n-1,change=TRUE;i>=1&&change;--i)
    {
        change=FALSE;
        for (j=0;j<i;++j)
          if (a[j]>a[j+1]) {a[j]<-->a[j+1]; change=TRUE;}
     } 
}
*/
