//longest subarray with sum k
#include<bits/stdc++.h>
using namespace std;
int subarray(vector<int> a,int sum){
    int k=0;
    int len=0;
    while(k<a.size()){
        int s=0;
        for(int i=k;i<a.size();i++){
            s+=a[i];
            if(sum==s && (i+1-k)>len){
                len=i+1-k;
            }
        }   
        k++; 
    }
    return len;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int s;
    cin>>s;
    cout<<subarray(v,s);

    return 0;
}