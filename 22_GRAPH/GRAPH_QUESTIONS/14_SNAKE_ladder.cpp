/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.
*/
#include<bits/stdc++.h>
using namespace std;



class Solution {

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if(board[0][0]!=-1 ){
            return -1;
        }

        int n=board[0].size();
        int flag=n&1;
        int des=n*n;
        vector<bool> vis(des+1,false); 
        int steps=1;
        queue<int> q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                for(int i=1;i<=6;i++){

                    int num=curr+i;
                    if(num==des)return steps;
                    int row=num/n;
                    if(num%n){
                        row=n-row-1;
                    }
                    else{
                        row=n-row;
                    }
                    int col=num%n;
                    if(!flag){

                    
                    if(row&1 ){
                        if(col){
                            col-=1;
                        }
                        else{
                            col=n-1;
                        }
                    }
                    else{
                        if(col){
                            col=n-col;
                        }
                    }
                    }
                    else{
                     if(row&1 ){
                        if(col){
                            col=n-col;
                        }
                    }
                    else{
                     if(col){
                            col-=1;
                        }
                        else{
                            col=n-1;
                        }   
                    }   
                    }

                    // cout<<num<<" "<<row<<" "<<col<<"    ";

                    if(board[row][col]!=-1){
                        if(board[row][col]==des){
                            return steps  ;
                        }
                        else  if(!vis[board[row][col]]){
                            vis[board[row][col]]=true;
                            q.push(board[row][col]);
                        }
                    }
                    else{
                        if(!vis[num]){
                            vis[num]=true;
                        q.push(num);
                        }
                    }   
                }
            }

            steps++;
        }
    return -1;
    }
};

int main(){
    
    return 0;
}