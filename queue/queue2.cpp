#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next= NULL;
    }

    ~node(){
        if(this->next != NULL){
            delete next;
            next= NULL;
        }
    }
};

class Queue{
    public:
    node* front=NULL;
    node* rare=NULL;

    void push(int d){
        node* n1= new node(d);
        if(front == NULL){
            front=n1;
            rare=n1;
        }
        else{
            rare->next=n1;
            rare=n1;
        }
    }
    
    void pop(){
        if(front != NULL){
            node* n1= front->next;
            front->next=NULL;
            delete front;
            front = n1;
        }
        else {
            cout<<"queue underflow"<<endl;
        }
    }

    int first(){
        if(front == NULL){
            return -1;
        }
        else{
            return front->data;
        }
    }

    bool isempty(){
        if(front==NULL){
            return true;
        }
        else return false;
    }
};

int main(){
    Queue q;
    for(int i=0;i<5;i++){
        int d;
        cin>>d;
        q.push(d);
    }
    q.pop();
    cout<<q.first()<<endl;
    q.pop();
    cout<<q.first()<<endl;
    q.pop();
    cout<<q.first()<<endl;
    q.pop();
    cout<<q.first()<<endl;
    q.pop();
    if(q.isempty()){
        cout<<"Empty "<<endl;
    }
    else{
        cout<<"not Empty"<<endl;
    }
    return 0;
}