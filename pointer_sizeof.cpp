#include<stdio.h>
int main()
{
	int *p1;
	char *p2;
	struct Node
	{
		int data;				//4		4
		struct Node *next;		//4 	8
	}p3,*p4;
	printf("int=%d\n",sizeof(int));
	printf("int*=%d\n",sizeof(p1));
	printf("char*=%d\n",sizeof(p2));
	printf("struct Node=%d\n",sizeof(struct Node));
	printf("%d\n",sizeof(p3.next));
	printf("struct Node*=%d\n",sizeof(p4));
	return 0;
 } 		//边界对齐	按字节编址，每次访存只能读/写1个字 
 
