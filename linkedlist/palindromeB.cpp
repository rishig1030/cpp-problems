#include<iostream>
using namespace std;

// we will find the middle of a linked list and reverse the second half , now compare first half and second half

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        this->next = NULL;
    }
};
void insertattail(node* &head,node* &tail,int data){
    node* n1= new node(data);
    if(head==NULL){
        head = n1;
        tail=n1;
    }
    else{
        tail->next=n1;
        tail=n1;
    }
}
node* reverse(node* head){
    node* previous=NULL;
    node* current = head;
    while(current){
        node* forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    node * newhead = previous;
    return newhead;
}

bool palindrome(node* &head){
    if(!head) return true;
    node* slow = head;
    node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    node* newhead = reverse(slow->next);
    node* temp1=head;
    node* temp2= newhead;
    while(temp2){
        if(temp1->data != temp2->data) return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    reverse(newhead);
    return true;
}

int main(){
    int n;
    cin>>n;
    node* head = NULL;
    node* tail = NULL;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        insertattail(head,tail,data);
    }
    if(palindrome(head)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}