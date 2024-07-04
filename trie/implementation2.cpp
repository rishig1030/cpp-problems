// implementing trie - 2
// count the number of times a word appears , number of times it starts & erase
#include<iostream>
using namespace std;

class Node{
    public:
    Node* links[26];
    int EndWith;
    int CountPrefix;


    bool ContainKey(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    void increaseEnd(){
        EndWith++;
    }

    void prefixIncrease(){
        CountPrefix++;
    }



    void deleteEnd(){
        EndWith--;
    }

    void reducePrefix(){
        CountPrefix--;
    }
};

// time complexity for all the words is O(N)
class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->ContainKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->prefixIncrease();
        }
        node->increaseEnd();
    }

    // count word equal to 
    int countWordEqualto(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->ContainKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->EndWith;
    }

    // count the number of prefix
    int countStartwiht(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->ContainKey(word[i])){
                node = node->get(word[i]);
            }
            else return 0;
        }
        return node->CountPrefix;
    }

    // to erase a node
    void erase(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->ContainKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return ;
            }
        }
        node->deleteEnd();
    }
};

int main(){
    Trie* trie = new Trie();
    trie->insert("samsung");
    trie->insert("iPhone");
    trie->insert("motorola");
    trie->insert("vivo");
    trie->insert("sam");
    trie->insert("samsung");
    trie->insert("samsan");
    cout<<trie->countStartwiht("sam")<<endl<<trie->countWordEqualto("samsung");
    cout<<endl<<trie->countStartwiht("i")<<endl;
    trie->erase("samsung");
    cout<<trie->countStartwiht("sam")<<endl<<trie->countWordEqualto("samsung");
    cout<<endl<<trie->countStartwiht("moto");
    cout<<endl<<trie->countStartwiht("vivo");
    trie->erase("vivo");
    cout<<endl<<trie->countStartwiht("vivo");
    return 0;
}