// find the ceil and floor in a binary tree
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertinBST(node* &root,int data){
    //if nuLL node
    if(root == NULL){
        root  = new node(data);
        return root;
    }
    if(data <= root->data){
        //insert at right part
        root->left = insertinBST(root->left,data);   
    }
    else{
        root->right = insertinBST(root->right,data);
    }
    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        insertinBST(root,data);
        cin>>data;
    }
}

// the smallest value in the tree which is greater than equal to the key. 
int ceil(node* head,int val){
    int c = -1;
    while(head){
        if(head->data<val) head = head->right;
        else if(head->data>val) {
            c = head->data;
            head = head->left;
        }
        else{
            c = head->data;
            return c;
        }
    }
    return c;
}
// largest value smaller than the value given
int floor(node* root,int val){
    int c = -1;
    while(root){
        if(root->data > val){
            root = root->left;
        }
        else if(root->data < val){
            c = root->data;
            root = root->right;
        } 
        else{
            return root->data;
        }
    }
    return c;
}

int main(){
    node* root = NULL;
    takeinput(root);

    int ceils = ceil(root,8);
    cout<<"ceil = "<<ceils<<endl;

    int floors = floor(root,7);
    cout<<"floor = "<<floors;
    return 0;
}