// sort the linked list with 0 1 and 2
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
    int count = 0;
    int count1 = 0;

    node* temp = head;
    while(temp){
        if(temp->data == 0){
            count++;
        }
        else if(temp->data == 1){
            count1++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp){
        if(count){
            temp->data=0;
            count = count -1;
        }
        else if(count1){
            temp->data =1;
            count1 = count1 - 1;
        }
        else{
            temp->data= 2;
        }
        temp=temp->next;
    }
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