#include "LinkList.h"
#include "string"
#include "iostream"

using namespace std;

//查找单链表某个位置的元素(List,2,&a),将单链表List的第2个位置的元素放入a中
Status GetElem(LinkList L, int location, ElemType &e) {
    //定义一个指针,指向头节点的next,即:指向了真正的第一个结点
    Node *p = L.next;
    //首先排除location<1的情况
    if (location < 1) {
        return ERROR;
    }
    //统计链表的长度
    int count = 1;//计数器.因为当p->NULL时,最后一次循环是进不去的,如果计数器一开始为0就少计数了最后一个结点
    while (p && count < location) {
        //p指向的next不为NULL 且 计数器小于查找位置
        count++;
        p = p->next;
    }
    //如果是因为刚刚好查找到了location元素,此时分为两种情况:
    //那么此时p指向的就是location元素,count==location
    //如果p指向了null,说明已经遍历完了整个单链表,count==单链表长度
    //所以如果p==null && count<location,那么location就是非法位置
    if (!p && count < location) {
        return ERROR;
    }
    e = p->data;
    return OK;
}

//向单链表的某个位置插入元素(List*,2,3),使第2个位置的值为3,其余元素后移
Status ListInsert(LinkList *L, int location, ElemType e) {
    //位置非法
    if (location < 1) {
        return ERROR;
    }
    //定义一个指针,指向头节点的next,即指向第一个数据结点
    Node *p = L->next;
    //计数器
    int count = 1;
    while (p && count < location) {
        count++;
        p = p->next;
    }
    if (!p && count < location) {//插入的位置可以是实际长度
        return ERROR;
    }
    //此时排除了一切非法操作
    //分为两种情况:在链表末尾接一个:p后接一个
    // 不在链表末尾接一个:p此时指向的是需要被插入的位置
    //新造一个结点,这个结点用于存储p的data和next
    //p的data存插入值,next指向新结点
    Node *s = new Node;
    s->data = p->data;
    s->next = p->next;
    p->data = e;
    p->next = s;
    return OK;
}

//删除单链表中的某个结点,(List*,2,e),将List中的第2个结点删除,并将其值放入e中
Status ListDelete(LinkList *L, int location, ElemType &e) {
//合法判断
    if (location < 1 || L->next == nullptr) {
        return ERROR;
    }
//搞两个指针,一个主指针从指向头结点开始,副指针从指向第一个结点开始
//假设要删除第二个元素,那么在主指针指第一个元素时停止,副指针指向第二个要删的那个元素
//取出副指针的data给e,再把副指针的next给主指针的next,最后释放副指针
    int count = 1;//计数器
    Node *p = L;
    Node *q = L->next;
    while (q && count < location) {
        count++;
        p = p->next;
        q = q->next;
    }
    if (!(q->next) && count < location) {
        //副指针指向链表最后一个元素,而location>count,说明要删的结点位置超过了实际长度
        return ERROR;
    }
    e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

//初始化单链表,(*node),将node作为头节点
Status InitList(Node *headNode) {
    headNode->next = nullptr;
    return OK;
}

//创建一个单链表,(headNode ,a,length),将长度为length的数组转为单链表,headNode是头结点
//头插法
Status ListCreateH(Node *headNode, const ElemType arr[], int length) {
    //搞一个p指针,来始终指向单链表的第一个数据结点
    int i = 0;
    Node *p = headNode->next;
    if (headNode->next == nullptr) {
//        如单链表为空,就新建一个结点,给这个结点data存数组第一个值,next为null
//          p指针指向它(这个结点就是现在的第一个数据结点)
        headNode->next = new Node;
        p = headNode->next;
        p->data = arr[i];
        i++;
        p->next = nullptr;
    }
    //此时,无论原链表有没有1个以上数据结点,p指针都指向第一个数据结点
    for (; i < length; i++) {
        //使头结点next指向新结点,并给新结点data赋值
        //新结点next指向p
        //p指向新结点(使p始终指向第一个数据结点)
        headNode->next = new Node;
        headNode->next->data = arr[i];
        headNode->next->next = p;
        p = headNode->next;
    }
    return OK;
}

//尾插法
Status ListCreateE(Node *headNode, const ElemType arr[], int length) {
    Node *p = headNode;
    while (p->next != nullptr) {
        p = p->next;
    };//遍历单链表,使p指向最后一个结点
    for (int i = 0; i < length; i++) {
        p->next = new Node;
        p = p->next;
        p->data = arr[i];
        p->next = nullptr;
    }
    return OK;
}


//删除整个单链表,(L),将L单链表销毁
Status ListDestroy(LinkList *L) {
    Node *p;
    Node *q;
    p = L;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}

//获取单链表长度
Status GetLength(LinkList L, int &length) {
    if (!L.next) {
        //头结点next指向null,说明链表长度为0
        length = 0;
        return ERROR;
    }
    Node *p = L.next;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    length = count;
    return OK;
}

//获取某个元素的位置,ListElemLocate(L,3,location),将链表中,第一个值为3的位置放入location
Status ListElemLocate(LinkList L, ElemType e, int &location) {
    if (!L.next) {
        //头结点next指向null,说明链表长度为0
        return ERROR;
    }
    location = 1;
    Node *p = L.next;
    while (p) {//遍历单链表
//        如果找到了,就赋值 退出
        if (p->data == e) {
            return OK;
        }
        location++;
        p = p->next;
    }
    //如果执行到此处,说明没有要找的,则使location为0,返回false
    location = 0;
    return FALSE;
}

//打印单链表,(L),将单链表打印出来,若单链表为空,则返回False
Status DisplayList(LinkList L) {
    if (!L.next) {
        return FALSE;
    }
    Node *p = L.next;
    while (p) {
        cout << p->data << " ";
        if ((p->next)) {
            cout << "-->  ";
        }
        p = p->next;
    }
    cout << endl;
    return OK;
}