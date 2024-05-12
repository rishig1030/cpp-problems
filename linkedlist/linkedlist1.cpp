//linked list is similar to array with non contigious memory location , or it is the collection of nodes
// head loaction of starting element of Linked list
// next is the address of next element of linked list
// tail is the address of ending element 

//all types of insertions
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;   //pointer is of node type, bcoz its storing address of next node
     
    //need to create constructor inorder to give values, initially
    Node(int data){
        this->next=NULL;
        this->data=data;
    }
};




void insert2head(Node* &head, int d){
    //new node create 
    Node* temp = new Node(d);
    //inserting at the starting of linked list 
    temp -> next = head;
    head = temp;
}

void insert2tail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}


void insertatPosition(Node* &head,Node* &tail,int position,int data){
    //if want to insert at starting
    if(position==1){
        insert2head(head,data); //technically inserting it at head/starting only
        return ;
    }

    //traverse till position-1 element
    Node* temp=head;
    int count=1 ;//(at head)
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //if inserrting at last position
    if(temp->next==NULL){
        insert2tail(tail,data);
        return;
    }
    Node* data2insert= new Node(data);
    data2insert->next=temp->next;
    temp->next=data2insert;

}

//to traverse a linked list 
void print(Node* &head){
    Node* temp = head; //temp is the address of head

    while(temp != NULL){
        cout<< temp -> data<<" ";
        temp = temp->next; // address directing to next element of linked list
    }
    cout<<endl;
}
int main(){
    Node* node1= new Node(10);
    //cout<<node1->data<<endl<<node1->next<<endl;    
    Node* head = node1;
    Node* tail = node1;
    insert2tail(tail,12);
    print(head);

    insert2head(head,17);
    print(head);

    
    insertatPosition(head,tail,2,14);
    print(head);


    cout<<"head verify: "<<head->data<<"  ";
    cout<<"tail data: "<<tail->data;
    return 0;
}