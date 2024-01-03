//sum of element from l to r, with one base indexing
#include<bits/stdc++.h>
using namespace std;
void sum(vector <int> &v){
    int l, r;
    cin>>l>>r;
    int sum=0;
    for(int i=l-1;i<r;i++){
        sum+=v[i];
    }
    cout<<sum<<endl;
}
int main(){
    int n;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int t;
    cout<<"queries :";
    cin>>t;
    while(t--){
        sum(v);
    }
    return 0;
}