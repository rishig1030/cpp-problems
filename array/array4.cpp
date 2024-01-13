//rotate an array by K steps 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k;int r,t;
    cin>>k;
    int a[]={1,2,3,4,5,6};
    int size=sizeof(a)/sizeof(a[0]);
    // a[1]=a[0];//t=a[1]
    // a[2]=t;//t=a[2];
    for(int i=0;i<k;i++){
        t=a[0];
        a[0]=a[size-1];
        for(int j=1;j<size;j++){
            r=a[j];
            a[j]=t;
            t=r;
        }
    }
    int i=-1;
    while(i++<size-1){
        cout<<a[i]<<" ";
    }
    return 0;
}