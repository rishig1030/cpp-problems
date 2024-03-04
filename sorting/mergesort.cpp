// merge sort , invovle divide and merge   O(n*log(n))  (time compplexity)
// space complexity if O(n)
#include<iostream>
#include<vector>
using namespace std;
void merge(int a[],int i,int mid,int n){
    vector<int> v;
    int left=i;
    int right=mid+1;
    while(left<=mid && right<=n){
        if(a[left]<=a[right]){
            v.push_back(a[left]);
            left++;
        }
        else{
            v.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
        v.push_back(a[left]);
        left++;
    }
    while(right<=n){
        v.push_back(a[right]);
        right++;
    }

    for(int j=i;j<=n;j++){
        a[j]=v[j-i];
    }
}
void f(int a[],int i,int n){
    if(i==n){
        return;
    }
    int mid=(i+n)/2;
    f(a,i,mid);
    f(a,mid+1,n); 
    merge(a,i,mid,n);
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    f(a,0,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
//time complexity
//we are dividing an array into n/2 size
//           n/(2^k)  <= 1
//           k >=  log2(n)
// now merge time O(n)  , evry element is compared n times(atmost) O(n);
// time complexity is n*log(n)