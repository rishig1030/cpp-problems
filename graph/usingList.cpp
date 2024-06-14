// represent a graph using list

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    // non-directed
    // array of n nodes , each array element contain the nodes of its adjacent nodes
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // this will not be required for directed graph
    }
    // here the space complexity is O(2M);
    for(int i=1;i<n+1;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}