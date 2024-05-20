//implement circular queue using array

#include<iostream>
using namespace std;

class Queue{
    public:
    
    int rare;
    int front;
    int *arr;
    int size;

    Queue(int n){
        this->size=n;
        arr[n];
        front=-1;
        rare=-1;
    }

    void enqueue(int d){
        if((front == 0 && rare==size-1) || (rare == (front-1)%(size-1))){
            cout<<"Queue is Full";
        }
        else if(front == -1){
            front= rare=0;
            arr[rare]=d;
        }
        else if(rare == size -1 && front !=0){
            rare=0;
            arr[rare]=d;
        }
        else{
            rare++;
            arr[rare]=d;
        }
    }

    void dequeue(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front ==0 && rare==0){
            rare=-1;
            front= -1;
        }
        else if(front== size -1){
            front=0;
        }

        else{
            front++;
        }
    }
    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        cout << "Queue elements: ";
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rare + 1) % size);
        cout << endl;
    }
};

int main(){
    Queue queue(5); // Change the size as needed
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();
   

    queue.dequeue();
    queue.dequeue();

    queue.display();

    queue.enqueue(6);
    queue.enqueue(7);

    

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    return 0;
}