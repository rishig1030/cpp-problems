//maximum frequency number
// if more than two have same maximum freq retrun which occur first
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxfreq =0;
    unordered_map <int,int> count;
    for(int i=0;i<n;i++){
        count[arr[i]]++;
        maxfreq= max(maxfreq,count[arr[i]]);
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        if(maxfreq== count[arr[i]]){
            ans= arr[i];
        }
    }
    cout<<"Maximum Frequecy number is "<<ans<<endl;

    return 0;
}
// time complexity is O(n)