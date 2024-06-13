#include "QueueLink.h"
#include "string"
#include "iostream"

using namespace std;

// 初始化队列
Status InitQueue(QueueLink *Q) {
    Q->front = Q->rear = new Node(); // 创建头结点,并使头尾指针都指向头结点
    Q->front->next = nullptr; // 初始结点为空
    Q->front->data=0;//头结点的data用来存长度
    return OK;
}

//若队列存在,则销毁它
Status DestroyQueue(QueueLink *Q){
    Node *p=Q->front->next;//指针p指向第一个数据结点
    while (p){//遍历整个队列,直到p指向null,也就是最后一个结点的next
        //临时变量存储,p向后移,释放临时变量..知道p指向null,退出循环
        Node *t=p;
        p=p->next;
        delete(t);
    }
    //此时,就已经删完了除了头结点的所有结点了
    //释放头结点,释放front rear指针
    delete(Q->front);
    delete(Q);
    return OK;
}

//将队列清空
Status ClearQueue(QueueLink *Q){
    Node *p=Q->front->next;//指针p指向第一个数据结点
    while (p){//遍历整个队列,直到p指向null,也就是最后一个结点的next
        //临时变量存储,p向后移,释放临时变量..知道p指向null,退出循环
        Node *t=p;
        p=p->next;
        delete(t);
    }
    //此时,就已经删完了除了头结点的所有结点了
    //再将rear指回头结点,更新元数据
    Q->rear=Q->front;
    Q->front->data=0;
    return OK;
}

//判断队列是否为空
Status QueueIsEmpty(QueueLink Q){
    if(Q.front==Q.rear){
        return TRUE;
    }else{
        return FALSE;
    }
}

//入队列
Status QueueAdd(QueueLink *Q,ElemType e){
    //搞一个新结点,让尾结点的next指向新结点
    //再将rear指针后移到新节点
    //更新数据
    Q->rear->next=new Node();
    Q->rear=Q->rear->next;
    Q->rear->data= e;
    Q->rear->next= nullptr;
    Q->front->data=Q->front->data+1;
    return OK;
}

//出队列
Status QueuePop(QueueLink *Q,ElemType &e){
    if (Q->front==Q->rear){//队列为空,返回错误状态
        return ERROR;
    }else if(Q->front->data==1){//如果队列就剩下一个了,那么出去的结点也是最后一个,就是rear指向的
//        所以此时还需要更新rear的指向
        Q->rear=Q->front;
    }
    //临时指针记下第一个数据结点
    //将第一个数据结点的数据拿出来
    //让头节点next指向第二个数据结点
    //释放第一个数据结点
    Node *t=Q->front->next;//此时t存储着第一个数据结点
    e=t->data;
    Q->front->next=t->next;
    delete(t);
    Q->front->data=Q->front->data-1;//更新元数据
    return OK;
}

//获取头元素值(不删除,只查看)
Status QueueGetHead(QueueLink Q,ElemType &e){
    if (Q.front==Q.rear){
      return  ERROR;
    }else{
        e=Q.front->next->data;
        return OK;
    }
}

//获取队列元素个数(不包括头结点)
Status QueueLength(QueueLink Q,int &length){
    length=Q.front->data;
    return OK;
}

//将一个数组转为队列
Status ArrToQueueLink(QueueLink *Q,ElemType arr[],int length){
    for (int i = 0; i < length; ++i) {
        QueueAdd(Q,arr[i]);
    }
    return OK;
}
//打印队列
Status DisplayQueueLink(QueueLink Q){
    if (Q.front==Q.rear){
        return  ERROR;
    }else{
        Node *p=Q.front->next;
        while (p){
            cout<<p->data;
            if (p->next){
                cout<<" --> ";
            }
            p=p->next;
        }
    }
    cout<<endl;
    return OK;
}