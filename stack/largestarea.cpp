// find the largest area of reactange in histograph

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> indexfornext(vector<int> v){
    vector<int> ans(v.size());
    stack<int> st;
    st.push(-1);
    for(int i=v.size()-1;i>=0;i--){
        if(st.top()!= -1 && v[st.top()]<v[i]){
            ans[i] = st.top();
            st.push(i);
        }
        else{
            while(st.top()!= -1 && v[st.top()]>=v[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
    return ans;
}

vector<int> indexforprev(vector<int> v){
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());
    for(int i=0;i<v.size();i++){
        if(st.top()!= -1 && v[st.top()]<v[i]){
            ans[i]=st.top();
            st.push(i);
        }
        else{
            while(st.top()!= -1 && v[st.top()]>=v[i])
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
    }

    return ans;
}

int maxarea(vector<int> v){

    vector<int> next(v.size());
    next = indexfornext(v);
    vector<int> prev(v.size());
    prev= indexforprev(v);
    int area = -1;
    for(int i=0;i<v.size();i++){
        int length = v[i];
        if(next[i] == -1) next[i]=v.size();
        int breath = next[i]-prev[i]-1;
        area = max(area,length*breath);
    }
    return area;
}

int main(){
    vector<int> v;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        v.push_back(data);
    }

    cout<<"Maximum Area "<<maxarea(v);
    return 0;
}