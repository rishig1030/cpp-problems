//Given array write the sum of all the subset int it , (subset is different from subarray since the subarray is continuous element )
#include<iostream>
#include<vector>
using namespace std;          
//total subset of element having n character is 2^n
void f(int a[],int n,int i,int sum,vector <int> &result){
    if(i==n){
        result.push_back(sum);   // storing thr value of sum in result after the whole recursion
        return;
    }
    f(a,n,i+1,sum+a[i],result);  //including the element 
    f(a,n,i+1,sum,result); //not including the element 
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector <int> result;

    f(a,n,0,0,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}