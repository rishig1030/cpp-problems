#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// given N tasks from 0 to N-1
// pre-requisites are given example for [0 1] that means 0 should be performed before 1
// check the the task is possible or not  - course 1;

// for course II problem , [0 1] means 1 should be performed before 0
// return the task in order if the task is possible else return the empty list


bool isPossible(int nodes,vector<pair<int,int>> v){
    
    vector<int> arr[nodes];

    for(int i=0;i<nodes;i++){
        arr[v[i].first].push_back(v[i].second);
    }
    int indegree[nodes] = {0};
    for(int i=0;i<nodes;i++){
        for(auto it: arr[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<nodes;i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto it : arr[front]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(ans.size() == nodes) return true; // that is the task is possible
    else return false; // task is not possible

}

int main(){
    int nodes;
    cin>>nodes;
    vector<pair<int,int>> v(nodes);
    for(int i=0;i<nodes;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    if(isPossible(nodes,v)) cout<<"Task is possible ";
    else cout<<"Task is not possible"<<endl;

    return 0;
}