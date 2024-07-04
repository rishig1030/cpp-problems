// implement a trie
#include<iostream>
using namespace std;

class Node{
    public:
    Node* links[26];
    bool flag;
    Node(){
        // all the element in the link is initialized to NULL
        flag = false;
    }

    bool containKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
    Node* root;
    public:

    // initialize the data structure
    Trie(){
        root = new Node();
    }

    // insert a word into the trie
    // Tc - O(L), l is the length of the word
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            // moves to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    // search a word in the trie
    // tc - O(length)
    bool search(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    // check if any word start with given word in trie
    // tc - O(length)
    bool startsWith(string prefix){
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containKey(prefix[i])) return false;

            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    Trie* tire = new Trie();
    tire->insert("noob");
    tire->insert("insert");
    tire->insert("apla");

    cout<<tire->search("apla")<<endl;
    cout<<tire->search("book")<<endl;
    cout<<tire->startsWith("no")<<endl;
    return 0;
}