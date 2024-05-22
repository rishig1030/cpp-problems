// create a tree from level order traversal

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
        left = NULL;
        right = NULL;
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

void buildfromlevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for node "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter data for left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter data for right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }
}
int main(){
    node* root = NULL;
    buildfromlevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}