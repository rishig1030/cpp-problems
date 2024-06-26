#include<iostream>
using namespace std;

// set the ith bit
void setithbit(int &n,int i){
    n = n | (1<<i);
}

// clear the ith bit 
void clearithbit(int &n,int i){
    n = n & ~(1<<i);
}

// toggle the ith bit
void toggleithbit(int &n,int i){
    n = n^(1<<i);
}

// remove the last set bit
void removelastsetbit(int &n){
    n = n & (n-1);
}

// check the powerof 2
bool powerof2(int n){
    if((n & (n-1)) == 0) return true;
    else return false;
}

// count the set bits
int countsetbit(int n){
    int count = 0;
    while(n>0){
        count+= n&1;
        n=n>>1;
    }
    return count;
}

int main(){
    int n,i;
    cin>>n>>i;
    setithbit(n,i);
    cout<<n<<endl;

    clearithbit(n,i+1);
    cout<<n<<endl;

    toggleithbit(n,i+2);
    cout<<n<<endl;

    removelastsetbit(n);
    cout<<n<<endl;

    if(powerof2(32)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    cout<<countsetbit(n)<<endl;
    return 0;
}