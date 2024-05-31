// rotate a linked list kth time
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->next=NULL;
        this->data= data;
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

void rotate(node* &head, int k){
    int length = 0;
    node* temp=head;
    while(temp){
        temp=temp->next;
        length++;
    }
    
    k=k%length;
    temp= head;
    int y = length-k-1;
    while(y--){
        temp=temp->next;
    }
    if(temp->next){
        node* newhead= temp->next;
        temp->next=NULL;
        temp=newhead;
        while(temp->next){
            temp=temp->next;
        }
        temp->next= head;
        head= newhead;
    }
    else return;
    
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
    rotate(head,k);
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}