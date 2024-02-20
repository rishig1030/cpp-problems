//remove all the occurrences of 'a' from string , uisng recursion
#include<bits/stdc++.h>
using namespace std;
string f(string str,int i,int n){
    //removing all the element form index i to str.size()-1 (bigger problem)
    if(i== n){
        return "";    
    }
    if(str[i]!='a'){
        return str[i]+f(str,i+1,n); // adding element if not equal to a
    }
    else return "" + f(str,i+1,n);   // adding element if equal to a

    // instead of this if else we could've used
    // return ((str[i]=='a') ? "" : str[i]) + f(str,i+1,n)
}
int main(){
    string str; char ch;
    cin>>str;
    
    cout<<f(str,0,str.size());
    return 0;
}