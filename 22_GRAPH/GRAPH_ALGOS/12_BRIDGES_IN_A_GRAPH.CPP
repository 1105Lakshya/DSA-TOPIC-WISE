

//QUESTION
/*
Given a undirected unweighted graph of v verices and e edges you need to find the bridges in the graph 
bridge is an edges jisko hattaanne parr graph components mei break hojjayyyyeee
*/



// ALGO
/*
SEE THE PHOTOS OR YOUR REGGISTER

*/







#include<bits/stdc++.h>
using namespace std;





//TIME COMPLEXITY O(N+E) i.e. of dfs algo


#include <unordered_map>
#include<algorithm>
#include<list>
void dfs(int node ,int parent ,int &timer , vector<int> &disc ,vector<int> &low ,vector<vector<int>> &result,unordered_map<int,list<int>> &adj , vector<bool> &visited){
    visited[node]=true;
    disc[node]=low[node]=timer++;
    
    for(auto nbr: adj[node]){
        if(nbr==parent)
            continue;
        if(!visited[nbr]){
            dfs(nbr,node, timer ,disc ,low ,result,adj ,visited);
            //jab call se waapas attee hai toh low ko update krttee haiii kyuki ho sakta hai ki neeeche walla update hua ho toh current node tak pahochne ka ek or tarika ho sakta hai isliyee update karte haiii
            low[node]=min(low[node],low[nbr]);
            //check krte hai kya particular node bridge hai ya nahhii
            if(low[nbr]>disc[node]){     //bridge present
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
                
            }
        }
        else{                   //this is the case when back edge forms
            low[node]=min(low[node],disc[nbr]);
        }
    }
    
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e ;i++){
        int u =edges[i][0];
        int v =edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer =0 ;
    vector<int> disc(v,-1);       //stores the time of discovery
    vector<int> low(v,-1);        //stores the lowest possible time to reach that node
    int parent=-1;
    vector<bool> visited(v,false);
    
    vector<vector<int>> result ;
    //dfs
    for(int i=0 ;i<v ;i++){
        if(!visited[i]){
            dfs(i,parent,timer,disc,low,result,adj ,visited);
        }
    }
    return result;
}






class Solution {
    vector<int> arrival;
    vector<int> lowesttime;
    vector<vector<int>> critical;
    vector<vector<int>> adj;
public:


    void solve(int node, int parent,int time){

        arrival[node]=time;
        lowesttime[node]=time;

        for(auto next:adj[node]){
            //first i need to get the lowest possible time so made a call first 
            if(arrival[next]==-1){
                solve(next,node,time+1);
            }    
            


            //if next not equal to parent we updated the minimum timee
            if(next!=parent){
                lowesttime[node]=min(lowesttime[node],lowesttime[next]);
            }

//if lowestpossible time of next node is less than my arrival time it means it can be reached via a node other than me and since it is less it will go back to somwhere and reach me so this is not critical component other than that it is criticall 
            if(lowesttime[next]>arrival[node]){
                critical.push_back({node,next});
            }
            
        }
    }




    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(n==2){
            return connections;
        }


        arrival.resize(n,-1);
        lowesttime.resize(n,INT_MAX);
        adj.resize(n);

        for(auto connection:connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }


        solve(0,-1,1);


        return critical;

    }
};
















int main(){
    
    return 0;
}