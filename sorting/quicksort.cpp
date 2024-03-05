//quick sort      
//statement : pick an element(pivot) and place it in its correct place
//time complexity is O(n*log(n))  
// space complexity is O(1)
#include <iostream>
using namespace std; 
//function f will find the index
int f(int a[],int left,int right){
    int pivot=a[left];
    int i=left+1; int j=right-1;
    while(i<j){
        while(a[i]<=pivot && i<right){
            i++;
        }
        while(a[j]>pivot && j>left){
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    if(a[left]>=a[j]) 
        swap(a[left],a[j]);
    return j;
}
void quick(int a[],int left,int right){
    if(left<right-1){
        int index=f(a,left,right);
        quick(a,left,index);
        quick(a,index+1,right);
    }
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}