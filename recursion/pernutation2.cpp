// printing all the ecombination

#include<bits/stdc++.h>
using namespace std;

void permutation(int index,vector<int> &arr,int n,vector<vector<int>> &v){
    
    if(index == n){
        v.push_back(arr);
        return ;
    }
    
    for(int i=index;i<n;i++){
        swap(arr[index],arr[i]);
        permutation(index+1,arr,n,v);
        swap(arr[index],arr[i]);
    }
}

void f(vector<int> &arr,int n){
    vector<vector<int>> v;
    permutation(0,arr,n,v);
    for(int i=0;i<v.size();i++){
        for(auto it:v[i]){
            cout<<it<<" ";
        }cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    f(arr,n);
    return 0;
}