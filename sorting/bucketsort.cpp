// bucket sort algorithm - used to sort the floating element

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketsort(float arr[],int n){
    vector<vector<float>> bucket(n,vector<float> ());

    for(int i=0;i<n;i++){
        int index = arr[i]*n;
        bucket[index].push_back(arr[i]);
    }

    // now sort individual bucket
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++] = bucket[i][j];
        }
    }
}
// time complexity is O(n+k) for avg case , O(n^2) for worst casee , if all of them are at single bucket
// space complexity is O(n+k) , k is the numebr of element in a bucket


int main(){
    int n;
    cin>>n;
    float arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bucketsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// if we have element greater than 1 , it will not fit in bucket list
// that range = (max-min)/size
// index = (arr[i]-min)/range , will be its index in bucket