// upper bound 
// number greater than target number in an array (no equal to)
#include <iostream>
using namespace std;
int f(int arr[],int left,int right,int target){
    int ans=right+1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>target){         //similar to lower bound 
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[]={2,3,6,7,8,8,11,11,11,12};
    int target;
    cin>>target;
    cout<<f(arr,0,9,target);
    return 0;
}