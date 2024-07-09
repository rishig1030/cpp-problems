// find the kth smallest element in an array
#include<iostream>
#include<queue>
using namespace std;

// insert the 1st k element in to heap
// for next k element if that element is lesser than root node of heap , pop that
// insert the smallest element into it
// now the heap will only contain k smallest element
// out of k smallest , largest element will be the root node element

int kSmallest(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.emplace(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.emplace(arr[i]);
        }
    }
    return pq.top();
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

    cout<<kSmallest(arr,n,k);

    return 0;
}
