//print the sum of all the subset present in the array
//and print it in sorted order
#include<bits/stdc++.h>
using namespace std;

void f(int i,int arr[],int n,vector<int> &v,int sum){
    if(i==n){
        v.push_back(sum);
        return ;
    }
    
    sum = sum+ arr[i];
    f(i+1,arr,n,v,sum);
    sum = sum-arr[i];
    f(i+1,arr,n,v,sum);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    int sum =0;
    f(0,arr,n,v,sum);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}

//time complexity will be - O((2^N)*log(2^N))
//space complexity is -  O(2^N + N(stack space))