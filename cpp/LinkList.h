# define MAXSIZE 20

#define ERROR 0
#define OK 1
#define FALSE 0//三种状态值

typedef int Status;//定义GetElem函数时用,返回状态值(1或0)
typedef char ElemType;

//头结点用于存储链表的元数据,不用作存储数据,第一个位置结点指头节点之后的那个
typedef struct Node{
    ElemType data;
    struct Node *next;
}LinkList;

//查找单链表某个位置的元素(List,2,&a),将单链表List的第2个位置的元素放入a中
Status GetElem(LinkList L,int location,ElemType &e);

//向单链表的某个位置插入元素(List*,2,3),往List的第2个位置插入值3
Status ListInsert(LinkList *L,int location,ElemType e);

//删除单链表中的某个结点,(List*,2,e),将List中的第2个结点删除,并将其值放入e中
Status ListDelete(LinkList *L, int location, ElemType &e);

//初始化单链表,(*node),将node作为头节点
Status InitList(Node *headNode);

//创建一个单链表,(headNode ,a,length),将长度为length的数组转为单链表,headNode是头结点
//头插法
Status ListCreateH(Node *headNode,const ElemType arr[],int length);
//尾插法
Status ListCreateE(Node *headNode,const ElemType arr[],int length);


//删除整个单链表,(L),将L单链表销毁
Status ListDestroy(LinkList *L);

//获取单链表长度,(L,length),将L链表的长度放入length中
Status GetLength(LinkList L,int &length);

//获取某个元素的位置ListElemLocate(L,3,location),将链表中,第一个值为3的位置放入location
Status ListElemLocate(LinkList L, ElemType e, int &location);

//打印单链表,(L),将单链表打印出来,若单链表为空,则返回False
Status DisplayList(LinkList L);