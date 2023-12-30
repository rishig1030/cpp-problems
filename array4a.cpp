//another method to rotate an array k times
#include<iostream>
#include<vector>
#include<algorithm>//for reverse operation
using namespace std;
int main(){
    vector <int> v;
    v={1,2,3,4,5};
    int k;
    cin>>k;
    k=k%v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());

    for(int a:v){
        cout<<a<<" ";
    }
    return 0;
}
//reverse operation reverse(v.begin(),v.end()) only for vector
//1,2,3,4,5 by reversing the whole array and then reverse the part of it