/*

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
Accepted
125.2K
Submissions
279.6K
Acceptance Rate
44.8%

*/


/*
First we did bfs traversal and marked all the components with a common parent and then stored the size of component and the parent in a map

then we did another traversal of grid and if there is a zero we checked all its possible 4 sides if it was visited we put their parent in a set 
as a 0 can have have same component to its left and bottom and also top and right so to avoid that we ensured that the parents we got are unique 
then we added their sum and returned the max ans
*/


class Solution {
public:
    vector<int> dx{0,0,1,-1};
    vector<int> dy{1,-1,0,0};
    unordered_map<int,int> sizeofcompo;


    void makeParent(int row,int col ,vector<vector<int>> &grid , vector<int> &parent){
        int n=grid.size();
        int num=(row*n)+col;


        queue<pair<int,int>> q;
        q.push({row,col});

        grid[row][col]=-1;
        int size=0;


        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int mp=(p.first*n)+p.second;
            size++;

            parent[mp]=num;

            int i=p.first;
            int j=p.second;

            for(int k=0 ;k< 4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];

if(newi<n && newi>=0 && newj<n && newj>=0 && grid[newi][newj]==1 ){
    grid[newi][newj]=-1;
    q.push({newi,newj});

}
            }

        }


sizeofcompo[num]=size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<int> parent(n*n,-1);


        for(int i=0 ;i< n;i++){
            for(int j=0 ;j< n;j++){
                if(grid[i][j]==1){
                    makeParent(i,j,grid, parent);
                }
            }
        }




int ans=0;
        for(int i=0 ;i< n;i++){
            for(int j=0 ;j< n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;
                    for(int k=0 ;k<4;k++){
                        int newi=i+dx[k];
                        int newj=j+dy[k];
                        if(newi<n && newi>=0 && newj<n && newj>=0 && grid[newi][newj]==-1){
                            st.insert(parent[newi*n+newj]);
                        }
                    }
                    int tempans=0;
                    for(auto prnt: st){
                        tempans+=sizeofcompo[prnt];
                    }

                    ans=max(ans,tempans);
                }
            }
        }

if(ans==0){
    for(auto i:sizeofcompo){
        ans=max(ans,i.second);

    }
    if(ans==n*n)return ans;
}

        return ans+1;
    }
};


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}