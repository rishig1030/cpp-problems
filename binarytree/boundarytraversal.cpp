// print the boundary order traversal of binary tree
#include<iostream>
#include<stack>
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
    bool isleaf(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        else return false;
    }
};


Node* buildtree(Node* root){
    
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert at left of "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data to inser at right of "<<data<<endl;
    root->right = buildtree(root->right);

    return root;
}
// insert the left part of the tree
void insertheleft(Node* root,vector<int> &v){
    root = root->left;
    while(root){
        if(!root->isleaf(root)) v.push_back(root->data);
        if(root->left) root = root->left;
        else root = root->right;
    }
}

void inserttheright(Node* root,vector<int>&v){
    stack<int> st;
    root=root->right;
    while(root){
        if(!root->isleaf(root)) st.push(root->data);
        if(root->right) root = root->right;
        else root = root->left;
    }
    int size = st.size();
    for(int i=0;i<size;i++){
        v.push_back(st.top());
        st.pop();
    }
}

void inserttheleave(Node* root,vector<int> &v){
    if(root->isleaf(root)){
        v.push_back(root->data);
        return;
    }
    if(root->left) inserttheleave(root->left,v);
    if(root->right) inserttheleave(root->right,v);
}

vector<int> boundarytraversal(Node* root){
    vector<int> v;
    if(!root) return v;
    if(!root->isleaf(root)) v.push_back(root->data);
    insertheleft(root,v);
    inserttheleave(root,v);
    inserttheright(root,v);
    return v;
}

//algorithemtic time complexity is O(log n + log n + N) = O(N);
// space complexity is O(N) - auxillary space excluding the space used to return answer


int main(){
    Node* root = buildtree(NULL);
    vector<int> v;
    v = boundarytraversal(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}