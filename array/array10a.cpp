//suffix sum and prefix sum
#include<bits/stdc++.h>
using namespace std;
bool sum(vector <int> &v){
    int ts=0;
    for(int i=0;i<v.size();i++){
        ts+=v[i];
    }
    int ps=0;
    for(int i=0;i<v.size();i++){
        ps+=v[i];
        
        if(ps*2 == ts){
            return true;
        }
    }
    return false;
}
int main(){
    vector <int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    cout<<sum(v);
    return 0;
}