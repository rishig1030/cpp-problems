//same question but not done by myself
#include <bits/stdc++.h>
using namespace std;
//time and space complexity will be same as that of for selection sort i.e O(n^2) adn O(1) respectively.
void stringsort(char array[][60],int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(strcmp(array[m],array[j]) > 0){  //strcmp basicall compare two character element.
                m=j;
            }
        }
        if(m!=i){
            swap(array[i],array[m]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    char array[n][60];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    stringsort(array,n);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}