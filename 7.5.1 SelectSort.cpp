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
	for (int i=0; i<n-1; i++)	//一共进行n-1趟 
	{
		int min=i;		//记录最小元素位置
		for (int j=i+1; j<n; j++)	//在A[i...n-1]中选择更小的元素
			if (A[j]<A[min])	min=j;	//更新最小元素位置
		if (min!=i)	swap(A[i],A[min]);	//封装的swap()函数共移动元素3次 
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
