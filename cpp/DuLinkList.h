#include <cstdlib>
#include "iostream"
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0//四种状态值
using namespace std;
typedef int Status;//定义GetElem函数时用,返回状态值(1或0)
typedef int ElemType;

//循环双链表结构
typedef struct DuLinkList {
    ElemType data;//头结点数据域用于存长度
    DuLinkList *prior;
    DuLinkList *next;
}DuLinkNode,DuLinkList;

//初始化双链表
Status DuLinkListInit(DuLinkList *DL);
//判断是否为空,空返回TRUE
Status DuLinkListIsEmpty(DuLinkList *DL);

//销毁双链表
Status DuLinkListDestroy(DuLinkList *DL);

//获取某个位置的元素
Status DuLinkListGetElem(DuLinkList *DL,int location,ElemType &e);

//查找某个元素是否在链表中,并拿到位置
Status DuLinkListIsExist(DuLinkList *DL,ElemType e,int &location);

//在某个位置插入一个元素
Status DuLinkListInsertElem(DuLinkList *DL,int location,ElemType e);
//头插元素
Status DuLinkListInsertHead(DuLinkList *DL,ElemType &e);
//尾插元素
Status DuLinkListInsertEnd(DuLinkList *DL,ElemType &e);
//将一个数组转成双链表
Status ArrToDuLinkList(DuLinkList *DL,ElemType arr[],int arrLength);

//删除某个位置的元素
Status DuLinkListDeleteElem(DuLinkList *DL,int location);
//打印链表
Status DuLinkListDisplay(DuLinkList *DL);
//返回元素个数
Status DuLinkListGetLength(DuLinkList *DL);
//逆序双链表
Status DuLinkListReverse(DuLinkList *DL);