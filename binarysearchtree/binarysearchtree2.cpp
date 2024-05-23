// delete a node from bst
#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node* insertinBST(node* &root,int data){
    //if nuLL node
    if(root == NULL){
        root  = new node(data);
        return root;
    }
    if(data <= root->data){
        //insert at left part
        root->left = insertinBST(root->left,data);   
    }
    else{
        //insert at the the right part
        root->right = insertinBST(root->right,data);
    }
    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        insertinBST(root,data);
        cin>>data;
    }
}

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

//max in a BST
node* maxval(node* root){
    node* temp = root;

    while(temp->right != NULL){
        temp = temp ->right;
    }
    return temp;
}

//min in a BST
node* minval(node* root){
    node* temp = root;

    while(temp->left != NULL){
        temp = temp ->left;
    }
    return temp;
}

node* deleteANode(node* root,int X){
    if(root == NULL){
        return root;
    }

    if( root->data == X){
        //zero child 

        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //one child 
            //left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
            //right child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        //two child
        if(root->left != NULL && root->right != NULL){
            //find min value from right , or the max value from left ,whatever can be done
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deleteANode(root->right,mini);
            return root;

            //or 
            /*int max = maxval(root->left)->data;
                root->data = max;
                root->left = deleteANode(root->left , max)
                return root
            */
        }
    }

    else if(root->data > X){
        root->left = deleteANode(root->left , X);
        return root;
    }
    else{
        root->right = deleteANode(root->right , X);
        return root;
    }
}

//time complexity avg case = O(h) and worst case O(n);

int main(){

    node* root = NULL;
    takeinput(root);
    levelOrderTraversal(root);
    int X;
    cout<<"write the node to be deleted: ";
    cin>>X;
    deleteANode(root,X);
    cout<<"level order traversal after deletion"<<endl;
    levelOrderTraversal(root);
    return 0;
}