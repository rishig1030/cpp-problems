// add two number , where digits of each number is the node of a linked list in reverese order
// 6 - 7 - 8 , NUmber is 876
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

void insertattail(node* &head,node* &tail,int data){
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

int number(node* head){
    int num=0;
    while(head){
        num= num*10+(head->data);
        head=head->next;
    }
    int sum=0;
    while(num){
        sum=sum*10 + num%10;
        num/=10;
    }
    return sum;
}

void traversing(node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node* head = NULL;
    node* tail=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;cin>>data;
        insertattail(head,tail,data);
    }
    
    node* head1=NULL;
    node* tail1=NULL;
    int n1; cin>>n1;
    for(int i=0;i<n1;i++){
        int data;
        cin>>data;
        insertattail(head1,tail1,data);
    }
    
    int no1= number(head);
    int no2= number(head1);
    node* head2=NULL;
    node* tail2=NULL;
    int sum = no1+no2;
    while(sum){
        insertattail(head2,tail2,sum%10);
        sum/=10;
    }
    traversing(head2);

    return 0;
}