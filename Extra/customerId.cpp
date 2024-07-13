// shoudl be three digit long , and first and last digit should be add up and divisible by the number
#include<iostream>
using namespace std;

void find(int &fd,int &ld,int n){
    ld = n%10;
    while(fd/10 != 0){
        fd /= 10;
    }
}

int solve(int n){
    int result = -1;
    int fd = n;
    int ld = 0;
    find(fd,ld,n);

    int count = 1;
    while((n%(fd*10 + ld)) != 0){
        n -= count;
        if(n>99)
        find(fd,ld,n);
        
        if((n%(fd*10 + ld)) != 0){
            n += (2*count);
            find(fd,ld,n);
        }
        count++;
    }
    result = n;
    return result;
}

int main(){
    int n;
    cin>>n;

    cout<<solve(n)<<endl;

    return 0;

}
