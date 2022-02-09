//填坑法1.1:基准取第一个	A[low]	 
//[0]---[n-1] 				([1]---[n]一样)
//把Partition写进来，需要i和j 
//两个while不可交换 
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

//快速排序
void QuickSort(int A[],int low,int high)
{
	if (low<high)	//递归跳出的条件 
	{
		int pivot=A[low];		//第一个元素作为枢轴 
		int i=low;
		int j=high;
		while (i<j)		//用low,high搜索枢轴的最终位置 
		{
			while(i<j && A[j]>=pivot)	--j; 
			A[i]=A[j];		//比枢轴小的元素移动到左端
			while(i<j && A[i]<=pivot)	++i;
			A[j]=A[i];		//比枢轴大的元素移动到右端 
		}
		A[i]=pivot;		//枢轴元素存放到最终位置 
		int pivotpos=i;	//划分 
		QuickSort(A,low,pivotpos-1);		//划分左子表 
		QuickSort(A,pivotpos+1,high);		//划分右子表 
	}
 } 

//用第一个元素将待排序序列划分成左右两个部分
int Partition(int A[],int low,int high)
{
	
 } 
 
void Print(int A[],int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",A[i]);
	printf("\n");
} 
