// count the binary subarray with sum k 
#include<iostream>
using namespace std;

int countgoalSubarray(int arr[],int n,int k){
    if(k<0) return 0;
    int l = 0;
    int r = 0;
    int count = 0;
    int sum = 0;
    while(r<n){
        sum += arr[r];
        while(sum>k){
            sum -= arr[l];
            l++;
        }
        count += (r-l+1);
        r++;
    }   
    return count;
}
// timecomplexity = O(2x(2N));
// space complexity is O(1);
int SubArray(int arr[],int n,int k){
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
    cout<<"Number of subArray with sum "<<SubArray(arr,n,k);
    return 0;
}