// find the number of substring contains all the three character in a string
#include<iostream>
#include<map>
using namespace std;

// brute force solution
int NumberOfSubstring1(string s){
    int count = 0;
    for(int i=0;i<s.size();i++){
        int hash[3] = {0};
        for(int j=i;j<s.size();j++){
            hash[s[j]-'a'] = 1;
            if(hash[0]+hash[1]+hash[2] == 3){
                count++;
                // we know that if upto j index the string is valid than for further index,
                // the string will be valid
                //count += (s.size()-j); break; // can also be used 
            }
        }
    }
    return count;
}
// time complexity is O(N2);
// complexity is O(1);


// using sliding window technique
int NumberOfSubstring2(string s){
    int hash[3] = {-1,-1,-1}; // last seen index
    int i = 0;
    int count = 0;
    while(i<s.size()){
        hash[s[i]-'a'] = i;
        if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
            count = count + min(hash[0],min(hash[1],hash[2])) +1;
        }
        i++;
    }
    return count;
}
// time complexity is O(N)
// space complexity is O(3)

int main(){
    string s;
    cin>>s;
    cout<<"Number of substring "<<NumberOfSubstring1(s)<<endl;
    cout<<"Number of substring 2nd approach : "<<NumberOfSubstring2(s)<<endl;
    return 0;
}