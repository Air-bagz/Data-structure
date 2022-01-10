#include<stdio.h>

int Fib(int n)
{
	if (n==0)
		return 0;
	else if(n==1)
			return 1;
		else	return Fib(n-1)+Fib(n-2);
}

int main()
{
	int x=Fib(4);
	printf("%d\n",x);
}
