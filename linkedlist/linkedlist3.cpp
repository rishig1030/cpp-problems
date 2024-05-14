//double linked list
//it consists of data, previous and next
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* previous;
    //constructor
    public:
    node(int data){
        this->data=data;
        this->next=NULL;
        this->previous=NULL;
    }
};

//traversing a double linked list
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//length of double linked list
int dlll(node* &head){
    int length=0;
    node* temp= head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

//insert at head in double linked list
void insert2head(node* &head,node* &tail,int data){
    //in case of empty list
    if(head==NULL){
        node* temp = new node(data);
        head= temp;
        tail=temp;
    }
    else{
        node* temp= new node(data);
        head->previous=temp;
        temp->next= head;
        head=temp;
    }
}

//insert2tail in double linked list
void insert2tail(node* &tail,node* &head,int data){
    //in case of empty list
    if(tail==NULL){
        node* temp = new node(data);
        tail= temp;
        head=temp;
    }

    node* temp = new node(data);
    tail->next=temp;
    temp->previous=tail;
    tail=temp;
}

//insert at any position in dll
void insertatposition(node* &head,node* &tail,int position,int data){

    if(position==1){
        insert2head(head,tail,data);
        return;
    }
    node* temp= head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insert2tail(tail,head,data);
        return;
    }
    node* node1= new node(data);
    node1->next=temp->next;
    temp->next=node1;
    node1->previous=temp;
    (node1->next)->previous=node1;

}

void deleteatposition(int position, node* &head,node* &tail){
    //deleting the head
    if(position==1){
        node* current= head;
        head->next->previous=NULL;
        head=current->next;
        current->next=NULL;
        delete current;
    }
    //deleting other element of head
    else{
        node* current = head;
        int count=1;
        while(count<position){
            count++;
            current=current->next;
        }
        if(current->next==NULL){
            tail=current->previous;
            current->previous->next=NULL;
            current->previous=NULL;
        }
        else{
            (current->previous)->next=current->next;
            (current->next)->previous=current->previous;
            current->previous=NULL;
            current->next=NULL;
            delete current;
        }
    }
}

int main(){

    node* node1= new node(10);
    node* head=node1;
    node* tail= node1;
    print(head);
    
    cout<<dlll(head)<<endl;
    insert2head(head,tail,19);
    print(head);
    
    insert2tail(tail,head,34);
    print(head); 

    insertatposition(head,tail,4,87);
    print(head);

    deleteatposition(1,head,tail);
    print(head); 
    cout<<head->data<<" "<<tail->data;
    return 0;
}