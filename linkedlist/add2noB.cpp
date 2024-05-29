// add two number in linked list

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
};
void inserting(node* &head,node* &tail,int data){
    node* n1= new node(data);
    if(head==NULL){
        head=n1;
        tail=n1;
    }
    else{
        tail->next=n1;
        tail=n1;
    }
 }

node* sum(node* head,node* head1){
    node* sumhead=NULL;
    node* sumtail=NULL;
    int carry=0;
    while(head!=NULL || head1!=NULL){
        int sum;
        if(head!=NULL && head!=NULL){
            
            sum=(head->data + head1->data + carry)%10;
            carry=(head->data + head1->data + carry)/10;
            
            head=head->next;
            head1=head1->next;
        }
        else if(head==NULL){
            
            sum = (head1->data + carry)%10;
            carry = (head1->data + carry)/10;
            
            head1=head1->next;
        }
        else if(head1==NULL){
            sum = (head->data + carry)%10;
            carry = (head->data + carry)/10;
            head=head->next;
        }
        inserting(sumhead,sumtail,sum);
    }
    if(carry){
        inserting(sumhead,sumtail,carry);
    }
    return sumhead;
}

void travering(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d; cin>>d;
        inserting(head,tail,d);
    }

    node* head1 = NULL;
    node* tail1 = NULL;
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
        int d; cin>>d;
        inserting(head1,tail1,d);
    }
    node * head2=sum(head,head1);
    travering(head2);

    return 0;
}