#include<bits/stdc++.h>
using namespace std;
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
class Solution {
    public :
    void solveSudoku(vector<vector<char>> & board){
        solve(board);
    }
    private:
    bool solve(vector<vector<char>>&board){
        for(int i = 0; i< 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                for(char c = '1'; c <= '9'; c++){
                        if(isValid(board,i,j,c) == true){
                            board[i][j] = c;
                            if(solve(board) == true)
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>&board,int row, int col,char ch){
        for(int i = 0; i< 9; i++){
            if(board[row][i] == ch)return false;
            if(board[i][col] == ch)return false;
            int r = 3 * (row/3) + i/3;
            int c = 3 * (col / 3) + i%3;
            if(board[r][c] == ch)return false;
        }
        return true;
    }
    public:
    void print(vector<vector<char>> & board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<board[i][j]<<" | ";
            }cout<<"\n-----------------------------------";
            printf("\n");
        }
    }
};
int main(){
    vector<vector<char>>board(9,vector<char>(9));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
           cin>>board[i][j];
        }
    }
    Solution obj;
    obj.solveSudoku(board);
    obj.print(board);
    return 0;
}