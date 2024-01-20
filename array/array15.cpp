//spiral matrix , print elements in spiral order
#include <bits/stdc++.h>
using namespace std;
void spiral(vector<vector<int>> &v){
    int top=0,bottom=v.size()-1,left=0,right=v[0].size()-1;
    int direction=0;
    while(top<=bottom && left<=right){
        if(direction==0){
            for(int i=left;i<=right;i++){
                cout<<v[top][i]<<" ";
            }
            top++;
        }
        else if(direction == 1){
            for(int i=top;i<=bottom;i++){
                cout<<v[i][right]<<" ";
            }
            right--;
        }
        else if(direction ==2){
            for(int i=right;i>=left;i--){
                cout<<v[bottom][i]<<" ";
            }
            bottom--;
        }
        else{
            for(int i=bottom;i>=top;i--){
                cout<<v[i][left]<<" ";
            }
            left++;
        }
        direction=(direction+1)%4;
    }
}
int main(){
    int n,m;cin>>n>>m;
    vector <vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    spiral(v);
    return 0;
}