//check if a string is a anagram of other string 
//anargam are those string which have same element and also have equal count
#include<bits/stdc++.h>
using namespace std;
bool isanagram(string &str1,string &str2){
    if(str1.size()!=str2.size()){
        return false;
    }
    else{
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<str1.size();i++){
            freq1[str1[i]-'a']++;
            freq2[str2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return false;
    }
}
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    cout<<isanagram(str1,str2);
    return 0;
}