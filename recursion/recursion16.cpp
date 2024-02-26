//total number of path from top left corner to botttom right in as mXn matrics ,but we can either move down for right
#include <iostream>
using namespace std;
void f(int m,int n,int i,int j,int &count){
    if(i==m-1 && j==n-1){      //if at bottom right then return
        count++;               //increase the count value for one path
        return;
    }
    
    if(i<m-1) f(m,n,i+1,j,count); //moving towards bottom 
    if(j<n-1) f(m,n,i,j+1,count); //moving towards right
}
int main(){
    int m,n;
    cin>>m>>n;
    int count=0;
    f(m,n,0,0,count);
    cout<<count;
    return 0;
}