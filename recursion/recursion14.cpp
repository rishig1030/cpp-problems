//given an array of n integer and a target value x . print wheather x exist in the array or not
#include<iostream>
#include<vector>
using namespace std;
bool f(vector<int> v,int n, int i,int k){
    if(k==v[i]){
        return true;
    }
    return (v[i]==k || f(v,n,i+1,k));
}
int main(){
    int n; cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k; cin>>k;
    if(f(v,n,0,k)){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}