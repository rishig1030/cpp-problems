// Frog jump , from i to j ,and energy lost is arr[j]-arr[i] , return the minimum energy lost 
// to reach the nth stairs
#include<iostream>
using namespace std;

int frogJump(int arr[],int n){
    // frog wants to jump from 0 - (n-1)
    if(n==0) return 0;
    if(n==1) return arr[1]-arr[0];
    
    int first = frogJump(arr,n-1) + abs(arr[n]-arr[n-1]);
    int second = frogJump(arr,n-2) + abs(arr[n]-arr[n-2]);

    return min(first,second);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i,n;i++){
        cin>>arr[i];
    }

    cout<<frogJump(arr,n-1); 

    return 0;
}