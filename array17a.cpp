#include<bits/stdc++.h>
using namespace std;
int prefixsum(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            v[i][j]+=v[i][j-1];
        }
    }
}
int main(){
    int n,m ;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    prefixsum(v);
    int l1,l2,r1,r2;
    cout<<"enter l1,r1,l2,r2: ";
    cin>>l1>>r1>>l2>>r2;
    int sum=v[l1][r2]-v[l1][r1-1]+v[l2][r2]-v[l2][r1-1];
    cout<<sum;
    return 0;
}