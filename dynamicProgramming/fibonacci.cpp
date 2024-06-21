// fibonaci series
#include<iostream>
#include<vector>
using namespace std;

int fibonacci(int i,vector<int>&dp){
    if(i==0|| i==1){
        return dp[i] = i;
    }
    
    if(dp[i] != -1) return dp[i];
    else return dp[i] = fibonacci(i-1,dp)+fibonacci(i-2,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    vector<int> dp(n+1,-1);
    for(int i=0;i<n;i++){
        v.push_back(fibonacci(i,dp));
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}