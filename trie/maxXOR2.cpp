// given an array of size N , and M queries , each queries consist of 2 element ,
// you need no find the XOR of max XOR of first element(Xi) that is less than 2nd element(Ai) in array 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// time complexity for this approach is O(q*N)
vector<int> maxXOR1(vector<int> arr,vector<pair<int,int>> q){
    vector<int> v;
    for(int i=0;i<q.size();i++){
        int first = q[i].first;
        int second = q[i].second;
        int maxXOR = -1;
        for(int j=0;j<arr.size();j++){
            if(arr[j]<=second){
                maxXOR = max(maxXOR,first^arr[j]);
            }
        }
        v.push_back(maxXOR);
    }
    return v;
}

// using trie
class Node{
    public:
    Node* links[2];

    bool containKey(int bit){
        return links[bit]!=NULL;
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit,Node* node){
        links[bit] = node;
    }
};

class trie{
    public:
    Node* root;

    trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            if(!node->containKey(num>>i & 1)){
                node->put(num>>i & 1,new Node());
            }
            node = node->get(num>>i & 1);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxXOR = 0;
        for(int i=31;i>=0;i--){
            int bit = num>>i & 1;
            if(node->containKey(1-bit)){
                node = node->get(1-bit);
                maxXOR = maxXOR | (1<<i) ;
            }
            else{
                node = node->get(1-bit);
            }
        }
        return maxXOR;
    }
};

vector<int> maxXOR2(vector<int> arr,vector<pair<int,int>> q){
    sort(arr.begin(),arr.end());   //nlonN
    vector<pair<int,pair<int,int>>> oQ; // offline quries, to store , {Ai,{Xi,i}}
    for(int i=0;i<q.size();i++){
        oQ.push_back({q[i].second,{q[i].first,i}});
    } // Q
    sort(oQ.begin(),oQ.end()); // sort the Offline quries int term of Ai , second element of queries
    //QlongQ
    vector<int> ans(q.size(),0);

    int index = 0;
    trie t;

    for(int i=0;i<q.size();i++){ //Q
        int ai = oQ[i].first;
        int xi = oQ[i].second.first;
        int ind = oQ[i].second.second;
        // insert those element in the trie which are lesser than ai
        while(index<arr.size() && arr[i]<=ai){  // + N
            t.insert(xi);
            index++;
        }
        if(index == 0){
            ans[ind] = -1;
        }
        // insert the maxNum to ans array
        else{
            ans[ind] = t.getMax(xi);
        }
    } // O(Q*32+N)
    return ans;
}
// overall time complexity is O(NlogN + Q + QlogQ + Q*32 + N*32)

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    vector<pair<int,int>> q(m);
    for(int i=0;i<m;i++){
        cin>>q[i].first>>q[i].second;
    }

    vector<int> v1;
    v1 = maxXOR1(arr,q);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" "; 
    }cout<<endl;

    v1 = maxXOR2(arr,q);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" "; 
    }cout<<endl;

    return 0;
}