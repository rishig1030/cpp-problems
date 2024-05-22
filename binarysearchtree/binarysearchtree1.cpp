//insert a node in binary search tree 
#include<queue>
#include <iostream>
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

node* insertinBST(node* &root,int data){
    //if nuLL node
    if(root == NULL){
        root  = new node(data);
        return root;
    }
    if(data <= root->data){
        //insert at right part
        root->left = insertinBST(root->left,data);   
    }
    else{
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
//time complexity fro insertion is O(logN) // or O(h)  -- h is the height of binary search tree i.e. == logN
//similar to binary search and similar approach to find it 
//space complexity is also O(log N)  // occupied by recusive stack

int main(){
    
    node* root = NULL;
    cout<<"enter data to create BST "<<endl;
    takeinput(root);

    cout<<"priting the BST "<<endl;
    levelOrderTraversal(root);
    return 0;

}