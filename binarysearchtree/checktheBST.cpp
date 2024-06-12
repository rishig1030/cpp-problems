// check if the given BST is valid or not

#include<iostream>
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

Node* buildTree(Node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert at left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to inser at right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

bool checkBST(Node* root,int min,int max){
    if(!root) return true;
    if(root->data > max || root->data < min){
        return false;
    }
    if(checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max)) return true;
    else return false;
}

int main(){
    Node* root = buildTree(NULL);
    if(checkBST(root,INT16_MIN,INT16_MAX)) cout<<"True";
    else cout<<"false";
    return 0;
}