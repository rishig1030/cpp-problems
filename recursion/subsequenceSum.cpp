#include<iostream>
#include <vector>
using namespace std;

void f(int index ,int s,vector<int> &v,int sum,int arr[],int n){
    if(index==n){
        if(s==sum){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
    else{
            //[pickup]
            s= s+arr[index];
            v.push_back(arr[index]);
            f(index+1,s,v,sum,arr,n);
            //not pick
            s-=arr[index];
            v.pop_back();
            f(index+1,s,v,sum,arr,n);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    vector<int> v;
    f(0,0,v,sum,arr,n);

    return 0;
}