// breath first traversal in binary tree or Level Wise traversal
#include<iostream>
#include<queue>
using namespace std;

vector<int> BFS(int nodes,vector<int> arr[]){
    int visited[nodes+1] = {0};
    visited[1] = 1 ;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(int i=0;i<arr[node].size();i++){
            if(!visited[arr[node][i]]){
                visited[arr[node][i]] = 1;
                q.push(arr[node][i]);
            }
        }
    }
    return bfs;
}

int main(){
    int nodes;
    int edges;
    cin>>nodes;
    cin>>edges;
    vector<int> arr[nodes+1];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    // this vector will contain the bfs
    vector<int> v;
    v = BFS(nodes,arr);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}