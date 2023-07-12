/*
You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].
Example 2:

Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
 

Constraints:

1 <= n <= 104
0 <= paths.length <= 2 * 104
paths[i].length == 2
1 <= xi, yi <= n
xi != yi
Every garden has at most 3 paths coming into or leaving it.*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
   bool color(int node,int prevcolor,int parent,vector<vector<int>>&adj,vector<int> &ans){
       if(ans[node]!=-1){
           if(ans[node]== prevcolor){
               return false;
           }
           else{
               return true;
           }
       }


       for(int i=1; i<=4;i++){
           if(i!=prevcolor){
           ans[node]=i;
           bool iscolored=true;
           for(auto j:adj[node]){
               if(j!=parent)
               iscolored=iscolored && color(j,i,node,adj,ans);
           }    
           
           if(iscolored){
               return true;
           }
           }
       }

       return false;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);

        for(auto i:paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int> ans(n,-1);
        for(int i=0 ;i< n;i++){
        color(i,-1,-1,adj,ans);
        }

        return ans;
    }
};



int main(){
    
    return 0;
}