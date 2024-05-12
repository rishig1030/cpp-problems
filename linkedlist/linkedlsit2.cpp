//inserting element at the middle of linked list 
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->next=NULL;
        this->data=data;
    }
};

//insert the element at the end of linkled list
void insert2ll(node* &tail,int data){
    node* node1 =new node(data);
    

}

int main(){
    node* node1 = new node(10);
    node* head=node1;
    node* tail =node1;
    insert2ll(tail,12);
    return 0;
}