// find the lowest common ancestor of BST
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

node* LCA(node* root,pair<int,int> p){
    if(!root) return NULL;
    if(p.first > root->data && p.second > root->data){
        LCA(root->right,p);
    }
    else if(p.first < root->data && p.second < root->data){
        LCA(root->left,p);
    }
    else return root;
}

int main(){
    node* root = NULL;
    takeinput(root);
    pair<int,int> p = {11,17};
    cout<<"Lowest common ancestor of "<<p.first<<" and "<<p.second<<" is "<<LCA(root,p)->data;
    return 0;
}