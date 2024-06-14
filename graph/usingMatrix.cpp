// representing graph using a matrix
#include<iostream>
using namespace std;

int main(){
    int n;  // number of nodes
    int m;  // number of edges
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            adj[i][j] = 0;
        }
    }
    // non-directional graph 
    // give the input of m nodes , basically the directions
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=1;i<n+1;i++){

        for(int j=1;j<m+1;j++){
            cout<<adj[i][j]<<"     ";
        }
        
        cout<<endl;
    }
    return 0;
}