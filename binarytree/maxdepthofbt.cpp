// find the maximum depth of binary tree
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

Node* buildtree(Node* root){
    cout<<"Enter Data : "<<endl;
    int data; cin>>data;
    if(data == -1){
        return NULL;
    }

    root = new Node(data);
    cout<<"Enter Data for the left of "<<data <<endl;
    root->left = buildtree(root->left);
    cout<<"Enter Data for the right of "<<data <<endl;
    root->right = buildtree(root->right);
    return root;
}

int maxheight(Node* root){
    if(root == NULL)
    return 0;

    else{
        return 1 + max(maxheight(root->left),maxheight(root->right));
    }
}

int main(){
    Node* root =NULL;
    root= buildtree(root);

    cout<<maxheight(root);
    return 0;
}