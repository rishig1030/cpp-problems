// longest substring wihtout repeating 
// two pointer and sliding window method
#include<iostream>
#include<vector>
using namespace std;

int maxLen(string s){
    int maxlen = 0;
    int l = 0;
    int r = 0;
    vector<int> hash(256,-1);
    while(r<s.size()){
        if(hash[s[r]] != -1){
            if(hash[s[r]]>=l){
                l = hash[s[r]] + 1;
            }
        }
        maxlen = max(maxlen,r-l+1);
        hash[s[r]] = r;
        r++;
    }
    return maxlen;
}
// time complexity is O(n)
// space complexity is O(256), size of array

int main(){
    string s;
    cin>>s;
    cout<<"Max Length without repeatation "<<maxLen(s)<<endl;
    return 0;
}