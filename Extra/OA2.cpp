// remove the part subarray such that the number of element in that array stricktly lesser and
// strictly greater than a given number are equal

#include<iostream>
#include<vector>
using namespace std;

int length(vector<int> v,int k){
    vector<int> ans(v.size(),0);
    for(int i=0;i<v.size();i++){
        if(v[i]>k){
            ans[i] = 1;
        }
        else if(v[i]<k) ans[i] = -1;
    }
    int sum =0;
    for(int i=0;i<v.size();i++){
        sum+= ans[i];
    }

    // now find minimum length with sum = -sum
    
    int length;
    int p = 0;
    while(p<v.size()){
        int s = 0;
        for(int i=p;i<v.size();i++){
            s = s+ans[i];
            if(s==sum && (i+1-p)<length){
                length = i+1-p;
            }
        }
        p++;
    }    
    return v.size()-length;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<length(v,k);
    return 0;
}