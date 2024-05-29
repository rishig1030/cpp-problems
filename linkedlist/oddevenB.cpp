#include<iostream>
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

void inserting(node* &head,node* &tail,int data){
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
void evenodd(node* head){
    node* odd= head;
    node* even= head->next;
    node* evenhead=head->next;
    while(even && even->next){
        odd->next=even->next;
        even->next=odd->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
}

//time complexity will be O(N/2 * 2 ) , since two operation in inside loop
//space complexiyt is O(1) , no extra space is utilised

void traversing(node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node* head= NULL;
    node* tail = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        inserting(head,tail,data);
    }
    evenodd(head);
    traversing(head);
    return 0;
}