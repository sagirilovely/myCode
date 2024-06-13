#include "SqList.h"
#include "iostream"
#include "string"
using namespace std;




//定义一个函数,用于初始化一个线性表
Status InitList(SqList &sqlist){
    sqlist.length=0;
    if (sqlist.length!=0){
        return ERROR;
    }else{
        return OK;
    }
}
//定义一个函数,传入线性表与数组与数组长度,将线性表的值传入线性表
Status CreateList(SqList &sqlist,const ElemType *arr,int len){
    if(len<=MAXSIZE && len>0){
        for(int i=0;i<len;i++){
            sqlist.data[i]=arr[i];
        }
        sqlist.length=len;
        return OK;
    }else{
        return ERROR;
    }
}
//定义一个函数,销毁一个线性表
Status DestroyList(SqList &sqlist){
    if (sqlist.length==0){
        return ERROR;
    }else{
        sqlist.length=0;
        return OK;
    }
}
//定义一个函数,用于返回传入线性表的长度,
int GetLenth(SqList &sqlist){
    return sqlist.length;
}
//定义一个函数,用于获取线性表中第n个位置对应的值,(不是索引值,index=n-1)
// 传入(SqList线性表,int位置,ElemType *获取到的值)
//GetElem(sqlist,3,e),获取sqlist线性表中第3位的值,放入e中
Status GetElem(SqList L,int n,ElemType *e){
    if(L.length==0 || n<1 || n>L.length){
        return ERROR;
    } else{
        *e=L.data[n-1];
        return OK;
    }
}
//定义一个函数,查找线性表中某个元素是在线性表中排第几个
//int GetLocate(sqlist,3),在sqlist中找出值为3的位置并返回
int GetLocate(SqList &sqlist,ElemType x){
    int locate=-1;//若没找到则返回-1
    for(int i=0;i<sqlist.length;i++){
        if(sqlist.data[i]==x){
            locate= i+1;
        }
    }
    return locate;
}
//定义一个函数,打印线性表
//Status DispList(sqlist),打印出sqlist,返回函数执行状态
Status DispList(SqList &sqlist){
    if(sqlist.length==0){
        return ERROR;
    } else{
        for(int i=0;i<sqlist.length;i++){
            cout<<sqlist.data[i];
            if(i!=sqlist.length-1){
                cout<<" , ";
            }
        }
        cout<<endl;
        return OK;
    }
}
//定义一个函数，用于给线性表某个位置插入一个值
//ListInsert(sqlist,3,66),给sqlist的第3位插入值66，后面的值往后移动一个位置
Status ListInsert(SqList *sqlist,int n,ElemType e){
    if(sqlist->length==MAXSIZE){//线性表不能满了
        return ERROR;
    }else if(n<1 || n>sqlist->length+1){//插入的位置要合法(可以插入在线性表末尾)
        return ERROR;
    }else{//符合插入条件:
        if(n!=sqlist->length+1){//插入位置不在末尾时
            for(int j=(sqlist->length);j>n-1;j--){
                sqlist->data[j]=sqlist->data[j-1];
            }
            sqlist->data[n-1]=e;
            sqlist->length++;
            return OK;
        }else{//插入位置在末尾
            sqlist->data[n-1]=e;//等效于 sqlist->data[sqlist->length]=e;
            sqlist->length++;
            return OK;
        }
    }
}
//定义一个函数,用于删除线性表中某个位置的值
//ListDelete(sqlist,3,*e),将线性表中第3个位置的值删除,并将删除的值赋予e
Status ListDelete(SqList *sqlist,int n,ElemType *e){
    if(sqlist->length==0){//线性表不能为空
        return ERROR;
    }else if(n<1 || n>sqlist->length){//删除的位置要合法(在长度之内的位置)
        return ERROR;
    }else{//符合条件,执行删除:
        *e=sqlist->data[n-1];
        if(n!=sqlist->length){//删除的位置不在最后一位
            for(int j=(n-1);j<(sqlist->length-1);j++){
                sqlist->data[j]=sqlist->data[j+1];
            }
            sqlist->length--;
        }else{//删除的位置在最后一位
            sqlist->length--;//长度减1,不需要改变该位置的元素值
        }
        return OK;
    }
}
Status ListDelete(SqList *sqlist,int n){
    if(sqlist->length==0){//线性表不能为空
        return ERROR;
    }else if(n<1 || n>sqlist->length){//删除的位置要合法(在长度之内的位置)
        return ERROR;
    }else{//符合条件,执行删除:
        if(n!=sqlist->length){//删除的位置不在最后一位
            for(int j=(n-1);j<(sqlist->length-1);j++){
                sqlist->data[j]=sqlist->data[j+1];
            }
            sqlist->length--;
        }else{//删除的位置在最后一位
            sqlist->length--;//长度减1,不需要改变该位置的元素值
        }
        return OK;
    }
}
