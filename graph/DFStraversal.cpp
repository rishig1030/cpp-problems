// depth first search (DFS)
#include<iostream>
#include<vector>

using namespace std;

void DFS(int nodes,vector<int> adj[],int visited[],vector<int> &dfs){
    visited[nodes] = 1;
    dfs.push_back(nodes);

    // traverse its neighbours
    for(int i=0;i<adj[nodes].size();i++){
        if(!visited[adj[nodes][i]]){
            DFS(adj[nodes][i],adj,visited,dfs);
        }
    }

}

vector<int> depth(int nodes,vector<int> adj[]){
    int visited[nodes+1] = {0};
    int start = 1;
    vector<int> dfs;
    DFS(start,adj,visited,dfs);
    return dfs;
}

int main(){
    int nodes;
    int edges;
    cin>>nodes;
    cin>>edges;
    vector<int> adj[nodes+1];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfs;
    dfs = depth(nodes,adj);

    for(int i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }
    cout<<endl;
    return 0;
}