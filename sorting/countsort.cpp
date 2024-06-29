// perform a count sort algorithm to sort an array
#include<iostream>
using namespace std;

// for negative number array subtract thee Minimum number from all the array and then perform count sort
// this algorithm can't be used for floating numbers
// also these type of sorting algorithm should not be performed when the number are far from each other
void countsort(int arr[],int n){
    // find the max element in an array
    int m = INT16_MIN;
    for(int i=0;i<n;i++){
        m = max(m,arr[i]);
    }
    int f[m+1] = {0};
    // count the frequency of an array
    for(int i=0;i<n;i++){
        f[arr[i]]++; 
    }
    // calculate its cummilative frequency
    for(int i=1;i<m+1;i++){
        f[i]+= f[i-1];
    }
    int ans[n];
    // place the element in the index in cummulative frequency array
    for(int i=n-1;i>=0;i--){
        ans[--f[arr[i]]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }
}
// time complexity is O(3*n+(m+1))
// space complecity is O(M+n);


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countsort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}