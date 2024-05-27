// to print the element from array whose sum is target sum with any element can be taken any number of times
#include<iostream>
#include<vector>

using namespace std;
void f(int i,int sum,vector<int> &v,int target,int arr[],int n){
    if(target<sum){
        return;
    }
    if(target==sum){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i == n){
        return ;
    }
    else{
        //pick the element and stayed
        sum= sum+arr[i];
        v.push_back(arr[i]);
        f(i,sum,v,target,arr,n);

        //not pick and move
        sum= sum-arr[i];
        v.pop_back();
        f(i+1,sum,v,target,arr,n);
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the sum: ";
    cin>>target;
    vector<int> v;
    f(0,0,v,target,arr,n);

    return 0;
}