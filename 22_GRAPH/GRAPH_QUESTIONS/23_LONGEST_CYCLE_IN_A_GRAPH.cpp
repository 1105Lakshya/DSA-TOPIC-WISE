/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

 

Example 1:


Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
Example 2:


Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
 

Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
*/

//tarika number one is that make a visited and a tracker array vis will keep track of who are visited in total tracker will tell who are visited in current dfs call tracker will keep count as welll 



// tarika number do is that reverse the graph bhechoo koi kaise soch sakta hai ye but reverse the node of the graph ab cycle detection normally hojayega jab cycle detection ho toh apne normal walle graph matlab bina reversed walle graph se ulta traverse karlo tumhe length prapt ho jayeegii
#include<bits/stdc++.h>
using namespace std;

class Solution_tarika_1 {
    int dfs(int node,int count, vector<int> &adj , vector<int> &tracker , vector<bool> &vis){
        tracker[node]=count;

        if(adj[node]!=-1 && !vis[adj[node]]){
            if(tracker[adj[node]]!=-1){
                vis[node]=true;
                return count+1-tracker[adj[node]];
            }
            else{
                int ans= dfs(adj[node],count+1,adj,tracker,vis);
                tracker[node]=-1;
                vis[node]=true;
                return ans;
            }
            

        }
        tracker[node]=-1;
        vis[node]=true;

        return -1;
        

    }
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> vis(n,false);
        vector<int> tracker(n,-1);
        int ans=-1;

        for(int i=0 ;i<n;i++){
            if(!vis[i]){
            int temp_ans=dfs(i,1,edges,tracker,vis);
            ans=max(ans,temp_ans);
            }
        }

        return ans;
        

    }
};

int main(){
    
    return 0;
}