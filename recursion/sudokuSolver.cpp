// solve the sudoku
#include<iostream>
#include<vector>
using namespace std;

bool check(char num,int n, vector<vector<char>> &v,int row,int col){
    for(int i=0;i<n;i++){
        if(v[i][col] == num || v[row][i] == num) return false;
    }

    row = row - row%3;
    col = col - col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v[row+i][col+j] == num) return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(v[i][j] == '.'){
                for(char c='1';c<='9';c++){
                    if(check(c,v.size(),v,i,j)){
                        v[i][j] = c;
                        if(solve(v)) return true;
                        else{
                            v[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n = 9;
    vector<vector<char>> v(n,vector<char> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    solve(v);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
/*
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
*/