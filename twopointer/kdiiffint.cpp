// find the number array with k different interger
#include<iostream>
#include<map>
using namespace std;

// brute force ,
// time complexity is O(N2);
// space complexity is O(K+1)
int kDistint1(int arr[],int n,int k){
    int count = 0;
    for(int i=0;i<n;i++){
        map<int,int> mpp;
        for(int j=i;j<n;j++){
            mpp[arr[j]]++;
            if(mpp.size() == k){
                count++;
            }
            else if(mpp.size()>k) break;
        }
    }
    return count;
}

// kDistint
int kDistint2_p(int arr[],int n,int k){
    int l = 0;
    int r = 0;
    int count = 0;
    map<int,int> mpp;
    while(r<n){
        mpp[arr[r]]++;
        while(mpp.size()>k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size()<=k){
            count += r-l+1;
        }
        r++;
    }
    return count;
}
int kDistint2(int arr[],int n,int k){
    return kDistint2_p(arr,n,k)-kDistint2_p(arr,n,k-1);
    // time complexity is O(2X2N) , suppose map takes O(1) rather than O(logN) for insertiton
    // space complexity is O(K)
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
    cout<<"Number of array with k different "<<kDistint1(arr,n,k)<<endl;
    cout<<"Number of array with k different "<<kDistint2(arr,n,k);
    
    return 0;
}