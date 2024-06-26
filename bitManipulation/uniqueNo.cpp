// find the unique number in an array of duplicate element

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    // XOR of same number is 0
    // so the left out number will be the answer
    int k = v[0];
    for(int i=1;i<n;i++){
        k = k^v[i];
    }
    cout<<k;

    return 0;
}