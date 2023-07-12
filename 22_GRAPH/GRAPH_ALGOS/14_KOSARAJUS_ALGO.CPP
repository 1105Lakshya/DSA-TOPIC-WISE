#include<bits/stdc++.h>
using namespace std;


//algo to count the number of STRONGLY CONNECTED COMPONENTS see register 

// algo
/*
first get topological stack
then transpose 
then do dfs of transpose get ans
*/


#include<bits/stdc++.h>
void dfs(int node ,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int> > &adj){
    vis[node]=true;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,st,adj);
        }
    }
    
    //topo logic
    st.push(node);
}

void revdfs(int node ,unordered_map<int,bool> &vis,unordered_map<int,list<int> > &adj){
    vis[node]=true;
    cout<<node<<" ";
    
    for(auto nbr: adj[node]){
        if(!vis[nbr]){
            revdfs(nbr ,vis,adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
        // adj
    unordered_map<int,list<int> > adj;
    for(int i=0 ;i< edges.size() ;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    
//     topo sort
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=0 ;i< v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    
    //create a transpose graph
    unordered_map<int,list<int>> transpose;
    for(int i=0 ;i< v;i++){
        vis[i]=0;
        for(auto nbr : adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    
    //dfs call using above ordering
    int count =0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++;
            cout<<endl;
            revdfs(top ,vis, transpose);
        }
    }
    return count ;
}




int main(){
    int n=8;
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({1,2});
    edges.push_back({1,5});
    edges.push_back({2,3});
    edges.push_back({3,4});
    edges.push_back({4,2});
    edges.push_back({5,6});
    edges.push_back({6,7});
    edges.push_back({7,0});

    int ans =stronglyConnectedComponents(8,edges);
    cout<<endl;
    cout<<"TOTAL NUMBER OF STRONGLY CONNECTED COMPONENTS"<<ans<<endl;

    return 0;
}