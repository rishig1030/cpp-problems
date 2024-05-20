//an expression contain bracket '{' , '}' , check if the expression is valid or not.
//if not than how many bracket need to be revrese to make the expression valid

#include<iostream>
#include<stack>

using namespace std;

//number of opening bracket should be equal to close bracket, number of element should be even

// there are three condition for invalid expression after neglecting the valid part
// 1, all open , 2 all close , 3 starting open and end close 

//in all cases , minimum number of reverse = (a+1)/2 + (b+1)/2 , a and b are openning and closing brackets

int minimumreverse(string s){
    //odd condition
    if(s.size()%2 != 0) return -1;

    //remove the valid part
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }

    //now the stack only contain invalid expressions
    int a=0 ; int b=0;
    while(!st.empty()){
        if(st.top()== '{'){
            a++;
        }
        else{
            b++;
        }
        st.pop();
    }
    return (a+1)/2 + (b+1)/2 ;
}

int main(){
    string str;
    cin>>str;
    cout<< minimumreverse(str)<<endl;

    return 0;
}