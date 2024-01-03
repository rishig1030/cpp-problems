//pascal triangle, by factorial as every element is iCj;
#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
int main(){
    int n;cin>>n;
    vector <vector <int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            v[i][j]=factorial(i)/(factorial(j)*factorial(i-j));
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}