// find minimum in rotated sorted array , with duplicate element 
//do it yourself
//find element in duplicate has already have a concept to tackle with duplicate element
#include <iostream>
#include <algorithm>
using namespace std;

int f(int arr[],int n){

    int left = 0;
    int right = n-1;
    int mini=INT16_MAX;
    while(left<=right){

        int mid = (left+right)/2;
        
        mini= min(mini,arr[mid]);
        if(arr[mid]>arr[left]){
            mini=min(mini,arr[left]);
            left=mid+1;
        }
        else {
            mini=min(mini,arr[mid]);
            right= mid-1;
        }
        
        

    }
    return mini; 

}

int main(){
    int arr[]={4,5,5,6,7,8,8,8,8,8,2,2,2,3,4,4,4};
    cout<<f(arr,17);
    return 0;
}