#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0//四种状态值

typedef int Status;//定义GetElem函数时用,返回状态值(1或0)
typedef int ElemType;

// 链式结构队列节点
typedef struct Node {
    ElemType data;
    Node *next;
}Node;

// 链式结构队列
typedef struct QueueLink {
    Node *front;
    Node *rear;
    // 其他队列相关的成员
}QueueLink;
//初始化队列
Status InitQueue(QueueLink *Q);

//若队列存在,则销毁它
Status DestroyQueue(QueueLink *Q);

//将队列清空
Status ClearQueue(QueueLink *Q);

//判断队列是否为空
Status QueueIsEmpty(QueueLink Q);

//入队列
Status QueueAdd(QueueLink *Q,ElemType e);

//出队列
Status QueuePop(QueueLink *Q,ElemType &e);

//获取对头元素值(不删除,只查看)
Status QueueGetHead(QueueLink Q,ElemType &e);

//获取队列元素个数(不包括头结点)
Status QueueLength(QueueLink Q,int &length);

//将一个数组转为队列
Status ArrToQueueLink(QueueLink *Q,ElemType arr[],int length);

//打印队列
Status DisplayQueueLink(QueueLink Q);
