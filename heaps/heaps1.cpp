#include<iostream>
using namespace std;

//implementing heap using array
//max heap
class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }
    
    void insert(int val){
        size++;
        int index = size;
        arr[index]=val;

        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }


    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
// time complexity is O(h), O(logN)
//we compare along the height of the tree

int main(){
    
    heap h;
    h.insert(12);
    h.insert(891);
    h.insert(122);
    h.insert(892);
    h.insert(162);
    h.insert(23);
    h.insert(65);
    h.insert(89);
    h.insert(15);
    h.insert(9);
    h.insert(3);
    h.insert(2);
    h.print();

    return 0;
}