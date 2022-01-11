//串的链式存储 
typedef struct StringNode
{
	char ch;	//每个结点存1个字符，每个字符1B，存储密度低 
	struct StringNode *next; 		//每个指针4B 
}StringNode,*String;

typedef struct StringNode
{
	char ch[4];		//每个结点存多个字符，存储密度提高 
	struct StringNode *next; 
}StringNode,*String;



