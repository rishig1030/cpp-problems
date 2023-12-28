// Find the total number of pair in an array whose sum is equal to the given value x
#include<iostream>
using namespace std;
int main(){
    int array[]={2,3,4,5,3,2,3,5,2,2};
    int TS=5;
    int count=0;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(array[i]+array[j] == TS){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}