//two numbers are given p&q , find p^q using recursion
#include<bits/stdc++.h>
using namespace std;
//time complexity is O(q), as it calles function Q times,and other operation is constant
// space complexity is O(q), total Q stack frame are there
//can't solve for value of q in decimal , for that we require q to be float
float power(int p,int q){
    if(q==0){
        return 1;
    }
    else if(q<0){
        
        return (power(p,q+1))/p;
    }
    else {
        
        return p*power(p,q-1);
    }
}
int main(){
    int p,q;
    cin>>p>>q;
    float k=power(p,q);
    cout<<k;
    return 0;
}