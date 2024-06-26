// print all the subset of array
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subset(vector<int> v){
    int n = v.size();
    vector<vector<int>> ans;
    for(int i=0;i<(1<<n);i++){
        vector<int> list;
        for (int j = 0; j < n; j++)
        {
            if((1<<j) & i) list.push_back(v[j]);
        }
        ans.push_back(list);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    vector<vector<int>> ans;
    ans = subset(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}