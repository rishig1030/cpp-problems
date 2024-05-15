//reverse a dll , by iterative
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* previous;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->previous=NULL;
    }
};

//insert in dll at the tail 
void insert2tail(node* &tail,node* &head,int data){
    //in case of empty list
    if(tail==NULL){
        node* temp = new node(data);
        tail= temp;
        head=temp;
    }
    else{
        node* temp = new node(data);
        tail->next=temp;
        temp->previous=tail;
        tail=temp;
    }
}

//traverse a dll
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//reverse a dll 
void reverse(node* &head){
    node* current = head;
    node* previous = NULL;
    while(current != NULL){
        node* forward = current ->next;
        current->next= previous;
        previous= current;
        current = forward;
    }
    head= previous;
}

int main(){
    node* head= NULL;
    node* tail= NULL;
    insert2tail(tail,head,2);
    insert2tail(tail,head,5);
    insert2tail(tail,head,22);
    insert2tail(tail,head,21);
    insert2tail(tail,head,62);
    insert2tail(tail,head,4);
    print(head);
    reverse(head);
    print(head);
}
//time complexity = O(N);
//space complexity = O(1)