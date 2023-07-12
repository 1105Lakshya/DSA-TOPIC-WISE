/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
*/

//do the question shortest and longest ccycyle in a graph  

//linear graph are always bipartitie 
//cyclic graph having number of nodes in the cycle even is also bipartitie 
//odd cyclic graph are no bipartitieeeeeeeeeeeeeeeee


#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;

    bool solve(int node ,vector<vector<int>> &graph, vector<int> &count){
        count[node]=1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
                int curr=q.front();
                q.pop();
                
                for(auto neigh:graph[curr]){
                    if(count[neigh]!=-1){
                        if(count[neigh]==count[curr]){
                            return false;
                        }
                    }
                    else{
                        count[neigh]=count[curr]+1;
                        q.push(neigh);
                    }
                }
        }
return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int> count(n,-1);
        for(int i=0;i<n;i++){
            if(count[i]==-1 ){
                bool ans=solve(i,graph,count);
                if(!ans)return ans;
            }
        }

        return true;
    }
};



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}