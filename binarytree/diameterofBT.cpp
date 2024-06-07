// find the diameter of any binary tree
// diameter can be defined as the longest path between the nodes and it need not to pass through the root,it can but need not
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

int diameter(Node* root,int &m){
    if(!root) return 0;
    
    int lh = diameter(root->left,m);
    int rh = diameter(root->right,m);
    m = max(m,lh+rh);
    return 1+max(lh,rh);

}

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

int main(){ 
    Node* root = NULL;
    root = buildtree(root);
    int m = 0;
    diameter(root,m);
    cout<<m;
    return 0;
}