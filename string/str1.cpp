//sort an string
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int n=0;
    while(str[n]!='\0'){
        n++;
    }
    n=n+1;
    vector<int> freq(26,0);
    for(int i=0;i<n;i++){
        freq[str[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        while(freq[i]--){
            cout<<char('a'+i);
        }
    }
    return 0;
}