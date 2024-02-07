//print all the element of array using recursion
#include <bits/stdc++.h>
using namespace std;
//time space complexity is O(n) and space complexity is O(n){ space occupy by stack}
void printele(int arr[],int i,int n){
    if(i==n){
        return ;
    }
    cout<<arr[i]<<" ";
    return printele(arr,i+1,n);
}
int main(){
    int n=6;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printele(arr,0,6);
    return 0;
}