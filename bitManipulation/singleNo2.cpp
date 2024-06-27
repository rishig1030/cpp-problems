// find the unique number present in an array which only contain the number in triplet
#include<bits/stdc++.h>
using namespace std;

int findunique(vector<int> v){
    int n  = 0;
    // check every bit of every element , 
    for(int bi=0;bi<32;bi++){
        int  count = 0;

        for(int i=0;i<v.size();i++){
            if(v[i] & (1<<bi)) count++;
        }
        // if some of bit of all the element in that perticular element is not multiple of 3 ,
        // that bit is not set for the unique element
        if(count%3 == 1){
            n = n|(1<<bi);
        } 
    }
    return n;
    // time complexity will always be O(N*32) 
    // space complexity will be O(1).

}

// another solution

int findunique2(vector<int> v){
    sort(v.begin(),v.end()); // sorting the vector will take NlogN 
    for(int i=1;i<v.size();i+=3){
        if(v[i] != v[i-1]) return v[i-1];
    }
    return v[v.size()-1];

    // time complexity will be O(NlogN + N/3) here log N to be 32 , n should be pow(2^32),
    // that is not gonna happen
    // space complexity O(1);
    // only problem for this solution is that it alter the given input
}

// 3rd solution
// time complexity is O(N)
// space complexity is O(1)
int findunique3(vector<int> v){
    int one = 0;
    int two = 0;
    for(int i=0;i<v.size();i++){
        one = (one^v[i]) & ~(two);
        two = (two^v[i]) & ~(one);
    }
    return one;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    cout<<findunique(v)<<endl;
    cout<<findunique2(v)<<endl;
    cout<<findunique3(v)<<endl;
    return 0;
}
