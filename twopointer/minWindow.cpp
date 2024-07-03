// print the minimum window which contain all the element of give string of more or equal freq.
#include<iostream>
using namespace std;

//brute force :-
//time complexity is O(N2);
// space complexity is O(256);
string minWindow1(string s,string t){
    int sIndex = -1;
    int minLength  = INT16_MAX;
    for(int i=0;i<s.size();i++){
        int hash[256] = {0};
        int count = 0;
        for(int j=0;j<t.size();j++){
            hash[t[j]]++;
        }
        for(int j=i;j<s.size();j++){
            if(hash[s[j]]>0){
                count++;
                hash[s[j]]--;
            }
            if(count == t.size() && (j-i+1)<minLength){
                minLength = j-i+1;
                sIndex = i;
                break;
            }
        }
    }
    return s.substr(sIndex,minLength);
}


// optimised
// time complexity is O(N + N) + O(M)
// space complexity is O(256)
string minWindow2(string s,string t){
    int l = 0;
    int r = 0;
    int count = 0;
    int minlength = INT16_MAX;
    int sIndex = -1;
    int hash[256] = {0};
    for(int i=0;i<t.size();i++){
        hash[t[i]]++;
    }
    while(r<s.size()){
        if(hash[s[r]]>0) {
            count++;
        }
        hash[s[r]]--;
        while(count == t.size()){
            if((r-l+1)<minlength){
                minlength = r-l+1;
                sIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0) count--;

            l++;
        }
        r++;
    }
    if(sIndex == -1) return "" ;
    return s.substr(sIndex,minlength);
}

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;

    cout<<minWindow1(s,t)<<endl;
    cout<<minWindow2(s,t)<<endl;
    return 0;
}