//decode a string , 1[b] as b and , 3b[2[ca]] as bcacabcacabcaca
#include<bits/stdc++.h>
using namespace std;
//space complexity is O(n); size pf result string
//time complexity is O(n); n is size of result string

string decodedstr(string s1){
    //traversing a string
    string result="";
    for(int i=0;i<s1.size();i++){
        
        if(s1[i]!=']'){
            result.push_back(s1[i]);
        }
        else{
            //extracting str from result
            string str="";
            while(!result.empty() && result.back()!='['){ //result.empty , check is string is empty or not
                str.push_back(result.back()); //back add last character
                result.pop_back();// use to remove last character
            }
            //rervese an str
            reverse(str.begin(),str.end());

            //remove [ from str
            result.pop_back();

            //now extracting from string 
            string num="";
            while(!result.empty() && (result.back()>='0' && result.back()<='9')){
                num.push_back(result.back());
                result.pop_back();
            }
            
            //reversing thee num string
            reverse(num.begin(),num.end());

            //convert string to number
            int n=stoi(num);

            //inserting str to result n times
            while(n--){
                result+=str;
            }
        }
    }
    return result;
}
int main(){
    string s1;
    cin>>s1;
    
    cout<<decodedstr(s1);


    return 0;
}