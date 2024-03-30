// find minimum in rotated sorted array , should contain the unique elements
#include <iostream>
#include <algorithm>
using namespace std;
int f(int arr[],int n){
    int mini=INT16_MAX;
    int left =0;
    int right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[left]<=arr[right]){
            mini=min(mini,arr[left]);
            break;                       // when left and right both are sorted  ,i.e.  point of rotated array
        }
        if(arr[mid]>=arr[left]){
            mini=min(mini,arr[left]);
            left=mid+1;
        }
        else{
            mini=min(mini,arr[mid]);
            right=mid-1;
        }
    }
    return mini;
}
int main(){
    int arr[]={3,4,5,1,2};
    cout<<f(arr,5);

    return 0;
}