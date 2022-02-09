void swap(int a[], int low, int high) //交换两个数的值
{
    int t = a[low];
    a[low] = a[high];
    a[high] = t;
}

swap(a,low,high);


//------------------------------------------------------
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
 } 
 
swap(A[i],A[j]);

//------------------------------------------------------
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

swap(&a[storeIndex], &a[i]);
