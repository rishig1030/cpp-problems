// find the unique number present in an array which only contain the number in triplet
#include<iostream>
#include<vector>
using namespace std;

int findunique(vector<int> v){
    int n  = 0;
    // check every bit of every element , 
    for(int bi=0;bi<32;bi++){
        int  count = 0;

        for(int i=0;i<v.size();i++){
            if(v[i] & (1<<bi)) count++;
        }
        // if some of bit of all the element in that perticular element is not multiple of 3 ,
        // that bit is not set for the unique element
        if(count%3 == 1){
            n = n|(1<<bi);
        } 
    }
    return n;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    cout<<findunique(v);
    return 0;
}
