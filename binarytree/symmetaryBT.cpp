//check if the BT is symmetary or not
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
bool check(Node* left,Node* right){
    if(left==NULL || right==NULL) return left == right;
    if(left->data != right->data) return false;

    // checking if the mirror image is equal or not in both the side
    return check(left->left,right->right) && check(left->right,right->left);
}

bool checktree(Node* root){
    if(!root) return true;
    if(check(root->left,root->right)) return true;
    else return false;
}

int main(){
    Node* root = buildtree(NULL);
    if(checktree(root)) cout<<"True";
    else cout<<"false";
    return 0;
}