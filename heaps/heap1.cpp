#include<iostream>
using namespace std;

//implementing heap using array
//max heap - min heap
class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }
    // inserting in max heap
    // time complexity is O(logN), comparing every time with its height
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

    // inserting in min heap
    // time complexity is O(logN), comparing every time with its height

    void insertmin(int x){
        size++;
        int index = size;
        arr[index] = x;

        while(index>1){
            int parent = index/2;
            if(arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else return ;
        }
    }

    //print the heap 
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //delete a root from heap
    void deleteAnode(){
        if(size == 0){
            cout<<"heap is empty"<<endl;
            return ;
        }
        //first element = last element 
        arr[1] = arr[size];
        //remove last element
        size--;

        // now take root node to its correct position
        int i= 1;
        while(i<size){
            int leftchild = 2*i;
            int rightchild = 2*i + 1;

            if(arr[i]<arr[leftchild] && leftchild<=size){
                swap(arr[i],arr[leftchild]);
                i= leftchild;
            }
            else if(rightchild<=size && arr[i]<arr[rightchild]){
                swap(arr[i],arr[rightchild]);
                i=rightchild;
            }
            else return ;
        }
    }

    // delete a node
    void deleteANodePractice(){
        // delete a root node;
        arr[1] = arr[size];
        size--;
        int index = 1;
        while(index<size){
            int leftchild = 2*index;
            int rightchild = 2*index + 1;
            if(leftchild<=size && arr[leftchild]>arr[index]){
                swap(arr[leftchild],arr[index]);
                index = leftchild;
            }
            else if(rightchild<=size && arr[rightchild]>arr[index]){
                swap(arr[leftchild],arr[index]);
                index = rightchild;
            }
            else return ;
        }
    }

};
// time complexity is O(h), O(logN)
//we compare along the height of the tree

int main(){
    
    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(49);
    
    h.print();
    h.deleteAnode();
    h.print();

    return 0;
}