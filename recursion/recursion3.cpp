//find the sum of digits of a number using recursion
#include <bits/stdc++.h>
using namespace std;
int sumof(int n){
    if(n==0){
        return 0;
    }
    return n%10+sumof(n/10);
}
int main(){
    int x;cin>>x;
    int a=sumof(x);
    cout<<a;
    return 0;
}