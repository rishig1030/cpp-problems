// find the maximum point that can we get from k cards, and cards can be select from the front 
//or from the back ,or from both side but should be consecutive.
#include<iostream>
using namespace std;

int maxPoint(int arr[],int n,int k){
    int lsum = 0;
    int rsum = 0;
    int sum = 0;
    for(int i=0;i<k;i++){
        lsum += arr[i];
    }
    sum = lsum;
    for(int i=0;i<k;i++){
        lsum -= arr[k-1-i];
        rsum += arr[n-1-i];
        sum = max(sum,lsum+rsum);
    }
    return sum;
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
    cout<<"Maximum point is "<<maxPoint(arr,n,k);
    return 0;
}