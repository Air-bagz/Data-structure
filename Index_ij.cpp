//����ģʽƥ���㷨	�����±�ʵ��
#define MAXLEN 255		//Ԥ������󴮳�Ϊ255
typedef struct
{
	char ch[MAXLEN];	
	int length;		
 }SString; 
 
int Index(SString S,SString T)
{
	int i=1,j=1;
	while (i<=S.length && j<=T.length)
	{
		if (S.ch[i]==T.ch[j])
		{
			++i;
			++j;		//�����ȽϺ���ַ� 
		}
		else {
			i=i-j+2;
			j=1;		//ָ��������¿�ʼƥ�� 
		}
	}
	if (j>T.length)
		return i-T.length;
	else
		return 0;
 } 
//��������Ϊn,ģʽ������Ϊm			O(nm) 
