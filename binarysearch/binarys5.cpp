//floor : larget number in the array <= target
//ceil : smallest number in array >= target
//determine floor and ceil in an array
//time complexity is O(log2N)
#include<iostream>
using namespace std;

int ceil(int arr[],int left,int right,int target,int n){

    if(left>right){
        return n;
    }
    int mid=(left+right)/2;
    if(arr[mid]==target){
        return arr[mid];
    }
    else if(arr[mid]<target){
        
        return ceil(arr,mid+1,right,target,n);
    }
    else {
        n=arr[mid];
        return ceil(arr,left,mid-1,target,n);
    }
    
}

int floor(int arr[],int left,int right, int target,int n){
    if(left>right){
        return n;
    }
    int mid=(left+right)/2;
    if(arr[mid]==target){
        return target;
    }

    else if(arr[mid]>target){
        return floor(arr,left,mid-1,target,n);
    }
    else {
        n=arr[mid];
        return floor(arr,mid+1,right,target,n);
    }

}

int main(){
    int arr[]={1,26,37,43,54};
    int target;
    cin>>target;
    cout<<"floor = "<<floor(arr,0,4,target,-1)<<endl;
    cout<<"ceil = "<<ceil(arr,0,4,target,-1);
    return 0;
}
    