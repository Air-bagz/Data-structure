#include<stdio.h>
void swap(int *&p1,int *&p2) 
{
	int *p=NULL;     //�ı���ʵ��ָ��p_1,p_2��ָ�� 
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
	printf("a=%d,b=%d\n",a,b);//���гɹ� δ����
	printf("%d %d",*p_1,*p_2);//���гɹ� �����ɹ� 
}
