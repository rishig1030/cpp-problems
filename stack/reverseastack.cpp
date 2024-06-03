// revrese a stack using recursion

#include<iostream>
#include <stack>
using namespace std;


void insertatbottom(stack<int> &s,int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    else{
        int num=s.top();
        s.pop();
        insertatbottom(s,data);
        s.push(num);
    }
}


void reverse(stack<int> & s){
    if(s.empty()){
        return;
    }
    else{
        int data=s.top();
        s.pop();
        reverse(s);
        //putting the top element at the bottom of the stack 
        insertatbottom(s,data);
    }
}

int main(){
    stack <int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;

        s.push(d);
    }

    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}

//time complexity is O(n2);
//space complexity is O(n2) //recursion is called inside recursion.