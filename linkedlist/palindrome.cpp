// check if the linked list is the palindrome or not


#include<iostream>
#include <stack>
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

bool palindrome(node* head){
    stack<int> st;
    node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp ->next;
    }
    temp = head;
    while(temp){
        if(temp->data != st.top()) return false;
        st.pop();
        temp= temp->next;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    node* head = NULL;
    node* tail= NULL;
    
    for(int i=0;i<n;i++){
        
        int data;
        cin>>data;
        insertattail(head,tail,data);
    }
    if(palindrome(head)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}