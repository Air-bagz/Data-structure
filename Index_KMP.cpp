//KMP�㷨	�����±�ʵ��
#define MAXLEN 255		//Ԥ������󴮳�Ϊ255
typedef struct
{
	char ch[MAXLEN];	
	int length;		
 }SString; 
 
int Index_KMP(SString S,SString T,int next[])
{
	int i=1,j=1;
	while (i<=S.length && j<=T.length)
	{
		if (j==0 || S.ch[i]==T.ch[j])
		{
			++i;
			++j;		//�����ȽϺ���ַ� 
		}
		else {
			//i= 
			j=next[j];		//ģʽ�������ƶ� 
		}
	}
	if (j>T.length)
		return i-T.length;		//ƥ��ɹ� 
	else
		return 0;
 } 
