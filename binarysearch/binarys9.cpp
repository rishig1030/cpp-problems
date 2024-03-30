//search in rotated sorted array with duplicate elements , yes or no .
#include <iostream>
using namespace std;
bool f(int arr[],int n,int target){
    int left =0;
    int right= n-1;
    
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            return true;
        }
        if(arr[mid]==arr[left] && arr[mid]==arr[right]){
            left++;
            right--;
            continue;
        }
        if(arr[mid]>=arr[left]){
            if(target>=arr[left] && target<=arr[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        else{
            if(target>=arr[mid] && target<=arr[right]){
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        
    }
    return false;

}
int main(){
    int arr[]= {7,8,9,1,2,3,3,3,4,5,6};
    int target;
    cin>>target;
    cout<<f(arr,11,target);
    return 0;
}

//worst case time complexity would be O(n/2); because we might end up shrinking it n/2 times
// average case would be O(logN);