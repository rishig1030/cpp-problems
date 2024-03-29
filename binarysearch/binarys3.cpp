//lower bound problem
//write an minimum index which has number greater than equal to target value
// by recursion method 
//for iterative method use while(left<=high) {  and so on  }7
#include<iostream>
using namespace std;
int f(int arr[],int left,int right,int target,int n){
    if(left>right){
        return n;
    }
    int mid=(left+right)/2;
    if(arr[mid]>=target){
        n=mid;
        return f(arr,left,mid-1,target,n);   //this may be my answer but need smaller index
    }
    else{
        return f(arr,mid+1,right,target,n);  //this means lesser , hence move to right side of array
    }
}
int main(){
    int arr[]={3,4,12,19,40,40,54,54};
    int target;
    cin>>target;
    cout<<f(arr,0,7,target,8);
    return 0;
}
//time complexity is same as binary search
//if we need to find an indedx of a number to be inserted in an array while maintaining its sorted order
//basically it can be solved by lower bound