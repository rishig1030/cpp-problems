// detect the cycle in directed graph
#include<iostream>
#include<vector>
using namespace std;

bool dfs(int i,vector<int> arr[],vector<int> &visited,vector<int> &path,int nodes){
    visited[i] =  1;
    path[i] = 1;
    for(int j=0;j<arr[i].size();j++){
            if(!visited[arr[i][j]] || path[arr[i][j]]==0){
                if(dfs(arr[i][j],arr,visited,path,nodes)) return true;
                
            }  
            else return true;      
    }
    path[i] = 0;
    return false;
}

bool cycle(vector<int> arr[],int n){
    vector<int> visited(n,0);
    vector<int> path(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,arr,visited,path,n)) return true;
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
        int u; cin>>u;
        int v; cin>>v;
        
        arr[u].push_back(v);
    }

    if(cycle(arr,nodes)) cout<<"Cycle detected in Graph"<<endl;
    else cout<<"No Cycle Detected in Graph"<<endl;

    return 0;
}