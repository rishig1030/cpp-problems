//check the number is an palindrome or not, using recursion 
#include<bits/stdc++.h>
using namespace std;
bool f(int n, int *temp){
    if(n>=0 && n<=9){ 
        int lastdigit = (*temp)%10;
        (*temp)/=10;
        return (n == lastdigit);    //compare the first digit with last digit of a number
    }
    bool result= (f(n/10,temp) && (n%10) == ((*temp)%10));  //will call function until n<10,and will compare last digits of each number (that will be reduced upto some digit) with last digit
    *temp/=10;
    return result;
}
int main(){
    int n; cin>>n;
    int copy=n;
    int *pointer=&copy;
    cout<<f(n,pointer);   //we are basically passing same same number
    return 0;
}