//circular linked list , singly and doubly

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //constructor
    public:
    node(int data){
        this->data=data;
        this->next=NULL;
    }

    //distructor (not necessary) if called usinf delete temp/node etc
    public:
    ~node(){    
        int value=this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free from data : "<<value<<endl;
    }

};
//in curcular linked list there is nothing like head and tail 
// we can simply use tail to access head and tail


//to insert th data after elemnet 
void insertnode(node* &tail,int element,int data){
    

    //empty list
    if(tail==NULL){
        node* node1 = new node(data);
        tail= node1;
        node1->next = node1;
    }
    //non empty list  
    //asssuming element is present in linked list
    else{
        node* current = tail;
        while(current->data != element){
            current=current->next;
        }
        node* temp = new node(data);
        temp->next= current->next;
        current->next= temp;
    }
}

//travering using tail , since there is not head, there is no concept of tail as well ,just we are assuming
void print(node* &tail){
    if(tail==NULL){
        cout<<"empty ll"<<endl;
    }
    else{
        node* current = tail;
        do{
            cout<<current->data<<" ";
            current=current->next; 
        }while(current!=tail);
        cout<<endl;
    }
}
//delete a node

void deletenode(int element,node* &tail){
    //empty list 
    if(tail==NULL){
        cout<<"list is already empty"<<endl;
        return;
    }
    else{
        node* prev = tail;
        node* current = tail->next; //cicular
        
        while(current->data != element){
            current=current->next;
            prev=prev->next;
        }
        prev->next = current->next;

        //only one node in ll
        if(current==prev){
            tail=NULL;
        }
        //>=2 node in ll
        else if(tail==current){
            tail=prev;
        }

        current->next=NULL;
        delete current;
    }
}

int main(){
    node* node1= NULL;  //creating a heap memory;
    node* tail=node1;
    //inserting in empty list
    insertnode(tail,5,6);
    print(tail);

    insertnode(tail,6,7);
    print(tail);

    insertnode(tail,6,8);
    print(tail);

    insertnode(tail,6,8);
    print(tail);

    insertnode(tail,8,9);
    print(tail);
    
    deletenode(6,tail);
    print(tail);
    return 0;
}