// write all the permutation of an array , contain all the element in different order
// [1,2,3] , total permutation is (3)! 1,2,3  1,3,2  2,1,3,  2,3,1  3,1,2  3,2,1

#include<iostream>
#include<vector>
using namespace std;

//time complexity is = (n!)*n , function calling N! times and n is the traversing everytime
// space complexity is = O(n);

void f(int arr[],int freq[],int n,vector<int> v){
    if(v.size()==n){
        for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
        cout<<endl;
    }

    else{
        for(int i=0;i<n;i++){
            if(freq[i] != 0){
                freq[i]=0;
                v.push_back(arr[i]);
                f(arr,freq,n,v);
                v.pop_back();
                freq[i]=1;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    int freq[n];
    f(arr,freq,n,v);
    return 0;
}
