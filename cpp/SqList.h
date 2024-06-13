# define MAXSIZE 20  //define后没有';'

#define ERROR 0
#define OK 1
#define FALSE 0//三种状态值

typedef int ElemType;//方便后期需要改变数组类型，在此处可以一键修改
typedef int Status;//定义GetElem函数时用,返回状态值(1或0)
//用SqList来快捷创建一个线性表(含有data[]数组和int length的结构体)
typedef struct {
    ElemType data[MAXSIZE];//线性表的最大长度
    int length;//线性表的当前长度
} SqList;

Status InitList(SqList &sqlist);
Status CreateList(SqList &sqlist,const ElemType *arr,int len);
Status DestroyList(SqList &sqlist);
int GetLenth(SqList &sqlist);
Status GetElem(SqList L,int n,ElemType *e);
int GetLocate(SqList &sqlist,ElemType x);
Status DispList(SqList &sqlist);
Status ListInsert(SqList *sqlist,int n,ElemType e);
Status ListDelete(SqList *sqlist,int n,ElemType *e);
Status ListDelete(SqList *sqlist,int n);