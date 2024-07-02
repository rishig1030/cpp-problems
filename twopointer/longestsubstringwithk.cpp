// find the longest substring with k distint element allowed
#include<iostream>
#include<map>
using namespace std;

int longestString(string s,int k){
    int l = 0;
    int r = 0;
    int maxlen = 0;
    map<char,int> mpp;
    while(r<s.size()){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        if(mpp.size()<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    string s ;
    cin>>s;
    int k;
    cin>>k;
    cout<<"length of the longest string is "<<longestString(s,k);
    return 0;
}