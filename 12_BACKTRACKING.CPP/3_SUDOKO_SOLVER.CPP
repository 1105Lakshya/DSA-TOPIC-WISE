/*
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle.
The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. 
Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.


*/

//TIME COMPLEXITY = 9RAISE TO THE POWER m WHERE m IS NUMBER OF EMPTY CELLLSS
/*

bool isSafe(int row ,int col, vector<vector<int>> &board , int val){
    for(int i=0 ; i< board.size(); i++ ){
        //row check 
        if(board[row][i]==val)
            return false;
        
        //column chekc
        if(board[i][col]==val)
            return false;
        
        //3X3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
            return false;
    }
    return true;
}


bool solve(vector<vector<int>> &board){
    int n =board[0].size();                    // 9 direct bhi le sakta tha
    for(int row=0;row<n ;row++){
        for(int col=0;col<n;col++){
            
            //check if cell is empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row ,col ,board, val)){
                    board[row][col]=val;
                    //recursive call
                    bool aggeSolutionPossible= solve(board);
                        if(aggeSolutionPossible)
                            return true;
                        else{
                            //backtraack
                            board[row][col]=0;
                        }
                    }
                }
            return false;           //agar saari values try krne ke bawjood bhi safe ni hai toh false reutrn krdooo       
            }
        }
    }
    return true;
}





void solveSudoku(vector<vector<int>>& sudoku)
{
//     unordered_map<int,unordered_set<int> > row;    //mapping of row num and elements
//     unordered_map<int,unordered_set<int> > col;
//     //     creating matrix for 3X3 grid
//     unordered_map<pair<int,int> ,unordered_set<int>>  grid;
//     //creating set
//     for(int i=0;i<9 ;i++){
//         for(int j=0 ;j<9 ;j++){
//           row[i].insert(sudoku[i][j]);
//           col[j].insert(sudoku[i][j]);
//           int x=i/3;
//           int y=j/3;//           pair<int,int> p ={x,y};
//           grid[p].insert(sudoku[i][j]);
//         }
//     }
    
    solve(sudoku);
    
    
    
}



*/