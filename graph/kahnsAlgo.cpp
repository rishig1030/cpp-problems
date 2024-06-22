// kahn's Algorithm , topological sort with recursion 
// similar to BFS approach

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// space complexity is O(N^2)
// time complexity is O(e+n);

vector<int> topological(int nodes,vector<int> arr[]){
    vector<int> v;
    queue<int> q;
    int indegree[nodes] ={0};
    for(int i=0;i<nodes;i++){
        for(int it : arr[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<nodes;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        v.push_back(front);
        for(int it : arr[front]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    return v;
}

int main(){
    int nodes;
    int edges;
    cin>>nodes; 
    cin>>edges;
    vector<int> arr[nodes];
    for(int i=0;i<edges;i++){
        int u;
        int v;
        cin>>u;
        cin>>v;
        arr[u].push_back(v);
    }
    vector<int> v;
    v = topological(nodes,arr);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
