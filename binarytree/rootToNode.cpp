// find the path from root to node
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

bool getpath(Node* root,vector<int> &v,int data){
    // if root is null means at leaf , hence doesn't reach the value , we will return false
    if(!root) return false;
    v.push_back(root->data);
    // if root is equal to data , we reached return true
    if(root->data == data) return true;

    // if either left or right gives the desire output return the value
    if(getpath(root->left,v,data) || getpath(root->right,v,data)){
        return true;
    }
    // pop th value if not on the side
    v.pop_back();
    return false;
}

vector<int> findthepath(Node* root,int data){
    vector<int> v;
    if(!root) return v;
    getpath(root,v,data);
    return v;
}

int main(){
    Node* root = buildtree(NULL);

    int data;
    cin>>data;
    vector<int> v = findthepath(root,data);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}