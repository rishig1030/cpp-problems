#include <bits/stdc++.h>
using namespace std;
int maxones(vector<vector<int>> &v){
    int col=-1,row=-1;
    
    int j=v[0].size()-1;

    while(j>=0 && v[0][j]==1){
        col=j;
        row=0;
        j--;
    }
    for(int i=1;i<v.size();i++){
        while(j>=0 && v[i][j]==1){
            col=j;
            j--;
            row=i;
        }
    }
    return row;
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> v(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<maxones(v);
    return 0;
}