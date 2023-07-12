
//algo
/*
use kahn algo to do topological sort and count the number of elements you got in your topoplogical sort if they are equal to the total number of nodes
present in the graph then it means that it is a valid topological sort and there is no cycle present in the graphhh 
but if it is not then graph must have an cycle for suree

*/


#include<bits/stdc++.h>
using namespace std;


#include<unordered_map>
#include<list> 
#include<queue>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
      //create adjacency list
    unordered_map<int ,list<int>> adj;
    for(int i=0 ;i< edges.size() ;i++){
        int u=edges[i].first -1;
        int v=edges[i].second-1;
        
        adj[u].push_back(v);
    }
    
    //find all indegrees 
    vector<int> indegree(n);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        } 
    }
    //0 indegree wallo ko push kardoo  this will handel different components
    queue<int> q;
    for(int i=0 ;i< n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    //do bfs
    int cnt=0;
    
    while(!q.empty()){
        int front =q.front();
        q.pop();
        
        //ans store
        cnt++;
        
        //neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    if(cnt==n){
        return false;
    }
    else
        return true;       //invalid topological sort matlab cycle present haaii
}






int main(){
    
    return 0;
}