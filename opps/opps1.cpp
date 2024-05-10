#include <iostream>
using namespace std;

//for pratice only
class doing {
    public:
    int a;
    void operator+ (doing &a){
        int v1=this->a;
        int v2=a.a;
        cout<<v2-v1<<endl;
    }
};
int main(){
    doing obj1,obj2;
    obj1.a=7;
    obj2.a=4;
    obj2 + obj1 ;
}