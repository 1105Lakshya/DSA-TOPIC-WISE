/*
There exists an undirected and unrooted tree with n nodes indexed from 0 to n - 1. You are given an integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an array coins of size n where coins[i] can be either 0 or 1, where 1 indicates the presence of a coin in the vertex i.

Initially, you choose to start at any vertex in the tree. Then, you can perform the following operations any number of times: 

Collect all the coins that are at a distance of at most 2 from the current vertex, or
Move to any adjacent vertex in the tree.
Find the minimum number of edges you need to go through to collect all the coins and go back to the initial vertex.

Note that if you pass an edge several times, you need to count it into the answer several times.

 

Example 1:


Input: coins = [1,0,0,0,0,1], edges = [[0,1],[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: Start at vertex 2, collect the coin at vertex 0, move to vertex 3, collect the coin at vertex 5 then move back to vertex 2.
Example 2:


Input: coins = [0,0,0,1,1,0,0,1], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[5,6],[5,7]]
Output: 2
Explanation: Start at vertex 0, collect the coins at vertices 4 and 3, move to vertex 2,  collect the coin at vertex 7, then move back to vertex 0.
 

Constraints:

n == coins.length
1 <= n <= 3 * 104
0 <= coins[i] <= 1
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
*/

// All leaves that do not have a coin are redundant and can be deleted from the tree.
// Remove the leaves that do not have coins on them, so that the resulting tree will have a coin on every leaf.
// In the remaining tree, remove each leaf node and its parent from the tree. The remaining nodes in the tree are the ones that must be visited. Hence, the answer is equal to (# remaining nodes -1) * 2

//shuruat mei sarii leafs ko push kardiaaa fir unko remove kardia tree mei se fir agar remove karne ke baad koi leaf banii or usmei coin ni pada tha toh usko phir se queue mei push kardiaa

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {

        int n=coins.size();
        vector<set<int>> g(n);
        
        for(auto& e:edges)  g[e[0]].insert(e[1]),g[e[1]].insert(e[0]);
        queue<int> leaves;

        int totalEdges=edges.size()*2,deleted=0;
        // let's add the leaves which don't have any coins!
        
        for(int i=0;i<n;i++)    if(g[i].size()==1 && coins[i]==0)  leaves.push(i);

        while(leaves.size()){   // keep removing leaves with no coins!
            int leaf=leaves.front();
            leaves.pop();
            if(g[leaf].empty()) continue;// this not has no parent! [last node of the tree]

            int p=*g[leaf].begin();     // parent
            
            g[p].erase(leaf),deleted++;
            g[leaf].erase(p),deleted++;        // clear the entire mappings for it as it's useless now!
            
            if(g[p].size()==1 && coins[p]==0)   leaves.push(p); // if this now becomes a leaf with no coins. 
        }
        // now the leaves would be having the coin! 
        for(int i=0;i<n;i++)    if(g[i].size()==1)  leaves.push(i);
        // now I need to remove the leaf nodes and their immediate parents
        int step=2; //1 for parent and 1 for children
        while(step--){
            int sz=leaves.size();
            while(sz--){
                int leaf=leaves.front();
                leaves.pop();
                if(!g[leaf].size()) continue;// this not has no parent! [last node of the tree]
                
                int p=*g[leaf].begin();     // only parent would be there in leaf!
                
                g[p].erase(leaf),deleted++;
                g[leaf].erase(p),deleted++;

                if(g[p].size()==1)  leaves.push(p);
            
            }
        }
        
        return totalEdges-deleted;
    }
};



int main(){
    
    return 0;
}