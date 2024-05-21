//reverse a queue using stack
//can aslo be reversed by using recursion

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reversequeue(queue<int> &q){

    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}


//time complexity is O(n)
//space complexity is O(n); space occupied by stack

int main()
{   
    queue<int> q;
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        q.push(a);
    }

    reversequeue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}