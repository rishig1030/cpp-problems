// write the top view of binary tree
#include<bits/stdc++.h>
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

vector<int> topview(Node* root){

    // make a map top store the unique value with thier level
    map<int,int> nodes;
    // make a queue for the traversal in th etree with ungrading its level
    queue<pair<Node*,int>> q; 
    if(root) q.push({root,0});

    
    while(!q.empty()){
        //for bottom view remove this condition and update everytime to get the bottom most value
        if(!nodes[q.front().second])
        nodes[q.front().second] = q.front().first->data;
        if(q.front().first ->left) q.push({q.front().first ->left , q.front().second-1});
        if(q.front().first ->right) q.push({q.front().first ->right , q.front().second+1});
        q.pop();
    }

    // traverse the map;
    vector<int> v;
    for(auto i: nodes){
        v.push_back(i.second);
    }
    return v;
}

int main(){
    Node* root = buildtree(NULL);
    vector<int> v = topview(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}