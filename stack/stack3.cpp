//implement two stack using an array
#include <iostream>
using namespace std;

//here for two stack the push of element in stack1  will be from -1 to size-1;
//for 2nd stack it will be from n to 1

class twostack{
    public:
    int* arr ;
    int top1;
    int top2;
    int size;

    //constructor
    twostack(int size){
        this->size=size;
        top1=-1;
        top2=size;
        arr= new int[size];
    }

    //implimentation
    void push1(int element){
        if(top2-top1 > 1){   //atleast one place
            top1++;
            arr[top1]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void push2(int element){
        if(top2-top1 > 1){
            top2--;
            arr[top2]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop1(){
        if(top1!=-1){
            top1--;
        }
        else cout<<"stack underflow"<<endl;
    }

    void pop2(){
        if(top2 != size){
            top2++;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    

};

int main(){

    return 0;
}