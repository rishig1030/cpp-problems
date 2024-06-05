// find the area of max reactangle formed by one's of binary matrix 

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nextminimumindex(vector<int> arr,int n){
        vector<int> v(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
vector<int> prevminimumindex(vector<int> arr,int n){
        vector<int> v;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!= -1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            v.push_back(st.top());
            st.push(i);
        }
        return v;
    }



int getMaxArea(vector<int> arr, int n)
    {
        // Your code here
        vector<int> next;
        next = nextminimumindex(arr,n);
        
        vector<int> prev;
        prev = prevminimumindex(arr,n);
        
        int area = -1;
        for(int i=0;i<n;i++){
            int length = arr[i];
            
            if(next[i] == -1) next[i] = n;
            int breath = next[i]-prev[i]-1;
            
            area = max(area,length*breath);
        }
        return area;
    }

int maxreactangle(vector<vector<int>> v,int n, int m){
    int area = getMaxArea(v[0],m);
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]!=0){
                v[i][j]= v[i][j] + v[i-1][j];
            }
            else{
                v[i][j]=0;
            }
        }
        area=max(area,getMaxArea(v[i],m));
    }
    return area;
}

int main(){
    int n;
    int m; cin>>n;cin>>m;
    vector<vector<int>> v(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<maxreactangle(v,n,m);
    return 0;
}