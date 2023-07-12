//QUESTION
/*
You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.
For Example :

The MST (Minimum Spanning Tree) for the above graph is:

Input Format :
The first line of input contains an integer 'T' representing the number of the test case. Then the test cases are as follows.

The first line of each test case argument given is an integer ‘N’ representing the number of nodes in the graph.

The second line of each test case contains a given integer ‘M’ representing the number of edges. 

The next ‘M’ lines in each test case contain a matrix ‘E’ of size M x 2 which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1].
Output Format :
For each test case, print the minimum spanning tree in the form of edges and their weights which are included in the MST.
Note :
You do not need to print anything; It has already been taken care of. 
Constraints :
1 ≤ T ≤ 5
2 <= N <= 100
1 <= M <= min(1000, N(N - 1) / 2)
1 <= E[i][0], E[i][1] <= N


Time Limit: 1 sec
Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5
Explanation Of Input 1 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) with weight 3 and (2,5) with weight 5.
Sample Input 2 :
1
5 15
1 2 21
1 4 16
2 1 12
2 3 13
2 4 18
2 5 15
3 2 13
3 5 17
4 1 16
4 2 18
4 5 19
5 1 18
5 2 15
5 3 17
5 4 19
Sample Output 2 :
1 2 12
1 4 16
2 3 13
2 5 15
Explanation Of Input 2 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 12, (1,4) with weight 16, (2,3) with weight 13 and (2,5) with weight 15.

*/





//SPAANING TREE
/*When you convert a graph into a tree such that such that it contains N nodes and N-1 edges and every node is reachable by anyother node*/

//MINIMUM SPANNING TRE
/*Spanning tree with minimum number of weights on its edges*/

//PRIM'S ALGO
/*
for this we will require 3 data structures for this we will make three arrays   Key  , MST(min spamming tree) ,   Parent 
consider 0 as source node so mark 0 for source and infinity for rest nodes in the Key array 
shuruaat mei MST mei koi haii ni isliyyee sabkoo false mark karddoo
or shuruaat mei humme ni pattaa kiska parent kon hai islye sablo -1 krdiaa

ye sab toh hoggyi taiiyyariiyyaa

Now algo says
pehle key walle data structure mei se minimum find krke laoo provided it should not be present(marked true in mst) in MST
fir jo node miilii usko MST mei present mark karrdoo
fir us node ke liye  uskke sarree neighbours track karlloo fir agar un tak pahuchne ki value kaamm hai us se jo key mei paddii haii toh key walli aray mei update
kardooo or unkee parents bhiii update kardooo

stop when all the mst are true

parent  array gives us the minimum spaanning treee
*/


//T.C O(N)2

#include<bits/stdc++.h>
using namespace std;


//SOLUTION
#include <unordered_map> 
#include <list>
#include <limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adj list 
    unordered_map<int ,list<pair<int,int>>> adj;
    for(int i=0 ;i< m;i++){
        int u =g[i].first .first ;
        int v =g[i].first .second;
        
        int weight =g[i].second;
        adj[u].push_back({v, weight});
        adj[v].push_back({u,weight});
    }
    
    vector<int> key(n+1 ,INT_MAX);
    vector<bool> mst(n+1 ,false);                      //ye patta rakheegaa kon kon si node humnee andar lelliii mini spanning tree keeeen 
    vector<int> parent(n+1 , -1);
    
    key[1] =0;
    parent[1] = -1;
    
    for(int i=1 ;i< n;i++){                //is loop ka kaam hai  humne jo algo liikhii hai usko n-1 baar challanaa kyuki n-1 baari mei apni parent array taiiyar ho jaayegii
        int mini=INT_MAX;
        int u;
        //find the minimum walli node
        for(int v=1 ;v<=n;v++){
            if(mst[v] == false  && key[v] < mini){
                u=v;
                mini=key[v];
            }
        }
        //mark min node as true
        mst[u]= true;
        
        //check its adjacent nodes
        for(auto it: adj[u]){
            int v=it.first;
            int weight=it.second;
            if(mst[v] == false && weight<key[v]){
                parent[v]=u;
                key[v]=weight;
            }
        }
    }
    //parent array will be ready here 
    
    vector<pair<pair<int,int>,int>> result;
    
    //one ka parent -1 haii and 0 ke liye koii mapping hi ni haii so we will start front 2
    
    for(int i=2 ;i<= n;i++){
        result.push_back(make_pair(make_pair(parent[i] ,i), key[i] ));
    }
    
    
    return result;
}





// #######################      USING PRIORITY QUEUE        ##############################################
#include <unordered_map> 
#include <list>
#include <limits.h>
#include <queue>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
     //create adj list 
    unordered_map<int ,list<pair<int,int>>> adj;
    for(int i=0 ;i< m;i++){
        int u =g[i].first .first ;
        int v =g[i].first .second;
        
        int weight =g[i].second;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    priority_queue< pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;    //priority queue to store the weight and node ke pair 
    vector<int> key(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    vector<bool> MST(n+1,false);
    key[1]=0;
    pq.push({0,1});
    
    while(!pq.empty())
    {
        int node=pq.top().second;
        MST[node]=true;
        pq.pop();
        
        for(auto &it : adj[node]){
            if(MST[it.first]==false && key[it.first]  > it.second){
                parent[it.first]=node;
                key[it.first]=it.second;
                pq.push({it.second, it.first});
            }
        }
    } 
     vector<pair<pair<int,int>,int>> result;
    
    //one ka parent -1 haii and 0 ke liye koii mapping hi ni haii so we will start front 2
    
    for(int i=2 ;i<= n;i++){
        result.push_back(make_pair(make_pair(parent[i] ,i), key[i] ));
    }
    
    
        
    return result;
}











int main(){
    
    return 0;
}