// detect wheather the linked list contains any loop or not
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

//METHOD - 1
bool check(node* head){
    map<node*,int> mpp;
    node* temp= head;
    while(temp){
        if(mpp[temp] == 1){
            return true;
        }
        else{
            mpp[temp]=1;
        }
        temp=temp->next;
    }   
    return false;
}
//can run the code since no input parameter
// time complexity O(n* time complexity for the insertion of in hashmap)
// space complexity is O(n) , in hash

// METHOD -2 
bool check2(node* head){
    node* slow = head;
    node* fast= head;
    while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
// here time complexity is O(N);
// space complexity is O(1);