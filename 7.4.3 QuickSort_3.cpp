//交换法:基准取中间位置元素	A[(low+high)/2]	 
//[0]---[n-1] 	([1]---[n]一样)
//把Partition写进来，需要i和j 
//两个while可交换 
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
	int i,j,mid;        //实际应用中，这里的变量可定义成全局变量以节省栈空间
	i=low;
	j=high;
	mid=A[(i+j)/2];        //将当前序列在中间位置的数定义为中间数基准
	while(i<=j)	//注意这里必须有等号
	{
		while (A[i]<mid)	i++;	//在左半部分寻找比中间数大的数
		while (A[j]>mid)	j--;	//在右半部分寻找比中间数小的数
		if (i<=j)		//若找到一组与排序目标不一致的数对则交换它们
		{
			swap(A[i],A[j]);
			i++;	//继续找
			j--;
		}
	}
	if (low<j)	QuickSort(A,low,j);		//若序列有1个以上的无素，则递归搜索左右区间
	if (i<high)	QuickSort(A,i,high);
}
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
} 

//交换
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
 } 
