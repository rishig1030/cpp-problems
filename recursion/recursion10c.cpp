//given a sum of seires from 1 to n with alternator sign
#include <iostream>
using namespace std;
int f(int n){
    if(n==0){
        return 0;
    }
    
    if(n%2==0){
        return -n+f(n-1);
    }
    else{
        return n+f(n-1);
    }
}
int main(){
    int n; cin>>n;
    cout<<f(n);
    return 0;
}