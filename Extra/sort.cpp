#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main(){
    int n ; cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int b;
        cin>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

}