//binary search using recursion
#include<iostream>
using namespace std;
int f(int arr[],int target,int left,int right){
    int mid=(left+right)/2;
    if(left>right){
        return -1;
    }
    if(target==arr[mid]){
        return mid;
    }
    else if(target>arr[mid]){
        return f(arr,target,mid+1,right);
    }
    else{
        return f(arr,target,left,mid-1);
    }
    
}
int main(){
    int arr[]={2,3,45,56,75,89,223,424,544};
    int target;
    cin>>target;
    cout<<f(arr,target,0,9);
    return 0;
}