// find the longest substring without repeating character
// substring is a continous character from string
// brute force appraoch
#include<iostream>
using namespace std;

int maxLen(string s){
    int maxlen = 0;
    for(int i=0;i<s.size();i++){
        int hash[255] ={0};
        for(int j=i;j<s.size();j++){
            if(hash[s[j]] == 1) break;
            maxlen = max(maxlen,j-i+1);
            hash[s[j]] = 1;
        }
    }
    return maxlen;
}

int main(){
    string s;
    cin>>s;
    cout<<"length of string without repeating "<<maxLen(s);
    return 0;
}