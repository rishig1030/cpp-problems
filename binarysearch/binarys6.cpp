//find the first and last occurence of a element in a sorted array

//first approach :
// we can iterate the whole array if(a[i]==target) first=i(if(fisrt==-1)) and last =i;

//second approach : 
//by using the concept of lower bound(smallest index greater than equal to target)
// upper bound (smallest index greater than target)
// our desried array would be { lb , ub-1 }  but this will only work if it exist in array (lower bound)
#include <iostream>
using namespace std;

int lowerbound(int arr[],int left,int right,int target,int n){
    if(left>right){
        return n;
    }
    int mid=(left+right)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        n=mid;
        return lowerbound(arr,left,mid-1,target,n);
    }
    else {
        return lowerbound(arr,mid+1,right,target,n);
    }

}

int upperbound(int arr[],int left,int right,int target,int n){

    if(left>right){
        return n;
    }

    int mid=(left+right)/2;
    if(arr[mid]>target){
        n=mid;
        return upperbound(arr,left,mid-1,target,n);

    }
    else {
        return upperbound(arr,mid+1,right,target,n);
    }

}

pair<int,int> first_last(int arr[],int n,int target){
    int lb = lowerbound(arr,0,n-1,target,n);
    int up = upperbound(arr,0,n-1,target,n);

    // if( lower bound is n or target in not in an array i.e lowerbound element != target) 
    if(lb == n || arr[lb] != target){
        return {-1,-1};
    }
    else return {lb,up-1};
}
int main(){
    int arr[] = {2,4,6,8,8,8,11,13};
    int target;
    cin>>target;
    cout<<first_last(arr,8,target).first<<" ";
    cout<<first_last(arr,8,target).second;
    return 0;
}