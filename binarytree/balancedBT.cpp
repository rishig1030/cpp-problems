// check if the binary tree is balanced or not
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

/*
time complexity is O(N2)
space complexity is O(n2)

int height(Node* root){
    if(!root) return 0;
    else return 1 + max(height(root->left),height(root->right));
}

bool checkBT(Node* root){
    if(root = NULL) return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh - rh > 1) return false;

    if(checkBT(root->left) && checkBT(root->right)) return true;
    
    return false;
    
}
*/

// time complexity is O(N)
// space complexity is O(N) for recursion auxillary space
int height(Node* root){
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh ==-1 || rh ==-1) return -1;
    if(abs(lh-rh) > 1) return -1;
    return 1+max(lh,rh); 
}

// optimithod to check
bool checkBT(Node* root){
    if(height(root) != -1) return true;
    else return false;
}

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

int main(){
    Node* root = NULL;
    root = buildTree(root);

    if(checkBT(root)) cout<<true;
    else cout<<false;
    return 0;
}