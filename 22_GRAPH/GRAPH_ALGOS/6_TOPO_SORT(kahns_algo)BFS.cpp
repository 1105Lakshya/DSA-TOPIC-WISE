//ALGO
/*
MAKE A DATA STRUCUTURE TO STORE INDEGREE OF ALL THE NODES 
CREATE A QUEUE 
PUSH THE ELEMENTS THAT HAVE ZERO INDEGREEE
POP THE  FORNT ELEMENT FROM THE QUEUE 
STORE THE ELEMENT IN ANSWER
THEN SINCE WE REMOVED THE ELEMENT THEREFORE ARROWS CONNDECTED TO IT WILL ALSO GET REMOVED SO WE WILL DECREASE THE INDEGREE OF THE NODES THAT WERE CONNECTED TO THE NODE THAT
WE JUST REMOVED 

AGAIN REPEAT THE ABOVE PROCESSS TO GET THE TOPOLOGICAL SORT
    


*/

//SOLUTION


#include<bits/stdc++.h>
using namespace std;

#include<unordered_map>
#include<list> 
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adjacency list
    unordered_map<int ,list<int>> adj;
    for(int i=0 ;i< e ;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }
    
    //find all indegrees 
    vector<int> indegree(v);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        } 
    }
    //0 indegree wallo ko push kardoo  this will handel different components
    queue<int> q;
    for(int i=0 ;i< v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    //do bfs
        vector<int> ans;
    while(!q.empty()){
        int front =q.front();
        q.pop();
        
        //ans store
        ans.push_back(front);
        
        //neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}





int main(){
    
    return 0;
}
