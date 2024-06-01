// apply merge sort in a LL
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node* &head,Node* & tail,int data){
    Node* n1= new Node(data);
    if(!head){
        head = n1;
        tail = n1;
    }
    else{
        tail->next = n1;
        tail = n1;
    }
}

void traverse(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* findmiddle(Node* head){
    Node* slow =head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast= fast->next->next;
    }
    return slow;
}

Node* merge(Node* lefthead,Node* righthead){
    Node* head = NULL;
    Node* temp = head;
    while(lefthead && righthead){
        if(lefthead->data < righthead->data){

            if(!head){
                head = lefthead;
                temp = lefthead;
            }
            else{
                temp->next = lefthead;
                temp = lefthead;
            }
            lefthead = lefthead->next;
        }
        else{
            if(!head){
                head = righthead;
                temp = righthead;
            }
            else{
                temp->next = righthead;
                temp = righthead;
            }
            righthead = righthead->next; 
        }
    }
    while(lefthead){
        if(!head){
                head = lefthead;
                temp = lefthead;
            }
            else{
                temp->next = lefthead;
                temp = lefthead;
            }
            lefthead = lefthead->next;
    }
    while(righthead){
        if(!head){
                head = righthead;
                temp = righthead;
            }
            else{
                temp->next = righthead;
                temp = righthead;
            }
            righthead = righthead->next; 
    }
    return head;
}

Node* mergesort(Node* head){
    if(!head || head->next == NULL) return head;

    Node* middle = findmiddle(head);
    Node* lefthead = head;
    Node* righthead = middle->next;
    middle->next = NULL;
    lefthead =  mergesort(lefthead);
    righthead = mergesort(righthead); 
    return merge(lefthead,righthead);
}

int main(){
    int n;
    cin>>n;
    Node* head = NULL;
    Node* tail = NULL;
    while(n--){
        int data; cin>>data;
        insertattail(head,tail,data);
    }
    head = mergesort(head);

    traverse(head);
    return 0;
}