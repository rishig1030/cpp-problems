// find the unique element in an array; where all element are in pair.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    bool flag;
    a={2,3,4,2,4,1,1,5,5};
    for(int i=0;i<a.size();i++){
        flag=true;
        for(int j=0;j<a.size();j++){
            if(a[i]==a[j] && i!=j){
                flag=false;
            }
        }
        if(flag) cout<<a[i];
    }
}