
#include<iostream>
using namespace std;

// check if the ith bit is set or not
bool check(int n,int i){
    // using left shift
    if((n & 1<<i) != 0) return true;
    else return false;
    // using right shift
    if((n>>i & 1) != 0) return true;
    else return false;
    
}



// swap two number without using third variable
// by using XOR property a^a = 0

void swapit(int a,int b){
    a = a^b;  // 
    b = a^b;   // a^b ^ b = a
    a = a^b;    // a^b ^ a = b
    cout<<a<<" "<<b;
    return ;
}
int main(){
    int a,b; 
    cin>>a>>b;
    swapit(a,b);

    int n;
    cin>>n;
    if(check(n,4)) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}