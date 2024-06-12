// construct a BST from Pre order traversal

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
// root left root , preorder 
Node* construct(vector<int> v,int &i,int bound){
    // checking if the root satisfy the condition
    if(i==v.size() || v[i]>bound) return NULL;

    Node* root = new Node(v[i++]);
    root->left = construct(v,i,root->data);
    root->right = construct(v,i,bound);
    return root;

}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        v.push_back(data);
    }
    int i=0;
    Node* root = construct(v,i,INT16_MAX);
    inorder(root);
    return 0;
}