//������ʽ�洢 
typedef struct StringNode
{
	char ch;	//ÿ������1���ַ���ÿ���ַ�1B���洢�ܶȵ� 
	struct StringNode *next; 		//ÿ��ָ��4B 
}StringNode,*String;

typedef struct StringNode
{
	char ch[4];		//ÿ���������ַ����洢�ܶ���� 
	struct StringNode *next; 
}StringNode,*String;



