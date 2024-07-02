// find the longest repeating substring with k replacement allowed
#include<iostream>
using namespace std;

int RepeatingCharacter1(string s,int k){
    int maxlen = 0;
    for(int i=0;i<s.size();i++){
        int hash[26] = {0}; int maxf = 0;
        for(int j=i;j<s.size();j++){
            hash[s[j]-'A']++;
            maxf = max(maxf,hash[s[j]-'A']);
            if((j-i+1 - maxf)<=k){
                maxlen = max(maxlen,j-i+1);
            }   
            else break;
        }
    }
    return maxlen;
}
// time complexity is O(N2);
// space complexity is O(26);


int RepeatingCharacter2(string s,int k){
    int l = 0;
    int r = 0;
    int maxlen = 0;
    int maxf = 0;
    int hash[26] = {0};
    while(r<s.size()){
        hash[s[r]-'A']++;
        maxf = max(maxf,hash[s[r]-'A']);
        // (r-l+1 -maxf) is the number of changes required 
        if((r-l+1-maxf)>k){
            hash[s[l]-'A']--;
            //change the maxf, don;t change tha maxf as reducing the maxf will increase the 
            // value of eq. (r-l+1-maxf) will increase only > K
            // maxf should has to be same to get the better answer ,since only k flip are allowed
            l++;
        }
        if((r-l+1 - maxf)<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }

    return maxlen;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<"Length of Longest substring with repeating character "<<RepeatingCharacter1(s,k)<<endl;
    cout<<"Length of Longest substring with repeating character "<<RepeatingCharacter2(s,k)<<endl;
    return 0;
}