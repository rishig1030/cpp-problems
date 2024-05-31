// find the pair with given sum in a DLL
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* previous;
    node* next;
    node(int data){
        this->data= data;
        this->previous= NULL;
        this->next= NULL;
    }
};

void insertdata(node* &head ,node* & tail,int data){
    node* n1= new node(data);
    if(!head){
        tail= n1;
        head = n1;
    }
    else{
        tail->next = n1;
        tail=n1;
    }
}

void find(node* head,int sum,vector<pair<int,int>> &v){
    node* left = head;
    node* right = head;
    while(right->next!=NULL){
        right = right->next;
    }
    // time complixity is O(N)
    //space complexity is O(1) , no extra space other than answer vector
    while(left->data < right->data){
        if(left->data + right->data > sum){
            right= right->previous;
        }
        else if(left->data + right->data < sum){
            left = left->next;
        }
        else{
            v.push_back({left->data,right->data});
            left=left->next;
            right = right->previous;
        }
    }
}

int main(){
    int n;
    cin>>n;
    node* head = NULL;
    node* tail = NULL;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        insertdata(head,tail,data);
    }

    int sum; cin>>sum;
    vector<pair<int,int>> v;
    find(head,sum,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;

}