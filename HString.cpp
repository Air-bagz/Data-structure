//��̬����ʵ�֣��ѷ���洢��
#define MAXLEN 255		//Ԥ������󴮳�255 
typedef struct
{
	char *ch;			//����������洢����chָ�򴮵Ļ���ַ 
	int length;			//���ĳ��� 
 }HString;

HString S;
S.ch=(char *)malloc(MAXLEN*sizeof(char));
S.length=0;
 
