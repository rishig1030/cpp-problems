#include <bits/stdc++.h>
using namespace std;
string maxlength(vector <string> v){
    string str;
    string s1=v[0];//keeping a string constant to check;
    int len=s1.size();
    for(int i=1;i<v.size();i++){
        int j;
        for(j=0;j<min(s1.size(),v[i].size()) && s1[j] == v[i][j];j++){
            
        }//we are basically finding the length of biggest string to get the value of any string
        len=min(len,j);
    }
    str=s1.substr(0,len);
    return str;
}
int main(){
    int n;
    cin>>n;
    vector <string>  v(n);
    for(int  i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<maxlength(v);

    return 0;
}