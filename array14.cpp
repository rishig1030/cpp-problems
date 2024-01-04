//rotate an 2d array by 90 deg, without any extra space;
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){          //transposing 
        for(int j=0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    for(int i=0;i<v.size();i++){            //reversing each rows, since each row is itself a 1D vector
        reverse(v[i].begin(),v[i].end());
    }

    //transposing + reversing = rotating 90deg clockwise 
}
int main(){
    int n; cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    rotate(v);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}