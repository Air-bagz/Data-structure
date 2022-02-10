//看似交换本质还是填坑法	基准取第一个	A[low]	 
//[0]---[n-1] 			([1]---[n]一样)
//一共n个元素，怎么交换都不会破坏或覆盖 
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

//快速排序
void QuickSort(int A[],int low,int high)
{
	if (low<high)	//递归跳出的条件 
	{
		int pivotpos=Partition(A,low,high);	//划分 
		QuickSort(A,low,pivotpos-1);		//划分左子表 
		QuickSort(A,pivotpos+1,high);		//划分右子表 
	}
 } 

//用第一个元素将待排序序列划分成左右两个部分
int Partition(int A[],int low,int high)
{
	int pivot=A[low];		//第一个元素作为枢轴 
	while (low<high)		//用low,high搜索枢轴的最终位置 
	{
		while(low<high && A[high]>=pivot)	--high; 
		swap(A[low],A[high]);	//比枢轴小的元素移动到左端
		while(low<high && A[low]<=pivot)	++low;
		swap(A[low],A[high]);	//比枢轴大的元素移动到右端 
	}
//	A[low]=pivot;		//枢轴元素存放到最终位置 
	return low;		//返回存放枢轴的最终位置 
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