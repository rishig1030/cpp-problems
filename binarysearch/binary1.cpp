//binary search statement problem using loop
#include<iostream>
using namespace std;
int f(int arr[],int n,int target){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else {
            right=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,4,23,44,53,233,544,1090};
    int target;
    cin>>target;

    cout<<f(arr,8,target);
    return 0;
}