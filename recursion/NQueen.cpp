// N queens problem , place N queen in NxN matrix such that each rows and columns have one Queen and none of the queen should attack each other
#include<iostream>
#include<vector>

using namespace std;

bool check(int row,int col,vector<string> &board){
    // we will only check the left side of the rows and column becuase the right side is not fixed
    int row1 = row;
    int col1 = col;
    // left side row
    while(col1>=0){
        if(board[row][col1] == 'Q') return false;
        col1--; 
    }
    col1 = col;
    // upper diagonal
    while(col1>=0 && row1>=0){
        if(board[row1][col1] == 'Q') return false;
        row1--; col1--;
    }
    col1 = col;
    row1 = row;
    // lower diagonal
    while(col1>=0 && row1<board.size()){
        if(board[row1][col1] == 'Q') return false;
        row1++;
        col1--;
    }
    return true;
}

void solve(int col,vector<string> &board,int n,vector<vector<string>> &ans){
    if(col == n){
        ans.push_back(board);
        return ;
    }
    for(int i=0;i<n;i++){
        if(check(i,col,board)) {
            board[i][col] = 'Q';
            solve(col+1,board,n,ans);
            board[i][col] = '_';
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<string>> ans; 
    vector<string> board(n);
    string s(n,'_');
    for(int i=0;i<n;i++){
        board[i] = s;
    }   
    solve(0,board,n,ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}