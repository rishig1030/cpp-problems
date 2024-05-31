// find the length of loop in linked list
#include<iostream>
#include<map>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        this->next=NULL;
    }
};

// method 1 
int length(node* &head){
    map<node*,int> mpp;
    node* temp = head;
    int count=1;
    while(temp){
        if(mpp[temp]){
            return count-mpp[temp]; 
        }
        else{
            mpp[temp]=count;
            count++;
        }
        temp=temp->next;
    }
    return 0;
}

// method -2
int length2(node*head){
    node* slow= head;
    node* fast= head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) break;
    }
    int count =0;
    if(fast && fast->next){
        count =1;
        fast=fast->next;
        while(fast != slow){
            count++;
            fast=fast->next;
        }
    }
    return count;
}