//implementation and theory of stack

#include<iostream>
#include<stack>
using namespace std;

//implementing using an array
class Stack{
    //properties of class
    public:
    int *arr;
    int size;
    int top;

    //behavious 
    public:
    Stack(int size){
        this->size= size;
        arr = new int[size];  //creating array dynamically
        top=-1;
    }
    
    void push(int element){
        if( size - top > 1){
            top++;
            arr[top]= element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow";
        }
    }

    int peek(){
        if(top>=0 && top<size)
        return arr[top];

        else{
            cout<<"stack is empty"<<endl;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else return false;
    }

};



int main(){
    //creating a stack //general way of creating stack from STL
    /* stack<int> s;
    s.push(2);
    s.push(3);
    s.pop();   //top most element will be pop out ,removes
    cout<<s.top();
    s.empty();
    cout<<endl<<s.empty();*/

    Stack st(4);
    st.push(22);
    st.push(44);
    st.push(100);
    st.push(534);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl<<endl;

    cout<<st.isEmpty()<<endl;


    return 0;
}