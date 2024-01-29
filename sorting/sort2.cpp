//sort an string array using selection sort in lexicographic order
//selection sort - find minimum element and place it at the beginning 
#include<bits/stdc++.h>
using namespace std;
bool checksize(string &a,string &b){
    
    for(int i=0;i<min(a.size(),b.size());i++){
        if(int(a[i])<int(b[i])){
            return true;
        }
    }
    
}
void stringsort(vector<string> &v){
    for(int i=0;i<v.size()-1;i++){
        int m=i;
        for(int j=i+1;j<v.size();j++){
            if(checksize(v[j],v[m])){
                m=j;
            }
        } 
        if(m!=i){
            swap(v[m],v[i]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    stringsort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}   