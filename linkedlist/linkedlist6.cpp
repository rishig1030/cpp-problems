//reverse an linked list in kth group
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

//insert in ll at the tail 
void insert2tail(node* &tail, int d){
    node* temp = new node(d);
    tail->next = temp;
    tail = tail->next;
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

node* krevrese(node* head,int k){
    if(head==NULL){
        return NULL;
    }
    //reverse 1st case node;
    node* next= NULL;
    node* current = head;
    node* previous = NULL;
    int count=0;
    while(current != NULL && count<k){
        next= current->next;
        current->next= previous;
        previous=current;
        current=next;
        count++;
    }

    //recusrion
    if(next != NULL){
        head->next=krevrese(next,k); 
    }
     
    return previous;
    
}

int main(){
    node* temp= new node(2);
    node* head= temp;
    node* tail= temp;
    insert2tail(tail,5);
    insert2tail(tail,22);
    insert2tail(tail,21);
    insert2tail(tail,62);
    insert2tail(tail,4);
    print(head);
    int k;
    cin>>k;
    head= krevrese(head,k);
    print(head);
    return 0;
}