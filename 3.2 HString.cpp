//动态数组实现（堆分配存储）
#define MAXLEN 255		//预定义最大串长255 
typedef struct
{
	char *ch;			//按串长分配存储区，ch指向串的基地址 
	int length;			//串的长度 
 }HString;

HString S;
S.ch=(char *)malloc(MAXLEN*sizeof(char));
S.length=0;
 
