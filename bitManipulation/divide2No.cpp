// divide two numbers without using / or *
#include<iostream>
using namespace std;


// break down in powers of 2
// 22/3 , 3*(2^2) + 3*(2^1) + 3(2^0) , in total we are removing 3 , 7 times
int ans(int dividend,int divisor){
    if(dividend == divisor) return 1;
    long long ans = 0;
    bool sign = true;
    if(dividend>=0 && divisor<0) sign = false;
    if(dividend<0 && divisor>0) sign = false;
    dividend = abs(dividend);
    divisor = abs(divisor);

    // time complexity is O(LogN * 32 ) || (O(logN))^2
    while(dividend>=divisor){
        int count = 0;
        while(dividend>= (divisor*(1<<count+1))){
            count++;
        }
        ans+=1<<count;
        dividend-= divisor*(1<<count);
    }
    if(ans==(1<<31) && sign) return INT16_MAX;
    if(ans==(1<<31) && !sign) return INT16_MIN;
    return sign?ans:(-1)*ans;
}

int main(){
    int dividend;
    cin>>dividend;
    int divisor;
    cin>>divisor;
    cout<<ans(dividend,divisor)<<endl;
    return 0;
}