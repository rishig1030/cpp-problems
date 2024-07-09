//heapify algorithm
// basically to place the element int its correct position

#include <iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    // print the heap element 
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

// heapify algorithm in max heap   TC - logN
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    // check the left node
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }

    // check the right node
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    // if changed then swap the value 
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest); // check if largest is still its correct position or not
    }
}

// heapify for min - heap  TC - logN
void heapify2(int arr[],int n,int i){
    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[left]<arr[smallest]){
        smallest = left;
    }

    if(right<-n && arr[right]<arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify2(arr,n,smallest);
    }
    
}


//heap sort

void heapsort(int arr[],int n){
    // time complexity is O(NlogN) ,  N times traversing LogN for heapify 
    int size = n;
    while(size>1){
        // swap 1st element with last element, since 1st element is largest 
        swap(arr[size],arr[1]);
        size--;
        // exclude the last element
        //now place the 1st element to its correct position
        heapify(arr,size,1);
    }

}

int main(){
    int arr[6]= {-1,50,59,60,56,54};
    int n=5;

    // we will only check till n/2 index , since leaf node is already a heap in itself
    // left node till (n/2+1) to (n/2);
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing the hepify array:" <<endl;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    heapsort(arr,5);
    cout<<"printing the heap sorted array:" <<endl;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}