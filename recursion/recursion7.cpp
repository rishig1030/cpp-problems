//sum of all the element in an array using recursion
#include<bits/stdc++.h>
using namespace std;
int f(int arr[],int i,int n){
    if(i== n-1){
        return arr[i];
    }
    return arr[i]+f(arr,i+1,n);  //sum of element + sum of rest of the element
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<f(arr,0,n);
    return 0;
}