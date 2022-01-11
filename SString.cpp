//��̬����ʵ�֣�����˳��洢�� 
#define MAXLEN 255		//Ԥ������󴮳�Ϊ255
typedef struct
{
	char ch[MAXLEN];	//ÿ�������洢һ���ַ�,ch[0]�������ã�ʹ�ַ�λ��������±���ͬ 
	int length;			//����ʵ�ʳ��� 
 }SString; 

bool SubString(SString &Sub,SString S,int pos,int len);	//���Ӵ�����Sub���ش�S�ĵ�pos���ַ��𳤶�λlen���Ӵ� 
int StrCompare(SString S,SString T);	//�Ƚϲ�������S>T���򷵻�ֵ>0����S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0 
int Index(SString S,SString T);			//��λ������������S�д����봮Tֵ��ͬ���Ӵ����򷵻���������S�е�һ�γ��ֵ�λ�ã�������ֵΪ0 

bool SubString(SString &Sub,SString S,int pos,int len)
{
	//�Ӵ���ΧԽ�� 
	if (pos+len-1>S.length)
		return false;
	for (int i=pos; i<pos+len; i++)
		Sub.ch[i-pos+1]=S.ch[i];
	Sub.length=len;
	return true;
}

int StrCompare(SString S,SString T)
{
	for (int i=1;i<=S.length && i<=T.length;i++)
	{
		if (S.ch[i]!=T.ch[i])
		return S.ch[i]-T.ch[i];
	}
	//ɨ����������ַ�����ͬ���򳤶ȳ��Ĵ�����
	return S.length-T.length; 
 } 

int Index(SString S,SString T)
{
	int i=1, n=StrLength(S), m=StrLength(T);
	SString sub;	//�����ݴ��Ӵ�
	while (i<=n-m+1)
	{
		SubString(sub,S,i,m);
		if (StrCompare(sub,T)!=0)	++i;
		else return i;	//�����Ӵ��������е�λ�� 
	 } 
	 return 0;	//S�в�������T��ȵ��Ӵ� 
 } 
