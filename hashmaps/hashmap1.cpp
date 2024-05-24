#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    //creation
    unordered_map<string,int> m;

    //insertion
    pair <string,int> p = make_pair("Rishi",13);
    m.insert(p);
    pair<string,int> p1("smooth",12);
    m.insert(p1);
    m["insert1"]=43;
    m["insert2"]=15;
    m["insert3"]=91;

    //seraching 
    cout<<m["smooth"]<<endl;
    cout<<m.at("Rishi")<<endl;
    cout<<"size "<<m.size()<<endl;
    cout<<m["hello"]<<endl;
    cout<<"size "<<m.size()<<endl;
    
    //check the presence
    cout<<m.count("Rishi")<<" "<<m.count("sorry")<<endl;
    m.erase("insert1");

    //traversing
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //traversing 2
    unordered_map<string,int>:: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}