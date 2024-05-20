//implement queue using array

#include <iostream>
using namespace std;

class Queue {
    public:
    int front;
    int rare;
    int *arr;
    int size;

    public:
    Queue(int size){
        this->size=size;
        arr = new int[size];
        rare=0;
        front=0; 
    }

    //push an element 
    void push(int data){
        if(rare<size){
            arr[rare]=data;
            rare++;
        }
        else{
            cout<<"overflow"<<endl;
        }
    }
    //pop the element 
    void pop(){
        if(front == rare){
            cout<<"queue is empty "<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rare){
                front=0;
                rare=0;
            }
        }
    }
    // check if empty
    bool isempty(){
        if(front == rare){
            return true;
        }
        else return false;
    }
    //print the first element
    int Front(){
        if(front!=rare)
        return arr[front];
        else return -1;
    }
};

int main(){
    Queue q(5);
    q.push(12);
    q.push(23);
    q.push(2);
    q.push(32);
    q.push(32);
    q.push(32);

    q.pop();
    cout<<q.Front()<<endl;
    q.pop();
    cout<<q.Front()<<endl;

    if(q.isempty()) cout<<"empty"<<endl;
    else cout<<"not empty"<<endl;

    return 0;
}