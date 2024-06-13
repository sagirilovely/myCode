#include "iostream"
#include "vector"
#include "string"
using namespace std;
int forceSearch(int arr[],int length,int x){
    for (int i = 0; i < length; ++i) {
        if (arr[i]==x){
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[],int length,int x){
    int left=0,right=length-1;
    while (left<=right){
        int mid=(right-left)/2+left;
        if(arr[mid]==x){
            return mid;
        }
        else if(x>arr[mid]){
            left=mid+1;
        }
        else if(x<arr[mid]){
            right=mid-1;
        }
    }
    return -1;
}
int main(){
    int n=0;int sum=0;
    cout<<"enter n: ";
    cin>>n;
    cout<<"\n输入n个值: ";
    vector<int> vector1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vector1.push_back(x);
    }
for(int i:vector1){
    sum=sum+i;
}
cout<<n<<"个值的平均值为:"<<(float )sum/(float )n;
}