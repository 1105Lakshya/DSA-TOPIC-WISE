#include<bits/stdc++.h>
using namespace std;




//ALGO TO FIND MINIMUM DISTANCE IN NEGATIVE WEIGHTED GRAPH
//BAS N-1 TIMES EK FORMULA SARII EDGE KE LIYE APPLY KRNNAAA
#include <limits> 
#include <algorithm> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
vector<int> dist(n+1 ,1e9);
dist[src]=0;
for(int i=1 ;i<=n ;i++){   //n-1 barri formula
    //traverse on edge list
    for(int j=0 ;j< m ;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
        
        if(dist[u] !=1e9 &&((dist[u]+wt )<dist[v])){
            dist[v]=dist[u]+wt;
        }
    }
}
    //check for negative weight cycle
    bool flag = 0;
     for(int j=0 ;j< m ;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
        
        if(dist[u] !=1e9 &&((dist[u]+wt )<dist[v])){
            flag=1;
        }
    }
    if(flag==0){
        return dist[dest];
    }
    return -1;
}


int main(){
    
    return 0;
}