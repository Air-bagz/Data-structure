//˳��������ڱ������ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�-1
//˳��������ڱ������ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�0

typedef struct			//���ұ�����ݽṹ(˳���) 
{
	ElemType *elem;		//��̬�����ַ 
	int Len;			//��ĳ��� 
}SeqTable;

//˳�����----pdfд�� 
int Seq_Search(SeqTable ST,ElemType key)
{
	int i;
	for (i=0; i<ST.len && ST.elem[i]!=key; i++);
	//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�-1
	return i==ST.Len? -1 : i; 
 } 

//˳�����----�ҵ�д�� 
int Seq_Search(SeqTable ST,ElemType key)
{
	int i=0;
	while (i<ST.Len && ST.elem[i]!=key)			
		i++;
	//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�-1
	return i==ST.Len? -1 : i; 
}

//˳�����----���Ա�д�� 
int Seq_Search(SeqTable ST,ElemType key)
{
	for (int i=0; i<L.length; i++)
		if (ST.elem[i]==key)		
			return i;		//�±� 
	return -1;	//ʧ�� 
}
/* 
int LocateElem(SqList L, int e)		//���Ա� 
{
	for (int i=0; i<L.length; i++)
		if (L.data[i]==e)		
			return i+1;		//λ�� 
	return 0;			
}
*/
//--------------------------------------------------------------------------------------------- 
//˳����ң����ڱ�----pdfд��
int Seq_Search(SeqTable ST,ElemType key)
{
	ST.elem[0]=key;		//�ڱ� 
	int i;
	for (i=ST.Len; ST.elem[i]!=key; i--);	//�Ӻ���ǰ�� 
	return i; 		//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�0
 } 

//˳����ң����ڱ�----�ҵ�д��
int Seq_Search(SeqTable ST,ElemType key)
{
	ST.elem[0]=key;		//guard
	int i=ST.Len;
	while (ST.elem[i]!=key)		//�����ж��Ƿ�Խ�� 
		i--;
	return i; 		//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�0
 } 
 
//˳����ң����ڱ�----���Ա�д�� 
int Seq_Search(SeqTable ST,ElemType key)
{
	for (int i=ST.Len; ; i--)
		if (ST.elem[i]==key)		
			return i;		//�±� 
}
