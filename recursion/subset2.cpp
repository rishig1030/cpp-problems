
//find all the subset of an array with duplicate values and no subset should repeat twice

#include<bits/stdc++.h>
using namespace std;

void f(int index,vector<int> arr,int n,vector<int> v){
    if(index <= n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=index;i<n;i++){
        if(i>index && arr[i]==arr[i-1]) continue;

        v.push_back(arr[i]);
        f(i+1,arr,n,v);
        v.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    sort(arr.begin(),arr.end());
    vector<int> v;
    f(0,arr,n,v);
    return 0;
}