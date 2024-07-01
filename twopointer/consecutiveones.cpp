// find the maximum onces , such that we have allowed to flip k zeros
// brute force solution
#include<iostream>
using namespace std;

int consecutiveOnes1(int arr[],int n,int k){
    // basically need to find consecutive array with atmost k zeros
    int maxlen = 0;
    for(int i=0;i<n;i++){
        int count0 = 0;
        for(int j=i;j<n;j++){
            if(arr[j] == 0){
                count0++;
            }
            if(count0 <= k){
                maxlen = max(maxlen,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxlen;
}
// time complexity is O(N2)
// space complexity is O(1);


// two pointer and sliding window approach
int consecutiveOnes2(int arr[],int n,int k){
    int l = 0;
    int r = 0;
    int maxlen = 0;
    int zero = 0;
    while(r<n){
        if(arr[r] == 0){
            zero++;
        }
        while(zero>k && l<n){
            if(arr[l] == 0) zero--;
            l++;
        }
        if(zero<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}
// time complexity O(2N)
// space complexity is O(N)


//most optimal solution 
int consecutiveOnes3(int arr[],int n,int k){
    int l = 0;
    int r = 0;
    int maxlen = 0;
    int zero = 0;
    while(r<n){
        if(arr[r] == 0) zero++;
        if(zero>k){
            if(arr[l] == 0) zero--;
            l++;
        }
        if(zero<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    } 
    return maxlen;
}
// time complexity is O(N)
// space complexity is O(1)

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<"brute force solution :- Number of consecutive ones by flipping "<<k<<" zeros is "<<consecutiveOnes1(arr,n,k)<<endl;
    cout<<"optimized solution :- Number of consecutive ones by flipping "<<k<<" zeros is "<<consecutiveOnes2(arr,n,k)<<endl;
    cout<<"most oprimized :- Number of consecutive ones by flipping "<<k<<" zeros is "<<consecutiveOnes3(arr,n,k);
    
    return 0;
}