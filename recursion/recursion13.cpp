//frog problem, stones from 1 to N (height hi , h is given for each stones), a frog can jump to steps or one but cost is (|hi-hj|)
#include<bits/stdc++.h>
using namespace std;
int f(int a[],int n, int i){
    if(i==n-1){
        return 0;        //test case-1   //already at last no jump req.
    }
    if(i==n-2) return f(a,n,i+1) + abs(a[i]-a[i+1]);     //test case-2   //only one jump is possible
    return min(f(a,n,i+1)+abs(a[i]-a[i+1]),f(a,n,i+2)+abs(a[i]-a[i+2]));    //calculate cost from i+1 to n and from i+2 to n, and minimum of that
}
int main(){
    int n; cout<<"Write Number of Stones: ";
    cin>>n;
    int a[n];
    cout<<"Write the array Elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Cheapest Cost from stone 1 to n: "<<f(a,n,0);
    return 0;
}