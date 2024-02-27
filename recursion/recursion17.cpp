//sub sequence of string , sub-sequence is similar to subset but relative order of element is same 
#include <iostream>
using namespace std;
void f(string str,int i,string result,int n){
    if(i==n){
        cout<<result<<" ";
        return;
    }
    f(str,i+1,result+str[i],n);  //including element 
    f(str,i+1,result,n);          //not including element
}
int main(){
    string str;
    cin>>str;
    string result="";
    f(str,0,result,str.size());
    return 0;
}