// count the number of nice array
// number of subarray with odd number is equal to k
#include<iostream>
using namespace std;

int countgoalSubarray(int arr[],int n,int k){
    if(k<0) return 0;
    int l = 0;
    int r = 0;
    int count = 0;
    int sum = 0;
    while(r<n){
        sum += arr[r]%2;  // for odd it will be 1 
        while(sum>k){
            sum -= arr[l]%2;
            l++;
        }
        count += (r-l+1);
        r++;
    }   
    return count;
}

int niceArray(int arr[],int n,int k){
    // convert the all the odd number as 1 and even numebr as zero
    // solve the problem as in number of binary subarray with sum
    return countgoalSubarray(arr,n,k)-countgoalSubarray(arr,n,k-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<niceArray(arr,n,k)<<endl;
    return 0;
}