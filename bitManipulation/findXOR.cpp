// find the XOR of all the numbers from 1 to N
#include<iostream>
using namespace std;

int Xor(int n){
    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n;
}

int xorInRange(){
    int l,r;
    cin>>l>>r;
    return Xor(l-1)^Xor(r);
}

int main(){
    int n;
    cin>>n;
    // to find the XOR from 1 to N
    cout<<Xor(n)<<endl;

    cout<<xorInRange();

    return 0;
}