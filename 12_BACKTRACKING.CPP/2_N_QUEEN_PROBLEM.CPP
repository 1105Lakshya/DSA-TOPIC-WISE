/*
The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.
Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.
Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 
*/

#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int>temp;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row ,int col , vector<vector<int>>& board , int n){
    int x=row;
    int y=col;
//check  for same roww  sirf left mei hi check kreeengee kyukiii hum left to right fill kr re hai
    while(0<=y--){
        if(board[x][y]==1)
            return false;
    }
    
    x=row;
    y=col;
    //check for diagonal 
    while(x>=0 && y>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }
    x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1)
            return false;
        x++;
        y--;
        
    }
        return true;
}


void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board ,int n )
{
    //basecase
    if(col==n)   // agar saree column bhar gyye tohh answer mei store karra diyya
    {
       addSolution(ans ,board ,n);
        return ;
    } 
    
    //solve one case and rest leave it on recursion
    for(int row=0 ;row<n;row++){
        if(isSafe(row , col , board ,n )){
            //is placing queen is safe
            board[row][col]=1;
            solve(col+1 ,ans ,board ,n);
            board[row][col]=0;
        }
    }
    
}


vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    
    solve(0,ans,board ,n);
    
    return ans;
	
}



int main(){
    
    return 0;
}


