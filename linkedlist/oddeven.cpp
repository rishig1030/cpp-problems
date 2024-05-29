// group all the even and odd index nodes 
#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        this->next= NULL;
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

void evenodd(node* &head,vector<int> &v){
    node* temp=head;
    while(temp ){
        v.push_back(temp->data);
        if(temp->next != NULL)
        temp=temp->next->next;
        else temp=NULL;
    }
    temp=head->next;
    while(temp){
        v.push_back(temp->data);
        if(temp->next !=NULL)
        temp=temp->next->next;
        else temp=NULL;
    }
    temp=head;
    for(int i=0;i<v.size();i++){
        temp->data=v[i];
        temp=temp->next;
    }
}

void traverse(node* head){
    while(head){
        cout<<head->data<<" ";
        head= head->next;
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
    vector<int> v;
    evenodd(head,v);
    traverse(head);

    return 0;

}