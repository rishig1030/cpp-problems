//revrese a string using stack 
#include<iostream>
#include<stack>

using namespace std;

int main(){
    string s1= "rishi";
    stack<char> st;

    cout<<"original string is "<<s1<<endl;
    //inserting in stack
    for(int i=0;i<s1.size();i++){
        st.push(s1[i]);
    }    
    for(int i=0;i<s1.size();i++){
        s1[i]=st.top();
        st.pop();
    }

    cout<<"revresed string is "<<s1<<endl;
    return 0;
}