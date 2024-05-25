// reverse an array without loop
#include<iostream>
using namespace std;

void reversearray(int arr[],int n,int i)
{
    if(n-i-1 < i){
        return ;
    }
    else{
        swap(arr[i],arr[n-i-1]);
        reversearray(arr,n,i+1);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    reversearray(arr,n,0);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}