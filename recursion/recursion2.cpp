//use recursion to find the nth fibonacci number strign from 0. 
#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n){
    if(n==1 || n==0){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n;
    cin>>n;
    int y=fibonacci(n);
    cout<<y;
    return 0;
}