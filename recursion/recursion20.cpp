#include<bits/stdc++.h>
using namespace std;
bool f(string s,int i,int n){
    if(i>= n/2){
        return true;
    }
    if(s[i]==s[n-i-1] && f(s,i+1,n)) {
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s;
    cin>>s;
    cout<<f(s,0,s.size());
    return 0;
}