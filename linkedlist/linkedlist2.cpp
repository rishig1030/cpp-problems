//deleting an element from linked list 
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    //constructor
    node(int data){
        this->next=NULL;
        this->data=data;
    }
};

void deletenode(int position,node* &head,node* &tail){
    
    //deleting starting node
    if(position == 1){
        node* temp = head;
        head = head->next;
        
        temp->next=NULL;
        //memory free
        delete temp; // deleting by using manual distructor
    }

    else{
        node* previous = NULL;
        node* current = head;
        int count =1;
        while(count<position){
            previous = current;
            current = current->next;
            count++;
        }
        previous->next = current->next;
        if(previous->next==NULL){
            tail=previous;
        }
        current->next = NULL;
        delete current;
    }

}

void insertattail(node* &tail,int data){
    node* temp= new node(data);
    tail->next=temp;
    tail=temp;
}

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* node1= new node(10);
    node* tail= node1;
    node* head= node1;
    insertattail(tail,12);
    insertattail(tail,22);
    insertattail(tail,42);
    insertattail(tail,21);
    print(head);
    
    deletenode(4,head,tail);
    print(head);
    return 0;
}