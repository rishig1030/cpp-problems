// find second largest number in an array
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> a;
    a={3,42,2,42,527,321};
    int max,max2;
    for(int i=0;i<a.size();i++){
        if(max>a[i] && max2>a[i]){
            max=a[i];
            max2=max;
        }
        else if(max2>a[i] && max<a[i]){
            max2=a[i];
        }
    }
}