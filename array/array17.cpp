//sum of element from (l1,r1) to (l2,r2);
#include<bits/stdc++.h>
using namespace std;
int sum(int l1,int l2, int r1, int r2,vector<vector<int>> &v){
    int sum=0;
    for(int i=l1;i<=l2;i++){
        for(int j=r1;j<=r2;j++){
            sum+=v[i][j];
        }
    }
    return sum;
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<"matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    int l1,l2,r1,r2;
    cout<<"enter l1 and r1:"; cin>>l1>>r1;
    cout<<"enter l2 and r2:"; cin>>l2>>r2;
    
    cout<<"aum:"<<sum(l1,l2,r1,r2,v);
    return 0;
}