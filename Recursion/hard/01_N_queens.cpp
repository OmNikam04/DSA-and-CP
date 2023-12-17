#include <bits/stdc++.h>
using namespace std;

//! Approach 1: using 3 loops to check each direction
bool isSafe(int row, int col, vector<string>&boards, int n){
    int temprow = row;
    int tempcol = col;

    // horizontal direction
    while(col>=0){
        if(boards[row][col] == 'Q') return false;
        col--;
    }

    row = temprow;
    col = tempcol;
    // upper diagonal
    while(row>=0 && col>=0){
        if(boards[row][col] == 'Q') return false;
        row--;col--;
    }

    row = temprow;
    col = tempcol;
    // lower diagonal
    while(row<n && col>=0){
        if(boards[row][col] == 'Q') return false;
        row++; col--;
    }

    return true;

}




void solve(int col, vector<string>&board, vector<vector<string>>& ans, int n){

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            // backtracking step
            board[row][col] = '.';
        }
    }
}


//! Approach 2: Using hashing to keep track of placed queens
void solve2(int col, vector<string>&board, vector<vector<string>>& ans, int n, vector<int>& leftrow, vector<int>& upperdigonal, vector<int>& lowerdiagonal){
    if(col == n){
        ans.push_back(board);
        return;
    }
    

    for(int row = 0; row<n; row++){
        if(leftrow[row] == 0 && upperdigonal[n-1 + col - row] == 0 && lowerdiagonal[row+col] == 0)
        {
            // hash all 3 arrays
            leftrow[row] = 1;
            upperdigonal[n-1 + col - row] = 1;
            lowerdiagonal[row+col] = 1;

            board[row][col] = 'Q';
            solve2(col+1, board, ans, n, leftrow, upperdigonal, lowerdiagonal);
            board[row][col] = '.';

            // undo the hashing 
            leftrow[row] = 0;
            upperdigonal[n-1 + col - row] = 0;
            lowerdiagonal[row+col] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');


    for(int i = 0; i<n; i++){
        board[i] = s;
    }
    
    //! Approach 2
    vector<int>leftrow(n);
    vector<int>upperdiagonal(2*n-1, 0);// (n-1) + (col - row);
    vector<int>lowerdiagonal(2*n-1, 0);// row+col
    // solve(0, board, ans, n);
    solve2(0, board, ans, n, leftrow, upperdiagonal, lowerdiagonal);
    return ans;

}

int main()
{
    int n;
    cin >> n;    

    vector<vector<string>> ans = solveNQueens(n);

    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<endl;
        }cout<<endl;
    }

    return 0;
}