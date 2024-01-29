//sort an string array using selection sort in lexicographic order
//selection sort - find minimum element and place it at the beginning 
#include<bits/stdc++.h>
using namespace std;
//here the time complexity will be more than that of selection sort , i.e O(n^2 * m) ,m is the size of string 
//but here i don't have to use any character array which i will in second approach (no problem although) 
bool checksize(string &a,string &b){
    
    for(int i=0;i<min(a.size(),b.size());i++){
        if(int(a[i])<int(b[i])){
            return true;
        }
        else if(int(a[i])>int(b[i])){
            return false;
        }
    }
    
}
void stringsort(vector<string> &v){
    for(int i=0;i<v.size()-1;i++){
        int m=i;
        for(int j=i+1;j<v.size();j++){
            bool flag=checksize(v[j],v[m]);
            if(flag){
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