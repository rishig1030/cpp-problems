// detect a cycle using DFS traversal in a list

#include<iostream>
#include<vector>
using namespace std;

bool detect(int parent,int node,vector<int> & visited,vector<int> adj[],int V){
    visited[node] = 1;
    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            
            if(detect(node,adj[node][i],visited,adj,V)) return true;
        }
        else if(adj[node][i] != parent){
            return true;
        }
    }
    return false;
}

bool cycle(vector<int> arr[],int V){
    vector<int> visited(V,0);
    
    // to tackle the disconnected graph
    for(int i=0;i<V;i++){
        if(!visited[i]){
            return(detect(-1,0,visited,arr,V));
        }
    }
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