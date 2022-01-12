//朴素模式匹配算法	数组下标实现
#define MAXLEN 255		//预定义最大串长为255
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
			++j;		//继续比较后继字符 
		}
		else {
			i=i-j+2;		//主串指针回溯 
			j=1;		//模式串指针回退到1 
		}
	}
	if (j>T.length)
		return i-T.length;
	else
		return 0;
 } 
//主串长度为n,模式串长度为m			O(nm) 
/*
int Index(SString S,SString T)
{
	int k=1;
	int i=k,j=1;
	while (i<=S.length && j<=T.length)
	{
		if (S.ch[i]==T.ch[j])
		{
			++i;
			++j;			//继续比较后继字符 
		}
		else {
			k++;		//检查下一个子串
			i=k;
			j=1; 
		}
	}
	if (j>T.length)
		return k;
	else 
		return 0;
}
*/
