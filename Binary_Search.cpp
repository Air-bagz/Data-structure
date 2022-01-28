//�۰���ң�
//1.Ԫ����������
//2.�����±��0��ʼ�洢
//3.mid=(low+high)/2  ������ȡ��    

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define InitSize 20
typedef int ElemType;

typedef struct			//���ұ�����ݽṹ(˳���) 
{
	ElemType *elem;		//��̬�����ַ 
	int Len;			//��ĳ��� 
}SeqTable;

int Binary_Search(SeqTable L,ElemType key);
void InitTable(SeqTable &L);

int main()
{
	SeqTable L;
	InitTable(L);
	printf("12Ԫ�ص��±�Ϊ:%d\n",Binary_Search(L,12));
	printf("33Ԫ�ص��±�Ϊ:%d\n",Binary_Search(L,33));
	return 0;
}

//�۰����
int Binary_Search(SeqTable L,ElemType key)
{
	int low=0,high=L.Len-1,mid;
	while (low<=high)
	{
		mid=(low+high)/2;			//ȡ�м�λ�� 
		if (L.elem[mid]==key)		
			return	mid;			//���ҳɹ��򷵻�Ԫ���±� 
		else if (L.elem[mid]>key)
			high=mid-1;				//��ǰ�벿�ּ������� 
		else 
			low=mid+1;				//�Ӻ�벿�ּ������� 
	}
	return -1;				//����ʧ�ܣ�����-1 
}

void InitTable(SeqTable &L)
{
	L.elem=(int *)malloc(InitSize*sizeof(int));		
	L.Len=0;
	
	FILE *fp;
	fp=fopen("Z:\\Binary_Search.txt","r");
	fscanf(fp,"%d",&L.Len);	
	for (int i=0; i<L.Len; i++)		
	 	fscanf(fp,"%d",&L.elem[i]);
}	
