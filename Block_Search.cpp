//�ֿ���ң��������򡢿������
//1.������ ˳�����  or  �۰����
//2.����   ˳����� 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;

//������ 
typedef struct
{
	ElemType maxValue;
	int low,high;
 }IndexNode,IndexList[100];
 
typedef struct
{
	IndexList Index;			//IndexNode Index[100];		������ 
	int Index_len;
	ElemType List[100];		//˳���洢ʵ��Ԫ�� 
	int List_len;
}BSList;		//�ֿ���ұ� 

void InitList(BSList &L);
void show(BSList L);
int Seq_Search_Index(BSList L,ElemType key); 
int Seq_Search_Block(BSList L,ElemType key,int point);
void Block_Search(BSList L,ElemType key);
//----------------------------------------------------------------------------------------
int Binary_Search_Index(BSList L,ElemType key); 
void Block_Search2(BSList L,ElemType key);

int main()
{
	BSList L;
	InitList(L);	//�����������˳��� 
	show(L);
//	int key;	//����Ŀ�� 
	Block_Search(L,22);	//pdf���� 
	Block_Search(L,29);	//pdf���� 
	Block_Search(L,50);	//��������һ��
	Block_Search(L,51); //���Գ������
	Block_Search(L,7);	//������С 
	Block_Search(L,6);	//����С����С 
//------------------------------------------------------------------ 
printf("------------------------------�������۰����������---------------------------\n");
	Block_Search2(L,30);//pdf����	
	Block_Search2(L,19);//pdf����
	Block_Search2(L,54);//pdf����
	return 0; 
}

void InitList(BSList &L)
{
	FILE *fp;
	fp=fopen("Z:\\Block_Search.txt","r");
	fscanf(fp,"%d",&L.Index_len);	
	for (int i=0; i<L.Index_len; i++)		
	 	fscanf(fp,"%d %d %d",&L.Index[i].maxValue,&L.Index[i].low,&L.Index[i].high);
	fscanf(fp,"%d",&L.List_len);
	for (int i=0; i<L.List_len; i++)
		fscanf(fp,"%d",&L.List[i]);
/*	for (int i=0; i<5; i++)		
	 	printf("%d %d %d\n",L.Index[i].maxValue,L.Index[i].low,L.Index[i].high);
	for (int i=0; i<14; i++)
		printf("%d ",L.List[i]);	*/
}

void show(BSList L)
{
	for (int i=0; i<L.List_len; i++)	
		printf("L[%d]\t",i);
	printf("\n");
	for (int i=0; i<L.List_len; i++)	
		printf("%d\t",L.List[i]);
	printf("\n"); 
}

//˳����������� �� ���ؿ�ţ���0��ʼ�� 
int Seq_Search_Index(BSList L,ElemType key)	
{
	int i=0;
	while (i<L.Index_len && key>L.Index[i].maxValue)			
		i++;
	return i;		//���ҳɹ�����i��ָ�ֿ飬��key������������ֵ�᷵��L.Index_len 
 } 

//����˳����� �� ���������±� 
int Seq_Search_Block(BSList L,ElemType key,int point)
{
	for (int i=L.Index[point].low; i<=L.Index[point].high; i++)		
		if (L.List[i]==key)	
			return i;
	return -1;		//˳�����ʧ�� 
}

void Block_Search(BSList L,ElemType key)
{
	int point=Seq_Search_Index(L,key);	//˳�����������	���ؿ��	point_block   
	printf("��Ĳ���Ŀ��Ϊ:%d\n",key);
//	printf("%d %d",L.Index[point].low,L.Index[point].high);
	if (point==L.Index_len)	
		printf("�������̫����,������������ķ�Χ!\n");
	else 
		{	
			int loca=Seq_Search_Block(L,key,point);		//����˳�����
			if (loca==-1)	
				printf("ʧ����,�Ҳ������%d\n",key);
			else 
				printf("�ҵ���!��˳����L[%d]\n",loca);
		}
}
//----------------------------------------------------------------------------------------
int Binary_Search_Index(BSList L,ElemType key)
{
	int low=0,high=L.Index_len-1,mid;
	while (low<=high)
	{
		mid=(low+high)/2;			//ȡ�м�λ�� 
		if (L.Index[mid].maxValue==key)		
			return	mid;			//���ҳɹ��򷵻�Ԫ���±� 
		else if (L.Index[mid].maxValue>key)
			high=mid-1;				//��ǰ�벿�ּ������� 
		else 
			low=mid+1;				//�Ӻ�벿�ּ������� 
	}
	return low;				//������������Ŀ��ؼ��֣����ջ�ͣ��low>high��Ҫ��low��ָ�ֿ��ڲ���
}

void Block_Search2(BSList L,ElemType key)
{
	int point=Binary_Search_Index(L,key);	//�۰����������	���ؿ��	point_block  
	printf("��Ĳ���Ŀ��Ϊ:%d\n",key);
//	printf("%d %d",L.Index[point].low,L.Index[point].high);
	if (point==L.Index_len)	
		printf("�������̫����,������������ķ�Χ!\n");
	else 
		{	
			int loca=Seq_Search_Block(L,key,point);		//����˳�����
			if (loca==-1)	
				printf("ʧ����,�Ҳ������%d\n",key);
			else 
				printf("�ҵ���!��˳����L[%d]\n",loca);
		}
}
