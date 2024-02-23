//write n and its multiple k times
#include<iostream>
using namespace std;
void f(int n,int k){
    if(k==0){
        return ;
    }
    return f(n,k-1);
    cout<<n*k<<" ";
}
int main(){
    int n,k; cin>>n>>k;
    f(2,3);
    return 0;
}