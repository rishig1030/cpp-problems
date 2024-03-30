//search an element in an rotated sorted array  , should contain unique elements in this case
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
        else if(arr[mid]>=arr[left]){
            if(target>=arr[left] && target<=arr[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        else 
        {
            if(target>=arr[mid] && target<=arr[right]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int arr[]={7,8,9,1,2,3,4,5,6};
    int target;
    cin>>target;
    cout<<f(arr,9,target);
    return 0;
}