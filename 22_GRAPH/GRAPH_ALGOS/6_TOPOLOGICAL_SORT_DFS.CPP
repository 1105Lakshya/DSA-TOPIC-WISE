//DAG ---> DIRECTED ACYCLIC GRAPH
//TOPOLOGICAL SORT CAN BE APPLIED ONLY ON DAG
//TOPOLOGICAL SORT --> IT IS THE LINEAR ORDERING OF THE VERTICES SUCH THAT FOR EVERY EDGE  u TO v  u ALWAYS APPEARS v IN THAT ORDEREING

//  ALGO
/*
we will start from the first node and do dfs traversal using the adjacency list and we will maintain a stack  and whenever 
 a call gets return for a particular node
or when all its neighbours are processed befor it return the call we push the element in the stack in the stack since in the end all the node will be processesd 
so it will guarentee that the value of node will come before. In the end we will have our answer stored  in the stack
*/


//question
/*
graph ki v vertices and e edges di huii hogii humme topological sort krnnaa haiii
topological sort manne for every node agar  u to v ek directed connection haii toh answer mei u v se pehle present honna chiiyyyeee
*/


#include<bits/stdc++.h>
using namespace std;



//SOLUTION

void topoSort(int node ,vector<bool> &visited ,stack<int> &s ,unordered_map<int ,list<int>> &adj){
    visited[node] = true;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour])
            topoSort(neighbour ,visited ,s ,adj);
    }
    
    s.push(node);
}



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adjacency list
    unordered_map<int ,list<int>> adj;
    for(int i=0 ;i< e ;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }
    vector<bool>  visited(v);
    stack<int> s;
    vector<int> ans;
    //call dfs topological sort util function for all components
    for(int i=0 ;i< v ;i++){
        if(!visited[i]){
            topoSort(i,visited ,s ,adj);
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}





int main(){

    int v=4;
    int e=5;
    vector<vector<int>> edges(5);
    edges[0]={1,2};
    edges[1]={2,3};
    edges[2]={1,4};
    edges[3]={4,3};
    edges[4]={2,3};

    vector<int> ans;
    ans=topologicalSort(edges, v, e);
    int n=ans.size();
    for(int i=0 ;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}