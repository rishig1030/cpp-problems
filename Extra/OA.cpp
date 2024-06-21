#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

string find(string arr[],int n){
    
    vector<vector<int>> visited(10,vector<int> (26,0));
    vector<int> isFree(26,0);
    for(int i=0;i<n;i++){
        if(arr[i][0] == '+'){
            visited[int(arr[i][1]) - '0'][int(arr[i][2]) - 'A']++;
        }
    }
    
    string s = "";
    int m = INT16_MIN;
    for(int i=0;i<10;i++){
        for(int j=0;j<26;j++){
            if(visited[i][j] > m){
                m = visited[i][j];
                s = to_string(i) + char('A'+j);
            }   
        }
    }
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<26;j++){
    //         if(visited[i][j] == m){
    //             m = visited[i][j];
    //             s = to_string(i) + char('A'+j);
    //             break;
    //         }   
    //     }
    // }
    return s;
}

int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<find(arr,n);
    return 0;
}