//sort an array with even at the beginning and odd at end"
#include<iostream>
#include<vector>
using namespace std;
void sorteo(vector <int> &v){
    int left=0;
    int right=v.size()-1;
    while(left<right){
        if(v[left]%2!=0 && v[right]%2==0){
            swap(v[left],v[right]);
        }
        if(v[left]%2==0){
            left++;
        }
        if(v[right]%2!=0){
            right--;
        }
    }
}
int main(){
    vector <int> v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    sorteo(v);
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}