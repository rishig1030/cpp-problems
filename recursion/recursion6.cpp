//print the max value of an array [3,10,3,2,5]
#include <bits/stdc++.h>
using namespace std;
int max_element(int arr[],int i,int n){
    // we have to determine the max of remaining array and compare it with maximum
    if(i == n-1){
        return arr[i];
    }        
    return max(arr[i],max_element(arr,i+1,n));
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int y= max_element(a,0,n);
    cout<<y;
    return 0;
}