//in a number pad , a digit from 2-9 is given , return all the possible letter combination that the number could represent
// ex: "23"
//output : ad , ae , af ,bd ,be ,bf ,cd ,ce ,cf     
#include<bits/stdc++.h>
using namespace std;
void f(string str,int i,string result,int n,vector<string> v){
    if(i==n){               // if input number string is over return the result string
        cout<<result<<" ";
        return;
    }
    for(int j=0;j<v[str[i]-'1'].size();j++){        //till the size of string in string vector v
        f(str,i+1,result+(v[str[i]-'1'][j]),n,v);   //dry and run and find out;
        
    }
    
}
int main(){
    string str;
    cin>>str;
    vector <string> v={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string result="";
    f(str,0,result,str.size(),v);
    return 0;
}