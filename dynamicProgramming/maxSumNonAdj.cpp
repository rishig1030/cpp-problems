// find the maximum sum of non adjacnet element

#include<iostream>
#include<vector>
using namespace std;

// find the sum of adjacent sum of elements using recursion
int maxSum(int n,int arr[]){
    if(n==0) return arr[n];
    if(n<0) return 0;
    int pick = arr[n] + maxSum(n-2,arr);
    int notpick = 0 + maxSum(n-1,arr);

    return max(pick,notpick);
}

// using memoization
int maxSum2(int n,int arr[],int dp[]){
    if(n==0) return dp[n] = arr[n];
    if(n<0) return 0;
    if(dp[n] != -1) return dp[n];
    int pick = arr[n] + maxSum2(n-2,arr,dp);
    int notpick = 0 + maxSum2(n-1,arr,dp);

    return dp[n] = max(pick,notpick);
}

// tabulation - bottom up
int maxSum3(int n,int arr[]){
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        dp[i] = 0;
    }
    
    dp[0] = arr[0];
    for(int i=1;i<n;i++){
        int take = arr[i] ; if(i>1) take += dp[i-2];
        int nottake = 0 + dp[i-1];
        dp[i] = max(take,nottake);
    }
    return dp[n-1];
}

//space optimixation
// we just req two variable dp[i-1] & dp[i-2] 

int maxSum4(int n,int arr[]){
    
    
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = arr[i] ; if(i>1) take += prev2;
        int nottake = 0 + prev;
        prev2 = prev;
        prev = max(take,nottake);
    }
    return prev;
}


int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] = -1;
    }

    cout<<maxSum(n-1,arr)<<endl;
    cout<<maxSum2(n-1,arr,dp)<<endl;
    cout<<maxSum3(n,arr)<<endl;
    cout<<maxSum4(n,arr)<<endl;
    return 0;
}