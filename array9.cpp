#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<10;i++){
        a[i]=a[i]+a[i-1];
    }
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}