//first and last occurence without the use if lower and upper bound

#include <iostream>
using namespace std;
pair<int,int> firstnlast(int arr[],int n,int target){
    int left=0,right=n-1;
    int low=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            low=mid;
            right=mid-1;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    left=0;right=n-1;
    int upper=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            upper=mid;
            left=mid+1;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return {low,upper};
}
int main(){

    int arr[]={2,2,3,4,5,5,5,5,6,7,9};
    int target;cin>>target;
    cout<<firstnlast(arr,11,target).first<<" "<<firstnlast(arr,11,target).second;
    cout<<endl<<"Number of occurence of target number is "<<firstnlast(arr,11,target).second+1-firstnlast(arr,11,target).first;
    return 0;
}