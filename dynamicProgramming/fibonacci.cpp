// fibonaci series
#include<iostream>
#include<vector>
using namespace std;


// memoisation method
// time complexity - O(N)
// space complecity - O(N) + O(N) = O(2N) , recursion stack space and array
int fibonacci(int i,vector<int>&dp){
    if(i==0|| i==1){
        return dp[i] = i;
    }
    
    if(dp[i] != -1) return dp[i];
    else return dp[i] = fibonacci(i-1,dp)+fibonacci(i-2,dp);
}

// tabulation
// time complexity is O(N)
// space complexity is O(N)
int fibonacci1(int n){
    vector<int> dp(n+1);
    dp[0] = 0; dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// more optimized solution 
// time complexity is O(N)
// space complexity is O(1)
int fibonacci2(int n){
    
    int previous2 = 0;
    int previous = 1;
    if(n==0) return previous2;
    else if(n==1) return previous;
    int ans;
    for(int i=2;i<=n;i++){
        ans = previous2 + previous ;
        previous2 = previous;
        previous = ans;
    }
    return ans;
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
    cout<<endl;
    for(int i=0;i<n;i++){
        v[i] = (fibonacci1(i));
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        v[i] = (fibonacci2(i));
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}