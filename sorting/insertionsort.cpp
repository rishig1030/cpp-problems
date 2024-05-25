//insertion sort
#include<bits/stdc++.h>
using namespace std;
//time complexity , O(n(n+1)/2) =O(n^2), worst case / as well in best case;
//space complexity , is O(1);,constant
// find the element lesser than the current element and swap it
//insertion sort is stable sorting algorithm because it doesn't change the order of same element
void insertionsort(vector<int> &v){ 
    int a;
    for(int i=1;i<v.size();i++){
        a=v[i];
        int j=i-1;
        while(j>=0 && a<v[j]){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=a;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    insertionsort(v);
    for(int i=0;i<n;i++){
       cout<<v[i]<<" ";
    }
    return 0;
}