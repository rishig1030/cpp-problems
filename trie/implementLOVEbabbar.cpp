// implement a trie by love babbar method;
#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie(){ 
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child,word.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0) {
            return root->isTerminal;
        }
        int index  = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        } 
        else return false;
        return searchUtil(child,word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool searchPrefix(TrieNode* root,string word){
        if(word.length() == 0) {
            return true;
        }
        int index  = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        } else return false;
        return searchPrefix(child,word.substr(1));
    }

    bool startsWith(string prefix) {
        return searchPrefix(root,prefix);
    }
};

int main(){
    // can create a trie;
    Trie* t = new Trie();

    t->insert("rishi");
    t->insert("rupta");
    t->insert("rishab");
    cout<<t->search("rishi");
    
    return 0;
}