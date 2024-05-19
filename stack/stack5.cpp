//insert at the bottom of any stack

#include <iostream>
#include <stack>

using namespace std;

void insertatbottom(stack<int> &s,int data){
    if(s.empty()){
        s.push(data);
    }
    else{
        int d=s.top();
        s.pop();
        insertatbottom(s,data);
        s.push(d);
    }
}

int main(){
    stack<int> s1;
    
    for(int i=0;i<10;i++){
        int data;
        cin>>data;
        s1.push(data);
    }

    insertatbottom(s1,0);

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
}