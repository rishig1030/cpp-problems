// iterative traversing of binary tree
#include <iostream>
#include <stack>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data= data;
        this->left =NULL;
        this->right = NULL;
    }
};

node* buildtree(node* &root){
    cout<<"Enter Data : "<<endl;
    int data;
    cin>>data;
    if(data == -1) return NULL;
    
    root= new node(data);

    cout<<"Enter data at the left of "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data at the right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}

//iterative preorder traversal (NLR)

void preordertraversal(node * root){
    stack <node*> st;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}

//iterative inorder traversaL (LNR)

void inordertraversal(node* root){
    stack<node*> st;
    node* temp = root;
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp= temp->left;
        }
        else{
            if(st.empty()) break;

            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp= temp->right;
        }
    }
}

//iterative approach for post order traversal


int main(){
    node* root = NULL;
    root = buildtree(root);

    cout<<"Preorder traversal : "<<endl;
    preordertraversal(root);

    cout<<endl<<"Inorder Traversal : "<<endl;
    inordertraversal(root);
    return 0;
}