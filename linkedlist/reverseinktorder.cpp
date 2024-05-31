// reverse a linked list in kth order

#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next= NULL;
    }
};

void insertattail(node* &head,node* &tail,int data){
    node* n1= new node(data);
    if(!head){
        head=n1;
        tail=n1;
    }
    else{
        tail->next= n1;
        tail=n1;
    }
}

node* reverseink(node* &head,int k){
    node* current = head;
    node* previous = NULL;
    int count = k;
    while(current && count--){
        node* forward= current->next;
        current->next= previous;
        previous= current;
        current=forward;
    }
    if(current)
    head->next= reverseink(current,k);
    head= previous;
    return head;
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        insertattail(head,tail,data);
    }
    
    int k; cin>>k;
    reverseink(head,k);
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}