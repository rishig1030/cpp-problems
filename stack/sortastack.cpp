//sort an array using recursion
#include<iostream>
#include<stack>

using namespace std;

//emptying the stack and inserting in the right order
//similar to inserting at the bottom here  we are just inserting it at the bottom of the array


void insertatright(stack<int> &s,int data){
    if(s.empty()){
        s.push(data);
    }
    else{
        if(data >= s.top()){
            s.push(data);
        }
        //if data < s.top() then we will empty the stack unless we get the >= value 
        else{
            int d= s.top();
            s.pop();
            insertatright(s,data);
            s.push(d);
        }
    }
}

void sortstack(stack <int> & s){

    if(s.empty()){
        return ;
    }

    else{
        int data= s.top();
        s.pop();
        sortstack(s);
        insertatright(s,data);
    }
}

int main(){

    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        s.push(d);
    }

    sortstack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

//time complexity is O(n2)
//space complexity is still O(n2)  since we are using extra stack memory by using recursion