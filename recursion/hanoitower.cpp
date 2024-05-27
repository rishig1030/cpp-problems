#include <iostream>
using namespace std;

void hanoi(int N,char from,char aux,char to){
    if(N==0) return ;

    hanoi(N-1,from,to,aux);
    cout<<"Move Disk "<<N<<" from "<<from<<" to "<<to<<endl;
    hanoi(N-1,aux,from,to);
}

int main(){
    int N;
    cin>>N;
    hanoi(N,'A','B','C');
    return 0;
}
