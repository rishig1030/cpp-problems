//INCOMPLETE

// find the maximum width of given binary tree
// width can be defined as the number of nodes between any two nodes
// between nodes can be imaginary

#include<iostream>
#include<vector>
#include<queue>
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

int width(Node* root){
    
}

int main(){
    Node* root = buildtree(NULL);
    cout<<width(root);
    return 0;
}