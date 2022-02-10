//从前往后	[0]--[n-1]存储 
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

//冒泡排序
void BubbleSort(int A[],int n)
{
	for (int i=n-1; i>=1; i--)
	{
		bool flag=false;		//表示本趟冒泡是否发生交换的标志 
		for (int j=0; j<i; j++)	//一趟冒泡过程 
			if (A[j]>A[j+1])	//若为逆序 
			{	
				swap(A[j],A[j+1]);	//交换 
				flag=true;
			}
		if (flag==false)
			return;		//本趟遍历后没有发生交换，说明表已经有序 
	}
 } 
 
//交换
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
{//将a中整数序列重新排列成自小至大有序的整数序列
    for (i=n-1,change=TRUE;i>=1&&change;--i)
    {
        change=FALSE;
        for (j=0;j<i;++j)
          if (a[j]>a[j+1]) {a[j]<-->a[j+1]; change=TRUE;}
     } 
}
*/
