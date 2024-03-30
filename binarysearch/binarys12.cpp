// find the number of times the array is rotated using binary search , with unique element
// bisically the index of minimim element
#include <iostream>
#include <algorithm>
using namespace std;
int f(int arr[],int n){
    int ans=INT16_MAX;
    int ansi=n;
    int left=0; int right =n-1;
    while (left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>arr[left]){
            if(arr[left]<ans){
                ans=arr[left];
                ansi=left;
                
            }
            left=mid+1;
        }
        else{
            if(arr[mid]<ans){
                ans=arr[mid];
                ansi=mid;
                
            }
            right=mid-1;
        }
 
    }
    return ansi;
}
int main(){

    int arr[]={9,10,11,12,13,1,2,3,4,5,6,7,8};
    cout<<f(arr,13);
    return 0;
}