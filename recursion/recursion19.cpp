//reverse an array using recursion
#include <bits/stdc++.h>
using namespace std;
void f(int arr[],int n,int left){
    if(left>(n-left-1)){
        return;
    }
    swap(arr[left],arr[n-left-1]);
    f(arr,n,left+1);
}
int main(){

    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    f(arr,n,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}