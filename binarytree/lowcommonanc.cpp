// find the lowest common ancestor of two nodes,

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildtree(Node* root){
    cout<<"Enter data: ";
    int data;
    cin>>data ;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);

    cout<<"Enter data at the left of "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data at the right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}

Node* LCA(Node* root,pair<Node*,Node*> p){
    // return null if not found
    if(!root) return NULL;

    // if found then return the value
    if(root->data == p.first->data || root->data == p.second->data){
        return root;
    }

    Node* x = LCA(root->left,p);
    Node* y = LCA(root->right,p);
    // if found both the side return the ancestor
    if(x && y) return root;
    // if found only right side return the data
    else if(x) return x;
    // else return the right side value either the data or id not found then value;
    else return y;
}

int main(){
    Node* root = buildtree(NULL);
    Node* temp1 = new Node(21);
    Node* temp2 = new Node(11);
    pair<Node*,Node*> p = {temp1,temp2};
    Node* ans = LCA(root,p);
    cout<<endl;
    cout<<ans->data<<endl;
    return 0;
}