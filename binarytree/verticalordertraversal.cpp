
// vertical order traversal
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
};

vector<vector<int>> verticalordertraversal(Node* root){
    vector<vector<int>> ans;
    map<int,map<int,multiset<int>>> nodes;   // value, vertical order, level
    queue<pair<Node*,pair<int,int>>> q;      // for traversal , {Node,{vertical,level}}
    
    if(root) q.push({root,{0,0}});

    while(!q.empty()){
        Node* node = q.front().first;

        // inserting to the map
        nodes[q.front().second.first][q.front().second.second].insert(q.front().first->data);

        // push the next element to the queue
        if(node->left) q.push({node->left,{q.front().second.first -1,q.front().second.second + 1}});
        if(node->right) q.push({node->right,{q.front().second.first + 1,q.front().second.second + 1}});
        q.pop();
    }

    //traversing
    for(auto i:nodes){
        vector<int> v;

        // traversing each vertical values
        for(auto j:i.second){
            // inserting the map value,that contain intger and mapset
            v.insert(v.end(),j.second.begin(),j.second.end());
            //j.second represnt that the mapset is executed and traversing it form begin to end
        }
        ans.push_back(v);
    }
    return ans;
} 


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

int main(){
    Node* root = buildtree(NULL);
    vector<vector<int>> v = verticalordertraversal(root);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}