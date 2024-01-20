//with different approach
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;cout<<"enter size of an array:"; cin>>n;
    vector <int> v(n+1,0); //for 1 base indexing with 0th element to be zero
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
    }
    int t;
    cout<<"number of times you want to run your code:";
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        ans=v[r]-v[l-1];
        cout<<ans<<endl;
    }
    return 0;
}