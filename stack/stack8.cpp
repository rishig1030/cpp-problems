//check if there exist any redundants bracket or not in a string consist of mathematical expression
// redundent means useless

#include<iostream>
#include<stack>

using namespace std;


//approach : there must be some expression or operator in between pair of bracket   

bool redbracket(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*'){
            st.push(s[i]);
        }
        else{
            // if closing brackets than we have to check for expression in the expression 
            // if no expression just opening after closing bracket than its redundant
            //that's why i use count , as if count == 0 , its redundant
            if(s[i] == ')'){
                st.push(s[i]);
                int count = 0;
                st.pop();
                while(st.top() != '('){
                    st.pop();
                    count++;
                }
                if(count==0) return false;
            }
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    if(redbracket(s)){
        cout<<"no redundant are there in the expression"<<endl;
    }
    else{
        cout<<"redundant bracket are there in the expression"<<endl;
    }
    return 0;
}