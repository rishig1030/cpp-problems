// sort the linked list contain all the 0s 1s and 2s 
// connect all the 0s , 1s and 2s together and than connect each with each other
#include<iostream>
using namespace std;
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

void sort(node* &head){
    node* zerohead= new node(-1);
    node* onehead = new node(-1);
    node* twohead = new node(-1);
    node* one = onehead;
    node* two = twohead;
    node* zero = zerohead;
    node* temp = head;
    head = zerohead;
    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero=temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one=temp;
        }
        else{
            two->next= temp;
            two=temp;
        }
        temp=temp->next;
    }
    
    zero->next = (onehead->next)?onehead->next:twohead->next; // if no zero 
    one->next = twohead->next;
    two->next = NULL;
    head = zerohead->next;
    zerohead->next = NULL; delete zerohead;
    onehead->next= NULL; delete onehead;
    twohead->next=NULL; delete twohead;
}

int main(){
    int n;
    cin>>n;
    node* head = NULL;
    node* tail= NULL;
    cout<<"enter number 0 1 or 2 : ";
    for(int i=0;i<n;i++){
        
        int data;
        cin>>data;
        insertattail(head,tail,data);
    }
    sort(head);
    node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}
