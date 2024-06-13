#include "DuLinkList.h"
#include "iostream"

//初始化双链表
Status DuLinkListInit(DuLinkList *DL){
    DL->data=0;
    DL->prior=DL;
    DL->next=DL;
    return OK;
}
//判断是否为空,空返回TRUE
Status DuLinkListIsEmpty(DuLinkList *DL){
    if (DL->data==0){
        return TRUE;
    }else{
        return FALSE;
    }
}

//销毁双链表
Status DuLinkListDestroy(DuLinkList *DL){
    DuLinkNode *p=DL->next;//p指针指向第一个数据结点
    while (p!=DL){//销毁除了头结点外的所有结点
        DL->next=p->next;
        p->next->prior=DL;
        delete(p);
        p=DL->next;
    }
    //销毁头结点
    delete(p);
    return OK;
}

//获取某个位置的元素
Status DuLinkListGetElem(DuLinkList *DL,int location,ElemType &e){
    DuLinkNode *p=DL->next;//p指针指向第一个数据结点
    int count=1;
    while (p!=DL){
        if(location==count){
            e=p->data;
            return OK;
        }
        p=p->next;
        count++;
    }
    return ERROR;
}

//查找某个元素是否在链表中,并拿到位置
Status DuLinkListIsExist(DuLinkList *DL,ElemType e,int &location){
    DuLinkNode *p=DL->next;//p指针指向第一个数据结点
    int count=1;
    while (p!=DL){
        if(p->data==e){
            location=count;
            return TRUE;
        }
        p=p->next;
        count++;
    }
    location=-1;
    return FALSE;
}

//在某个位置插入一个元素
Status DuLinkListInsertElem(DuLinkList *DL,int location,ElemType e){
    DuLinkNode *p=DL->next;//p指针指向第一个数据结点
    int count=1;
    while (p!=DL){
        if(count==location){
            DuLinkNode *q=new DuLinkNode ;
            q->data=e;
            q->prior=p->prior;
            p->prior->next=q;
            q->next=p;
            p->prior=q;
            DL->data++;
            return OK;
        }
        p=p->next;
        count++;
    }
    return ERROR;
}
//头插元素
Status DuLinkListInsertHead(DuLinkList *DL,ElemType &e){
    DuLinkNode *p=DL->next;//p指针指向第一个数据结点
    DuLinkNode *q=new DuLinkNode ;
    q->data=e;
    DL->next=q;
    q->prior=DL;
    p->prior=q;
    q->next=p;
    DL->data++;
    return OK;
}
//尾插元素
Status DuLinkListInsertEnd(DuLinkList *DL,ElemType &e){
    DuLinkNode *p=DL->prior;//p指针指向最后一个数据结点
    DuLinkNode *q=new DuLinkNode ;
    q->data=e;
    p->next=q;
    q->prior=p;
    q->next=DL;
    DL->prior=q;
    DL->data++;
    return OK;
}
//将一个数组转成双链表
Status ArrToDuLinkList(DuLinkList *DL,ElemType arr[],int arrLength){
    for(int i=0;i<arrLength;i++){
        DuLinkListInsertEnd(DL,arr[i]);
    }
    return OK;
}

//删除某个位置的元素
Status DuLinkListDeleteElem(DuLinkList *DL,int location){
    DuLinkNode *p=DL->next;//p指针指向第一个数据结点
    int count=1;
    while (p!=DL){
        if(location==count){
            p->prior->next=p->next;
            p->next->prior=p->prior;
            delete(p);
            DL->data--;
            return OK;
        }
        count++;
        p=p->next;
    }
    return ERROR;
}
//打印链表
Status DuLinkListDisplay(DuLinkList *DL){
    DuLinkNode *p=DL->next;//p指针指向第一个数据结点
    while (p!=DL){
        cout<<p->data;
        if(p->next != DL){
            cout<<" -> ";
        }
        p=p->next;
    }
    cout<<endl;
    return OK;
}
//返回元素个数
Status DuLinkListGetLength(DuLinkList *DL){
    return DL->data;
}
//逆序双链表
Status DuLinkListReverse(DuLinkList *DL){
    DuLinkNode *p = DL->next; // p指针指向第一个数据结点
    DuLinkNode *temp = nullptr;
    do {
        temp = p->next;
        p->next = p->prior;
        p->prior = temp;
        p = temp; // 更新p指针
    } while (p != DL); // 循环直到回到哨兵节点

    // 交换哨兵节点的next和prior指针
    temp = DL->next;
    DL->next = DL->prior;
    DL->prior = temp;
    return OK;
}



