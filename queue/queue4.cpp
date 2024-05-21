//implement doubly ended queue using array

#include <iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int front;
    int rare;
    int size;

    //constructor 
    Deque(int size){
        this->size=size;
        arr[size];
        front = -1;
        rare = -1;
    }

    //push_front
    void push_front(int element){
        if(isfull()){
            cout<<"Queue is Full"<<endl;
        }
        
        else if(front==-1){
            front =0;
            rare =0;
            arr[front] =element;
        }
        else if(front == 0){
            front = size -1;
            arr[front]=element;
        }
        else{
            front--;
            arr[front]=element;
        }
    }

    //push_back
    void push_back(int element){
        if(isfull()){
            cout<<"Queue is full "<<endl;
        }
        else if(front == -1){
            front = 0;
            rare = 0;
            arr[rare]= element;
        }
        else if(rare== size-1){
            rare=0;
            arr[rare] = element;
        }
        else{
            rare++;
            arr[rare]=element;
        }
    }

    //pop_back

    void pop_back(){
        if(front != -1){
            if(rare == 0){
                cout<<"poped elemnet"<<arr[rare]<<endl;
                rare= size-1;
            }
            else if(front == rare){
                cout<<"poped elemnet"<<arr[rare]<<endl;
                front = rare = -1;
            }
            else{
                cout<<"poped elemnet"<<arr[rare]<<endl;
                rare--;
            }
            
        }
        else{
            cout<<"Queue is empty"<<endl;
        }
    }

    //pop front
    void pop_front(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            if(front == size-1){
                cout<<"poped elemnet"<<arr[front]<<endl;
                front=0;
            }
            else if(front == rare){
                cout<<"poped elemnet"<<arr[rare]<<endl;
                front = rare = -1;
            }
            else{
                cout<<"poped elemnet"<<arr[front]<<endl;
                front++;
            }
        }
    }

    int getfront(){
        if(front != -1){
            return arr[front];
        }
        else return -1;
    }

    int getrare(){
        if(front!=-1){
            return arr[rare];
        }
        else return front;
    }

    bool isempty(){
        if(front == -1) return true;
        else return false;
    }

    bool isfull(){
        if((front == 0 && rare == size-1) || ((rare == front -1) && front!=0)) return true;
        else return false;
    }
};

int main(){
    Deque deque(5);

    if(deque.isempty()){
        cout<<"empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    
    deque.push_front(1);
    deque.push_back(3);
    cout<<deque.getfront()<<endl;
    cout<<deque.getrare()<<endl;
    if(deque.isfull()){
        cout<<"full"<<endl;
    }
    else{
        cout<<"not full"<<endl;
    }

    deque.push_front(9);
    deque.push_back(7);
    deque.push_back(6);
    cout<<deque.getfront()<<endl;
    cout<<deque.getrare()<<endl;

    if(deque.isfull()){
        cout<<"full"<<endl;
    }
    else{
        cout<<"not full"<<endl;
    }

    deque.push_back(6);
    return 0;
}
