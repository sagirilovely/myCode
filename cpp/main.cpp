# include "iostream"
using namespace std;
#include "SqList.h"

void changeMaxMin(SqList &sq){
    ElemType maxValue,minValue;
    int maxLocation,minLocation;
    for(int location=1;location<= GetLenth(sq);location++){
        ElemType value;
        GetElem(sq,location,&value);
        if(location==1){
            maxValue=value;
            minValue=value;
        }
        if(value>maxValue){
            maxValue=value;
            maxLocation=location;
        }
        if(value<minValue){
            minValue=value;
            minLocation=location;
        }
    }
    ListDelete(&sq,maxLocation);
    ListInsert(&sq,maxLocation,minValue);
    ListDelete(&sq,minLocation);
    ListInsert(&sq,minLocation,maxValue);
}
int main(){
    SqList sq;
    InitList(sq);
    ElemType arr[5]={3,2,9,4,7};
    CreateList(sq,arr,5);
    DispList(sq);
    changeMaxMin(sq);
    DispList(sq);
}