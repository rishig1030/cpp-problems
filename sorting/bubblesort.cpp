//bubble sort , repeatedly swapping two adjacent element 
#include <bits/stdc++.h>
using namespace std;
// worst case time complexity O(n^2)
void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){ 
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}