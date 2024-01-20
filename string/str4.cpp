//a character array with of string find the longest common prefix string amongst an array of string
#include <bits/stdc++.h>
using namespace std;
string longestprefix(vector <string> v,int n){
    string str;
    //sorting the array of string 
    sort(v.begin(),v.end()); // nlogn*m is time complexity (where m is the length of max string)
    string st1=v[0];
    string st2=v[n-1];  //only comparing first and last because biggest difference will be between that only 
    for(int i=0;i<min(st1.size(),st2.size());i++){ //time for size of minimum length of string
        if(st1[i]==st2[i]){
            str.push_back(st1[i]);
        }
        else return str;
    }
    return str;
}
int main(){
    int n;
    cin>>n;
    vector <string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    string y=longestprefix(v,n);

    cout<<y;
    return 0;
}