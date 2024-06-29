// perform a radic sort algorithm 
// this is advanced version of count sort where the number in a array is appart at longer distant
#include<iostream>
using namespace std;

// total time complexity O(p*(n+k)) , k will be 10
// space complexty O(n+k) , k is 10

void countSort(int arr[],int n,int pos){
    int f[10] = {0};
    for(int i=0;i<n;i++){
        f[(arr[i]/pos)%10]++;
    }
    // cuummulative frequency
    for(int i=1;i<10;i++){
        f[i]+=f[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--f[(arr[i]/pos)%10]] = arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }
}

// sort the element digit wise and you will get the desire output
void radixSort(int arr[],int n){
    int m = INT16_MIN;
    for(int i=0;i<n;i++){
        m = max(m,arr[i]);
    }
    for(int pos=1;m/pos>0;pos*=10){
        countSort(arr,n,pos);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    radixSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}