//put the element in matrix in spiral order , from 1 to n2(n square), n is order of matrix
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector <vector<int>> v(n,vector<int>(n));
    v=spiral(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}