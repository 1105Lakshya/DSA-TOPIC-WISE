/*
You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

Each node in the graph belongs to exactly one group.
For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 

Example 1:


Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
Output: 4
Explanation: As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
Example 2:

Input: n = 3, edges = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.
 

Constraints:

1 <= n <= 500
1 <= edges.length <= 104
edges[i].length == 2
1 <= ai, bi <= n
ai != bi
There is at most one edge between any pair of vertices.


*/




#include<bits/stdc++.h>
using namespace std;





class Solution {

    int solve(int node, vector<vector<int>> &adj){
        
        int n=adj.size();
        vector<int> count(n,-1);
        int ans=1;

        count[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
                int curr=q.front();
                q.pop();
                
                for(auto neigh:adj[curr]){
                    //agar visited hai node or uska count same hai as humare current ka iska matlab cycle mei odd number of edges haiii tabhi hoggaa yeeeeeeeeeeee
                    if(count[neigh]!=-1){
                        if(count[neigh]==count[curr]){
                            
                            return INT_MIN;
                        }
                    }
                    else{
                        count[neigh]=count[curr]+1;
                        ans=max(ans,count[neigh]);
                        q.push(neigh);
                    }
                }
        }
return ans;
}


int dfs(int node, vector<vector<int>> &adj,vector<bool> &vis,vector<int> &dis ){
    vis[node]=true;
    int ans=dis[node];
    for(auto neigh:adj[node]){
        if(!vis[neigh]){
            ans=max(ans,dfs(neigh,adj,vis,dis));
        }
    }
    return ans;
}


public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        n++;
        vector<vector<int>> adj(n);

        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dis(n,-1);
//pehle sabke liye bfs call mardiii  or unke liye distance which is basically groups nikal liyye
        for(int i=1;i<n;i++){
            dis[i]=solve(i,adj);
            if(dis[i]==INT_MIN)return -1;
        }
        int ans=0;
        vector<bool> vis(n,false);


//next dfs call marke har compnent ke liye usmmeii se max nikalll liaaaaaaa
        for(int i=1;i<n;i++){
            if(!vis[i]){
                ans+=dfs(i,adj,vis,dis);
            }
        }

        return ans;


    }
};

int main(){
    
    return 0;
}