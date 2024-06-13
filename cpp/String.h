#include "iostream"
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0//四种状态值
#define MAXSIZE 100
using namespace std;
typedef int Status;//定义GetElem函数时用,返回状态值(1或0)
typedef char ElemType;
typedef struct{
    char data[MAXSIZE];
    int len;
}String;
//打印字符串
Status DisplayString(String s);


//将一个字符数组转成String
Status StrAssign(String &s,const char c[],int length);


//销毁字符串
Status DestroyString(String &s);


//将串t复制给s
Status CopyString(String &s,String t);


//返回字符串的长度
Status GetLenString(String s);


//判断两个串是否相等
Status IsEqualString(String s,String t);


//连接两个串,并返回新串,s在前,t在后
Status ConcatString(String s,String t,String &newString);


//返回串s中,第start个位置到第end个位置之间的串(左闭右开)
Status SubString(String s,int start,int end,String &n);


//返回字串t在主串s中的位置
Status GetIndexString(String s,String t);


//将子串t插入到主串s的start位置
Status InsertString(String &s,String t,int start);


//将串中[start,end]的串删除
Status DeleteString(String &s,int start,int end);

//使用RK算法,在主串s中找出所有字串t的位置,位置放入arr数组中
Status GetIndexArrStringRK(String s,String t,int arr[]);

//将主串s中的s1串都替换成s2
Status ReplaceString(String &s,String s1,String s2);



