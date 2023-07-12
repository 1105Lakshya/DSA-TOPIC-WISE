/*
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

Example 1:


Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
Example 2:


Input: n = 1, edges = []
Output: [0]
Example 3:


Input: n = 2, edges = [[1,0]]
Output: [1,1]
*/


//COUNT arrya gives the count of number of nodes of the tree below andd inculduing the current node 
//first did dfs then maintained the count array 
//then for 0th node sum is the sum of count of others from the count array its easy and obvious 
// now inorder to calculate for a child of the cuureent node what i did is current node ka sum minus the current child or uskke neeche ke saree plus bakki jo bachhe unka sum

//baaki utube pe search
#include<bits/stdc++.h>
using namespace std;



class Solution {
    void getCount(int node ,vector<vector<int>>&adj , vector<int> &count  ,vector<bool> &vis )
    {
        vis[node]=true;
        int temp=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                vis[i]=true;
                getCount(i,adj, count, vis);
                temp+=count[i];
            }
        }
    count[node]=temp;
    }

void dfs(int node ,vector<vector<int>>&adj , vector<int> &count  ,vector<bool> &vis , vector<int> &ans ){
    int n=count.size();
    vis[node]=false;
    for(auto i:adj[node]){
        if(vis[i]){
        ans[i]=ans[node]-count[i]+n-count[i];
        dfs(i,adj,count,vis,ans);
        }

    }
}



public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> count(n,0);
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);

        int len=edges.size();
        while(len--){
            adj[edges[len][0]].push_back(edges[len][1]);
            adj[edges[len][1]].push_back(edges[len][0]);
        }
        getCount(0,adj,count,vis);
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=count[i];
        }

        vector<int> ans(n);
        ans[0]=sum;
        dfs(0,adj,count,vis,ans);

        return ans;

    }
};







int main(){
    
    return 0;
}