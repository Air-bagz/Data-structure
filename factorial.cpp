#include<stdio.h>

int factorial(int n)
{
	if (n==0 || n==1)
		return 1;
	else 
		return n*factorial(n-1);
}

int main()
{
	int x=factorial(5);
	printf("%d\n",x); 
}
