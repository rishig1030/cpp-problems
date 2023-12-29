// find second largest number in an array
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> a;
    a={3225,42,2,42,527,321};
    int max=INT16_MIN,max2=INT16_MIN;
    for(int i=0;i<a.size();i++){
        if(max<a[i] && max2<a[i]){
            max2=max;
            max=a[i];
        }
        else if(max2<a[i] && max>a[i]){
            max2=a[i];
        }
    }
    cout<<max2;
}