// design a BST iterator
// means to print the inorder , next , or preorder has next

#include<iostream>
#include<vector>
#include<stack>
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

class BSTiterator{
    private:
    stack<Node*> st;
    public:
    BSTiterator(Node* root){
        push(root);
    }
    int next(){
        int n = st.top()->data;
        Node* temp = st.top();
        st.pop();
        push(temp);
        return n;
    }
    void push(Node* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    bool hasnext(){
        if(!st.empty()) return true; 
        else return false;
    }
};