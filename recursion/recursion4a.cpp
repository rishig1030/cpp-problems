//find p^q with lesser time complexity 
#include<bits/stdc++.h>
using namespace std;
//time complexity is O(log q) 
float power(int p,int q){
    if(q==0){
        return 1;
    }
    else if(q%2==0 && q>0){
        int y=power(p,q/2);
        return y*y;
    }
    else if(q%2!=0 && q>0) {
        int y=power(p,(q-1)/2);
        return p*y*y;
    }
    else if(q%2==0 && q<0){
        float y=power(p,q/2);
        return y*y;
    }
    else if(q%2!=0 && q<0) {
        float y=power(p,(q+1)/2);
        return y*y/p;
    }
}
int main(){
    int p,q;
    cin>>p>>q;
    float k=power(p,q);
    cout<<k;
    return 0;
}