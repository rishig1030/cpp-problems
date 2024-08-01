#include<iostream>
using namespace std;

class A{
    private:
    int x;
    protected:
    int y;
    public:
    int z;
};

class B : public A{

};

class C : protected A{

};

class D : private A{

};

int main(){

    return 0;
}