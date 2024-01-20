#include<iostream>
#include<vector>
#include<algorithm>//to operate reverse function
using namespace std;
void sortsq(vector <int> &v){
    vector<int> a;
    int left=0;int right=v.size()-1;
    while(left<right){
        if(abs(v[left])>=abs(v[right])){
            a.push_back(v[left]*v[left]);
            left++;
        }
        else{
            a.push_back(v[right]*v[right]);
            right--;
        }
    }
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    vector <int> v(6);
    for(int i=0;i<6;i++){
        cin>>v[i];
    }
    sortsq(v);
    
    return 0;
}