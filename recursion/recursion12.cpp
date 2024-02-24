//check if number is armstrong or not
#include <bits/stdc++.h>
using namespace std;
int f(int n,int d){
    if(n<10 && n>0){
        return pow(n,d);
    }
    return pow(n%10,d)+f(n/10,d);
}
int main(){
    int n;
    cin>>n;
    int d=0;int k=n;
    while(k){
        d++; k/=10;
    }
    if(f(n,d)==n){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}