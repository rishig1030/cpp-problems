// detect the cycle using kahn's algorithm(topological sort) or using BFS

// if topological sort vector doesn't have equal to nodes element it does have cycle
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool topo(int nodes,vector<int> arr[]){
    // indegree represent the number of incoming nodes
    int indegree[nodes] = {0};
    for(int i=0;i<nodes;i++){
        for(int it:arr[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<nodes;i++){
        if(!indegree[i]) q.push(i);
    }
    vector<int> v;

    while(!q.empty()){
        int node = q.front();
        v.push_back(node);
        q.pop();
        for(int i:arr[node]){
            indegree[i]--;
            if(!indegree[i]){
                q.push(i);
            }
        }
    }
    if(v.size() != nodes) return true;
    else return false;
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int> arr[nodes];

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    if(topo(nodes,arr)) cout<<"Yes if does contain cycle";
    else cout<<"it does not contain any cycle";

    return 0;
}