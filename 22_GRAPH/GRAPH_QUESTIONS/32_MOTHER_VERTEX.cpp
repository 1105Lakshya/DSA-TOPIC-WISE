/*

Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/


#include<bits/stdc++.h>
using namespace std;


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    
    int ans=-1;
    
    void dfs(int node, vector<bool>&vis,vector<int>adj[]){
        vis[node]=true;
        
        
        
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,vis,adj);
            }
        }
        ans=node;
    }
    
    int get_count(int node, vector<bool> &vis,vector<int> adj[]){
        int count=1;
        
        vis[node]=false;
        
        for(auto neigh:adj[node]){
            if(vis[neigh]){
                count+=get_count(neigh,vis,adj);
            }
        }
        return count;
    }
    
    
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int n, vector<int>adj[])
	{
	   vector<bool> vis(n,false);
	   
	   for(int i=0;i<n;i++){
	       if(!vis[i]){
	           dfs(i,vis,adj);
	       }
	   }
	   //for(auto num:vis){
	   //    cout<<num<<" ";
	   //}
	   int start= ans;
	   
	   if(get_count(start,vis,adj)<n)return -1;
	   
	   
	   return ans;
	   
	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}