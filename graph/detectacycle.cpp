// detect a cycle in a undirected graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect(int node,vector<int> adj[],vector<int> &visited){
    visited[node] = 1;
    queue<pair<int,int>> q;
    q.push({node,-1});  
    while(!q.empty()){
        int n = q.front().first;
        int src = q.front().second;
        q.pop();
        for(int i = 0;i<adj[n].size();i++){
            if(!visited[adj[n][i]]){
                q.push({adj[n][i],n});
                visited[adj[n][i]] = 1;
            }
            else if(src != adj[n][i]){
                return true;
            }
        }
    }
    return false;
}

// this is to check the cycle if graph has more than one provices
bool cycle(vector<int> adj[],int nodes){
    vector<int> visited(nodes,0);
    
    
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            if(detect(i,adj,visited))
                return true;
        }
    }
    return false;
}

int main(){
    int nodes;
    cin>>nodes;
    int edges;
    cin>>edges;
    vector<int> arr[nodes];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    if(cycle(arr,nodes)) cout<<"Cycle is present in the Grpah ";
    else cout<<"Cycle is not present"; 
    return 0;
}