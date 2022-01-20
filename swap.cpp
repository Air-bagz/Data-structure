#include<stdio.h>
void swap(int *&p1,int *&p2) 
{
	int *p=NULL;     //改变了实参指针p_1,p_2的指向 
	p=p1;
	p1=p2;
	p2=p;
}
main()
{
	int a,b,*p_1,*p_2;
	scanf("%d%d",&a,&b);
	p_1=&a; p_2=&b;
	if (a<b) swap(p_1,p_2);   //pass by pointer
	printf("a=%d,b=%d\n",a,b);//运行成功 未交换
	printf("%d %d",*p_1,*p_2);//运行成功 交换成功 
}
