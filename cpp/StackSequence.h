# define MAXSIZE 20

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0//四种状态值

typedef int Status;//定义GetElem函数时用,返回状态值(1或0)
typedef int ElemType;

//顺序栈
typedef struct {
    ElemType data[MAXSIZE];
    int top; //记录栈顶元素的数组下标
}SqStack;

//初始化栈
Status InitStack(SqStack *S);

//销毁栈
Status Destroy(SqStack *S);

//清空栈
Status ClearStack(SqStack *S);

//若栈为空则返回TRUE,否则返回FALSE
Status StackEmpty(SqStack *S);

//若栈存在且非空,用e返回S的栈顶元素
Status GetTop(SqStack *S,ElemType &e);

//若栈存在,压入新元素
Status Push(SqStack *S,ElemType e);

//给栈压入数组
Status PushArr(SqStack *S,const ElemType arr[],int length);

//若栈存在,弹出元素
Status Pop(SqStack *S ,ElemType &e);

//返回栈的元素个数
Status StackLength(SqStack *S,int count);

//打印出栈的元素
Status DisplayStack(SqStack *S);
