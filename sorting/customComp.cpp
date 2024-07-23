#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// it will sort according to second element in the pair , in decreasing order
bool comp(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a;
        int b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),comp);
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }


    return 0;
}