#include <iostream>
#include<queue>

using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int d){
        this->data=d;
        this->left= NULL;
        this->right= NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert at left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to inser at right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}
// input = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
//traversal
//1.level order traversal - level wise print the tree data
/*1 
  3 5 
  7 11 15*/

void levelOrderTraversal(node* root){
    //using queue only
    queue<node*>  q;
    q.push(root);
    q.push(NULL); //seperator is used to differentiate the level

    while(!q.empty()){
        node* temp = q.front();
        
        q.pop();

        //if temp == null , that means we have traverse the previous level
        if(temp == NULL) {
            
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);  //seperator
            }
        }
        
        //each level will be filled in these two (else's) ,  if temp is not NULL.
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    } 


}

//2. Inorder traversal (LNR - left node right)
//o/p = 7 3 11 1 17 5
void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);  //Left
    cout<<root->data<<" ";     //Node print
    inorder(root->right); //Right
}

// 3. preorder traversal (NLR)

void preorder(node* root){
    if(root == NULL){
            return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// 3. postorder traversal (NLR)

void postorder(node* root){
    if(root == NULL){
            return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    node* root = NULL;

    // create a tree
    root = buildTree(root);
    cout<<"output Tree looks like :"<<endl;
    levelOrderTraversal(root);
    cout<<"Inorder traversal output : "<<endl;
    inorder(root); 
    cout<<endl;
    cout<<"Preorder traversal output : "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal output : "<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}