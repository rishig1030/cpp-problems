// convert a decimal number into binary number 
#include<bits/stdc++.h>
using namespace std;

// time complexity here is O(log N)
// space complexity is also O(log N) , no auxillary space, space is req. to store answer only
string deci2bin(int n){
    string s = "";
    while(n!=0){
        if(n%2 == 0){
            s+= '0';
        } 
        else s+='1';
        n/=2;
    } 
    reverse(s.begin(),s.end());
    return s;
}

// time complexity is O(N) , N is size of string
// space compelxity is O(1)
int bin2dec(string binary){
    int n = 0;
    int power = 1;
    for(int i=binary.size()-1;i>=0;i--){
        if(binary[i]=='1'){
            n+=power;
        }
        power*=2;
    }

    return n;
}

int main(){
    int n;
    cin>>n;
    string s = deci2bin(n);
    cout<<s<<endl;

    string binary;
    cin>>binary;
    int num = bin2dec(binary);
    cout<<num<<endl;
    return 0;
}