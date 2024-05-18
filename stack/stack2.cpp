//stack implementation using libnked list
#include <iostream>
using namespace std;

//to implement using linked list , we will always push and pop from head side
//so that the time complexity will be O(1) ,else it would be O(n)

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        this->next= NULL;
    }
};

class stack{
    public:
    node* top =NULL;

    void push(int element){
        node* node1= new node(element);
        node1->next= top;
        top= node1;
    }

    void pop(){
        if(top!=NULL){
            node* n1= top->next;
            top->next = NULL;
            delete top;
            top= n1;
        }
        else {
            cout<<"stack  underflow";
        }
    }

    void display(){
        node* n1= top;
        while(n1!=NULL){
            cout<<n1->data<<" ";
            n1=n1->next;
        }
        cout<<endl;  
    }

    int peek(){
        if(top!=NULL)
        return top->data;

        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else return false;
    }

    //use to free up the memory in case of class is destroyed
    //distructor
    ~stack(){
        while (top!=NULL)
        {
            pop();
        }
        
    }
};

int main(){
    stack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); // Output: 30 20 10 

    cout << "Peek: " << stack.peek() << endl; // Output: Peek: 30

    stack.pop(); // Output: Popped 30 from the stack (implied by display output)
    stack.display(); // Output: 20 10 

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? No


    return 0;
}