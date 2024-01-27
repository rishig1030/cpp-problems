//place 0's at the end of an array without changing the order of other element
#include<bits/stdc++.h>
using namespace std;
// space complexity = O(1) ;
// time complexity = O(n^2);
int main(){
    int n; cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n-2;i++){
        bool flag=false;
        for(int j=0;j<n-1-i;j++){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j],v[j+1]); // concept of bubble sort
                flag=true;
            }
        }
        if(!flag) break;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}