// print the right view of the binary tree
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

void rightview(Node* root,int level,vector<int>&v){
    if(!root) return;

    // if level == size that mean we are visiting this level for the first time 
    if(v.size()==level){
        v.push_back(root->data);
    }
    //traversing the nodes
    rightview(root->right,level+1,v);
    rightview(root->left,level+1,v);
}

int main(){
    Node* root = buildtree(NULL);
    vector<int> v;
    rightview(root,0,v);
    cout<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}