// count the number of distinct substring in an array
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    Node* links[26];
    // bool flag = false;

    bool containKey(char ch){
        return links[ch-'a']!=NULL;
    }

    // void setEnd(){
    //     flag = true;
    // }

    // bool isEnd(){
    //     return flag;    
    // }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    int count  = 0;
    void insert(string word){
        for(int i=0;i<word.size();i++){
            Node* node = root;
            for(int j=i;j<word.size();j++){
                if(!node->containKey(word[i])){
                    node->put(word[i],new Node());
                    count++;
                }
                node = node->get(word[i]);
            }
        }
        // node->setEnd();
    }

    int countDistinctsubstring(){
        return count+1;
    }
};

int main(){
    string st;
    cin>>st;
    Trie* trie = new Trie();
    trie->insert(st);
    cout<<trie->countDistinctsubstring();
    return 0; 
}