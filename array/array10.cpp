//check if we can partition an array with equal sum
#include<bits/stdc++.h>
using namespace std;
void subarray(vector <int> &v){
    int left=0,right=v.size()-1;
    int sumleft=v[left],sumright=v[right];
    while(right-left>1){
        if(sumleft<sumright){
            left++;
            sumleft+=v[left];
        }
        else {
            right--;
            sumright+=v[right];
        }
    }
    if(sumleft==sumright){
        cout<<"possible";
    }
    else cout<<"not possible";
}
int main(){
    vector <int> v;
    int n;
    cout<<"enter size:";
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    subarray(v);
    return 0;
}