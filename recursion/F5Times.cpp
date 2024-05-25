//write name five times
#include<iostream>
using namespace std;

void fivetimes(int n){
    if(!n){
        return;
    }
    else{
        cout<<6-n<<". Rishi"<<endl;
        fivetimes(--n);
    }
}
int main(){
    int n=5;
    fivetimes(n);
    return 0;
}