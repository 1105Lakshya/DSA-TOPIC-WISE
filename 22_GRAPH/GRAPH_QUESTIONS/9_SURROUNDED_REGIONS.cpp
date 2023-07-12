/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, int j,int m,int n ,vector<vector<char>>& board){
        //for dfs we will check weather the neighbour lies in our range or not 
        //i.e the matrix other than borders 
        if(i+1<m-1 && board[i+1][j]=='O'){
            board[i+1][j]='D';
            dfs(i+1 ,j,m,n,board);
        }
        if(i-1>0 && board[i-1][j]=='O'){
            board[i-1][j]='D';
            dfs(i-1 ,j,m,n,board);
        }
        if(j+1<n-1 && board[i][j+1]=='O'){
            board[i][j+1]='D';
            dfs(i ,j+1,m,n,board);
        }
        if(j-1>0 && board[i][j-1]=='O'){
            board[i][j-1]='D';
            dfs(i ,j-1,m,n,board);
        }
    }
    
    
public:
    void solve(vector<vector<char>>& board) {
    int m=board.size();      //number of rows 
    int n=board[0].size();   //number of columns
        
        //iterating the first row 
    for(int i=1 ;i< n-1;i++){
        if(board[0][i]=='O'){
            //if found moving a step inside
            if(board[1][i]=='O'){
            //if here also "O " present then marking this as "D" and doing dfs to find other "O" who will be stopped by this "O" from changing to "X" and so on
            board[1][i]='D';
            dfs(1,i,m,n,board);
            }
        }
    }
        
        //iterating the first column
    for(int i=1 ;i< m-1;i++){
            //if found moving a step inside
        if(board[i][0]=='O'){
            if(board[i][1]=='O'){
            board[i][1]='D';
            dfs(i,1,m,n,board);
                }
        }
    }
        // iterating the last column
        for(int i=1 ;i< m-1;i++){
        if(board[i][n-1]=='O'){
            //if found moving a step inside
            if(board[i][n-2]=='O'){
            board[i][n-2]='D';                
            dfs(i,n-2,m,n,board);
            }
        }
    }
        
        //iterating the last row
        for(int i=1 ;i< n-1;i++){
        if(board[m-1][i]=='O'){
            if(board[m-2][i]=='O'){
            //if found moving a step inside
            board[m-2][i]='D';
            dfs(m-2,i,m,n,board);
            }
        }
    }

        //at this point we have marked all the "O" that were not suppose to change to "D"
        //remaining "O" will be changed to "X"
        for(int i=1 ;i< m-1 ;i++){
            for(int j=1 ;j< n-1;j++){
                if(board[i][j]=='X'){
                    continue;
                }
                else if(board[i][j]=='D'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};



int main(){
    
    return 0;
}