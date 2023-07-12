/*
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].
Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.
For Example :
In the following directed graph has a cycle i.e. B->C->E->D->B.

Note :
1. The cycle must contain at least two nodes.
2. It is guaranteed that the given graph has no self-loops in the graph.
3. The graph may or may not be connected.
4. Nodes are numbered from 1 to N.
5. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
Input Format :
The first line of input contains an integer 'T' representing the number of the test case. Then the test cases are as follows.

The first line of each test case argument given is an integer ‘N’ representing the number of nodes in the graph.

The second line of each test case contains a given integer ‘M’ representing the number of edges. 

The next ‘M’ lines in each test case contain a matrix ‘EDGES’ of size M x 2 which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].
Output Format :
For each test case, print true if a cycle is present in the given directed graph else print false.
Note :
You do not need to print anything; It has already been taken care of. 
Constraints :
1 ≤ T ≤ 5

2 <= N <= 100
1 <= M <= min(100,N(N-1)/2)
1 <= EDGES[i][0], EDGES[i][1] <= N

Where ‘T’ is the number of test cases.

Time Limit: 1 sec
Sample Input 1 :
1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1 :
true
Explanation For Input 1 :
The given graph contains cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.
Sample Input 2 :
2
5
4
1 2
2 3
3 4
4 5
2
1
1 2


*/

//ALGO
/*
we will do dfs traversal we will maintain a visited node and  a dfsvisited node(dfs walli stores for which nodes call have been done ) 
for cycle detection the condition is that visited should be true as well as dfsvisited must be truee for that particular node we cannnot use method of cycle 
detection used in undirected graph because here in directed graph even if a loop is formed that does not mean a cycle because the direction of arrows must be 
so such that the cycle could be possible so we will mark the visited node true and dfsvisited true for every node we are cheking and while returning from the call
we will mark dfsvisited for that paritcular node false  which is very important step. 
We will do nothing if the node is visited but if it is visited and dfs visited is also true then cycle is present
if not visited we will call the function and ask ke bhhaii agge dekh  ke ajjja cycle present haii kyyyaa hai toh return true kardooo nahii toh dusre neighbour ko
bheejoooooooooooo

*/


#include<bits/stdc++.h>
using namespace std;



//SOLUTION
#include<unordered_map> 
#include<list>

bool checkCycleDFS(int node ,unordered_map<int ,bool> &visited , unordered_map<int ,bool> &dfsVisited, unordered_map <int,list<int>> &adj){
    visited[node]=true;
    dfsVisited[node]=true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected= checkCycleDFS(neighbour ,visited ,dfsVisited ,adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    
    dfsVisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    //create adjacency 
    unordered_map<int ,list<int>> adj;
    for(int i=0 ;i< edges.size(); i++){
        int u= edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
    }
    
    //call dfs for all components
    unordered_map<int ,bool > visited;
    unordered_map<int ,bool > dfsVisited;
    for(int i=0 ;i< n;i++){
        if(!visited[i]){
            bool cycleFound =checkCycleDFS(i ,visited ,dfsVisited ,adj);
            if(cycleFound){
                return 1;
            }
        }
    }
    return 0;
}





int main(){
    
    return 0;
}