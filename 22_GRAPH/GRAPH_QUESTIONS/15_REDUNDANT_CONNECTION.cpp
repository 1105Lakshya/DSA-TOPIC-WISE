/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
*/


//basically hum log union karte gayye or jab hume pata challa ke wo pehle se hi union haiii matlab wo hi redudant connection haiiiiiiiiiiiiiii


//UNION FIND GOOD USE 
#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> rank, parent;

public: 
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0 ;i<=n ;i++){
            parent[i]=i;
        }
    }


    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);

    }


    bool unionByRank(int u ,int v){
        int ulp_u =findParent(u);  //ultimate parent of u
        int ulp_v =findParent(v);   // ultimate parent of v

        if(ulp_u == ulp_v) return true;

        if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        if(rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
        return false;


    }
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjointSet d1(n+1);

        for(int i=0 ;i<n ;i++){
            int n1=edges[i][0];
            int n2=edges[i][1];

            if(d1.unionByRank(n1,n2)){
                return edges[i];
            }
            

        }

        vector<int> ans;
        return ans;
    }
};











int main(){
    
    return 0;
}