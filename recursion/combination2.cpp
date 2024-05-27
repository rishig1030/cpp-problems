//combination of element whose sum is equal to target but element should not repeat twice and should be arranges in lexographical order
//each combinations should be picked once only 

#include <bits/stdc++.h>
using namespace std;

void f(int index,int sum,vector<int> &v,int target,vector<int> &arr,int n){
    if(sum == target){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

        return;
    }
    if(index==n || sum>target){
        return;
    }
    else{
        for(int i=index;i<n;i++){
            if(i>index && arr[i]==arr[i-1]) continue; 

            sum = sum+arr[i];
            v.push_back(arr[i]);
            f(i+1,sum,v,target,arr,n);
            sum = sum- arr[i];
            v.pop_back();
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int target;
    cout<<"Enter the sum: ";
    cin>>target;
    vector<int> v;
    f(0,0,v,target,arr,n);

    return 0;
}
// time complexity is ( 2^N ) * k  , k is the length of an array , since we are adding the element at the end of the array
// space complicity  is (K*X) , k is the length and X is the number of operations