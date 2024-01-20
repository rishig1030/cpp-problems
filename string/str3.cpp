//isomorphic or not
//isomorphic are those strings which do have same value throughout the string assosiated with value as same index previously eg. adda egge , bbaab aabba etc.
#include<bits/stdc++.h>
using namespace std;
bool checkisomorphic(string &str1,string &str2){
    vector <int> freq1(128,-1);
    vector <int> freq2(128,-1);
    if(str1.size() != str2.size()){
        return false;
    }

    else{
        for(int i=0;i<str1.size();i++){
            if(freq1[str1[i]] != freq2[str2[i]]){
                return false;
            } 
            else{
                freq1[str1[i]]=freq2[str2[i]]=i;
            }
        }
        return true;
    }
}
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    cout<<checkisomorphic(str1,str2);
    return 0;
}