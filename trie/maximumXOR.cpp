// Q. for bit manipulation using trie
// given two array we need to find the max of element of (arr1 XOR element of arr2)
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    Node* links[2];

    bool containKey(int bit){
        return (links[bit]!=NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit,Node* node){
        links[bit] = node;
    }

};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    // insert the binary code of number into the trie
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = ((num >> i) & 1);
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i)&1);
            //contain or not , since we need to find the opposite bit , to get XOR max
            if(node->containKey(1-bit)){
                node = node->get(1-bit);
                maxNum =  (maxNum | (1<<i));
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(vector<int> arr,vector<int> arr2,int n,int m){
    Trie* trie;
    for(auto &it:arr){
        trie->insert(it);
    }
    int maxi = 0;
    for(auto &ji:arr2){
        maxi = max(maxi,trie->getMax(ji));
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m ;
    cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[m];
    }
    int result = maxXOR(arr,arr2,n,m);
    cout<<"max XOR is "<<result<<endl;
    return 0;
}