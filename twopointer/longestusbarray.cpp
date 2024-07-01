// find the longest subarray whose sum is less than k
#include<iostream>
using namespace std;

int length(int arr[],int n,int k){
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxlen = 0;
    while(r<n){
        sum += arr[r];
        if(sum>k){
            sum -= arr[l];
            l++;
        }
        if(sum<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<"length of longest subarray is "<<length(arr,n,k);
    return 0;
}