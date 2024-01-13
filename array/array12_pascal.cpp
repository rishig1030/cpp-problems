//2D Array , pascal triangle for n rows
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <vector <int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        //or v[i].resize(i+1) wihtout initiating the size of column rather we can just resize the size of each row.
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){ 
            if(j==0 || j==i){
                v[i][j]=1;
                cout<<v[i][j]<<" ";
            }
            else{
                v[i][j]=v[i-1][j-1]+v[i-1][j];
                cout<<v[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
