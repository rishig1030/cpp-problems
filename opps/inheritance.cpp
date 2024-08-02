#include<iostream>
using namespace std;

class A{
    private:
    int x = 5;
    protected:
    int y = 6;
    public:
    int z = 7;
};

class B : public A{
    // x is not accessible
    // y is protected
    // z is public
};

class C : protected A{
    // x is not accessible
    // y is protected
    // z is protected
};

class D : private A{
    // x is not accessible
    // y is private
    // z is private
};

// 1. aboves are the example of single inheritance

// 2. multiple inheritance

class E : public A,public B,public C{
    public:
    E(){
        cout<<"this is the example of multiple inheritance";
    }
};


// 3. multi-level inheritace 
// above example is the type of multi-level inheritance , because E is derived class from B which is derived from A

// 4. hierarchical inheritance
// one parent class and multiple child class
// A is the parent class (base-class) and B C D are the sub-class

// 5. hybrid inheritance
// combining more than one type of inheritance

int main(){
    D* d = new D();
    
    return 0;
}