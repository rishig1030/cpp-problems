// runtime polymorphism
// 1. function over-riding

#include<iostream>
using namespace std;

class Animal{
    public:
    string color = "grey";
};

// derived class
class Dog : public Animal{
    public:
    string color = "black";
};


int main(){
    // this can only be used with derived class
    Animal d = Dog();

    cout<<d.color<<endl;  // will get to the parent class 
    return 0;
}