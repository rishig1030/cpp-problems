#include<iostream>
using namespace std;
void sort(int (&a)[10]){
    int left=0;
    int right=9;
    while(left<right){
        if(a[left]==1 && a[right]==0){
            swap(a[left],a[right]);
            left++;
            right--;
        }
        if(a[left]==0){
            left++;
        }
        if(a[right]==1){
            right--;
        }
    }
}
int main(){
    int array[10];
    for(int i=0;i<10;i++){
        cin>>array[i];
    }
    sort(array);
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
}