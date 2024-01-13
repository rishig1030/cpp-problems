//sort an aray with 0s & 1s (two pointers)
#include<iostream>
#include<vector>
using namespace std;
void sort(vector <int> &v){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0) count++;
    }
    for(int i=0;i<v.size();i++){
        if(i<count){
            v[i]=0;
        }
        else v[i]=1;
    }
}
int main(){
    vector <int> v(5);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    sort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}