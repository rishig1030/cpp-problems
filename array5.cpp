//check if query element is present in an array or not
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int array[]={3,4,6,2,3,5};
    vector<int> freq(pow(10,5),0);//pow(10,5)== 1e5 + 10;
    for(int a:array){
        freq[a]++;
    }
    int q;
    cout<<"enter number quries:";
    cin>>q;
    while(q--){
        int element;
        cin>>element;
        cout<<"number of element present is = "<<freq[element]<<endl;//for every query element it will check ,how many times an element is present in it.
    }

    return 0;
}