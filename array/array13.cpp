//boolean 2d array ,each row sorted ,find row with max. number of one
#include<bits/stdc++.h>
using namespace std;
int maxonesrow(vector <vector<int>> &v){
    int col=v[0].size()-1,max=-1;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1 && j<col){
                col=j;
                max=i;
                break;
            }
        }
    }
    return max;
}
int main(){
    int n,m; cin>>n>>m;
    vector <vector <int>> v(n,vector <int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<maxonesrow(v);
    return 0;
}