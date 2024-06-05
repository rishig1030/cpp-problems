// find the celebrity 
// such that everyone knnows celebrity but celebrity know no one

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int>> v,int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size() != 1){
        int A = st.top(); 
        st.pop();
        int B = st.top();
        st.pop();
        if(v[A][B] != 1) st.push(A);
        if(v[B][A] != 1) st.push(B);
    }
    int cel = st.top();
    
    for(int i=0;i<n;i++){
        if(v[cel][i] == 1){
            return -1;
        }
        if(v[i][cel] == 0 && i!=cel){
            return -1;
        }
    }
    return cel;
}   


int main(){
    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<celebrity(v,n);

    return 0;
}
