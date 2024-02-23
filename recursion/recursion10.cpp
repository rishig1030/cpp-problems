//write a number from 1 to n
#include<iostream>
using namespace std;
void f(int n){
    if(n<=1){
        cout<<1<<" ";
        return ;
    }
    f(n-1);
    cout<<n<<" ";
}
int main(){
    long n; cin>>n;
    f(n);
    return 0;
}