// topological sort , if there is an edges between u to v , then u should appear before v
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int i,vector<int> &visited,stack<int> &st,vector<int> arr[]){
    visited[i] =1;
    for(int it : arr[i]){
        if(!visited[it]){
            dfs(it,visited,st,arr);
        }
    }
    st.push(i);
}

vector<int> sort(int nodes,vector<int> arr[]){
    vector<int> visited(nodes,0);
    stack<int> st;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            dfs(i,visited,st,arr);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    int nodes; cin>>nodes;
    int edges; cin>>edges;
    vector<int> arr[nodes];
    for(int i=0;i<edges;i++){
        int u; int v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    vector<int> topo(nodes); 
    topo = sort(nodes,arr); 
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }cout<<endl;
    return 0;
}