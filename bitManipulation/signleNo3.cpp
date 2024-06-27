// given array contain each element twice in an array but contain two distinct number once
#include<iostream>
#include<vector>
using namespace std;

pair<int,int> pairofunique(vector<int> v){
    pair<int,int> p = {0,0};
    int XOR = 0;
    for(int i=0;i<v.size();i++){
        XOR = XOR^v[i];
    }
    // XOR will be the XOR of two unique number , now to find the right most set bit
    XOR = (XOR^(XOR-1)) & XOR;
    // right most set bit will be to differentiate the two numbers
    // suppose 1st bit for both is different that will be set
    // and in an array the number which have 1st bit two be set are placed seperately
    // and taking XOR out of all numbers in different group will give the unique number seperately
    for(int i=0;i<v.size();i++){
        if(XOR&v[i]) {
            p.first = p.first^v[i];
        }
        else{
            p.second = p.second^v[i];
        }
    }
    return p;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    pair<int,int> p;
    p = pairofunique(v);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}