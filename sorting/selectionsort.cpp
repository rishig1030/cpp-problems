//selection sort
#include<bits/stdc++.h>
using namespace std;

//repeatedly find minimun element and place it at beginning
//stable sort :> element having same value are not disturbed
//hence selection sort is not stable sorting algorithm
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //time complexity would be worst case/best case O(n(n-1)/2) i.e. O(n^2)
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[m]){
                m=j;
            }
        }
        if(v[m]!=v[i]){
            swap(v[m],v[i]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
