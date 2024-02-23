//greatest common divisor (gdc) bw two number
#include <bits/stdc++.h>
using namespace std;
//this problem is based on EUCLID's Algorithem
//which states that if we subtract smaller number from larger number, the gcd remains same 
// or by division instead of subtrction
int f(int x,int y){
    if(x==y){
        return x;
    }
    if(x<y){
        return f(x,y-x);     // return f(x,y%x)
    }
    else return f(x-y,y);    // return f(x%y,x)
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<f(x,y);
    return 0;
}