#include "StackSequence.h"
#include "string"
#include "iostream"

using namespace std;

//初始化栈
Status InitStack(SqStack *S){
    S->top=-1;
    return OK;
}

//销毁栈
Status Destroy(SqStack *S){
    free(S);
    return OK;
}

//清空栈
Status ClearStack(SqStack *S){
    S->top=-1;
    return OK;
}

//若栈为空则返回TRUE,否则返回FALSE
Status StackEmpty(SqStack *S){
    if (S->top==-1){
        return TRUE;
    }else {
        return FALSE;
    }
}

//若栈存在且非空,用e返回S的栈顶元素
Status GetTop(SqStack *S,ElemType &e){
    if (!StackEmpty(S)){
        e=S->data[S->top];
        return OK;
    }else{
        return ERROR;
    }
}

//若栈存在空间,压入新元素
Status Push(SqStack *S ,ElemType e){
    if (S->top==MAXSIZE-1){//栈满
        return ERROR;
    }else{
        S->top++;
        S->data[S->top]=e;
        return OK;
    }
}

//给栈压入数组
Status PushArr(SqStack *S,const ElemType arr[],int length){
    if (MAXSIZE-(S->top)-1 < length){
        return ERROR;
    }else{
        for(int i=0;i<length;i++){
            S->top++;
            S->data[S->top]=arr[i];
        }
    }
    return OK;
}

//若栈存在元素,弹出元素
Status Pop(SqStack *S ,ElemType &e){
    if (S->top==-1){
        return ERROR;
    }else{
        e=S->data[S->top];
        S->top--;
        return OK;
    }
}

//返回栈的元素个数
Status StackLength(SqStack *S,int count){
    count= S->top+1;
    return OK;
}

//打印出栈的元素
Status DisplayStack(SqStack *S){
    if(S->top==-1){
        return ERROR;
    }
    for(int i=0;i<=S->top;i++){
        cout<<S->data[i];
        if(i!=S->top){
            cout<<" , ";
        }
    }
    return OK;
}