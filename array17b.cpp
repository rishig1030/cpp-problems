//3rd approach , by prefix sum row and column wise
#include<bits/stdc++.h>
using namespace std;
void sumofrect(vector<vector<int>> &v){
    //row wise sum
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            v[i][j]+=v[i][j-1];
        }
    }
    //column wise sum
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            v[i][j]+=v[i-1][j];
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector <vector<int>> v(n,vector<int> (m));
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
    sumofrect(v);
    int l1,r1,l2,r2,sum;
    cout<<"enter l1,r1,l2,r2:";cin>>l1>>r1>>l2>>r2;
    int top_sum=0,left_sum=0,topleft_sum=0;
    if(l1!=0) top_sum=v[l1-1][r2];
    if(r1!=0) left_sum=v[l2][r1-1];
    if(l1!=0 && r1!=0) topleft_sum=v[l1-1][r1-1];
    sum=v[l2][r2]-top_sum-left_sum+topleft_sum;
    cout<<sum;
    
    return 0;
}