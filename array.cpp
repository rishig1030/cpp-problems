// Find the total number of triplet in an array whose sum is equal to the given value x
#include<iostream>
using namespace std;
int main(){
    int array[]={3,1,2,4,0,6};
    int TS=5;
    int count=0;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<6;k++){
                if(array[i]+array[j]+array[k]==TS){
                    count++;
                }
            }
        }
    }
    cout<<count;
    return 0;
}
//for pair we only have to use two loop