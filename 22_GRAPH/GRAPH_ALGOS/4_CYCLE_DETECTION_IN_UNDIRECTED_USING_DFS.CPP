//ALGO
/*
DFS TRAVERSAL KARROO 
EK DATA STRUCTURE MAINTAIN KARKE CHALLO JO TRACK RAKHHEGA KA PARENT NODE KA
AGAR KOI NODE KA VISITED TRUE MARK HAII LEKIN WOH JO HUMARII CURRENT NODE HAI USKA PARENT NAHHI HAII TOH MATLAB CYCLE PRESENT HAI


*/

//QUESTION
/*
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
Example :
In the below graph, there exists a cycle between vertex 1, 2 and 3. 

Note:
1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :
Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
Input Format:
The first line of input contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two single space-separated integers ‘N’ and ‘M’ representing the total number of vertices and edges, respectively.

The next ‘M’ lines contain two single space-separated integers representing an edge of the graph.
Output Format:
For each test case, the only line of output will return “Yes” if there exists a cycle in the graph. Else print “No”.
Note:
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= M <= min(5000, (N * (N - 1)) / 2)
1 <= edges[i][0] <= N 
1 <= edges[i][1] <= N 

Time Limit: 1 sec 
Sample Input 1:
1
3 2
1 2
2 3
Sample Output 1:
No
Explanation Of Sample Output 1:
 The above graph can be represented as 

There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
Sample Input 2:
2
4 0 
4 3
1 4
4 3
3 1
Sample Output 2:
No
Yes


*/


//SOLUTION
#include<bits/stdc++.h>
using namespace std;


#include <queue> 
#include <unordered_map>
#include <list> 

bool isCyclicDFS(int node ,int parent , unordered_map<int ,bool > &visited ,  unordered_map<int, list<int> > &adj ){
visited[node] =true;


for(auto neighbour : adj[node]){
        if(!visited[neighbour]){                     //agar visited true nahhi haiii toh dfs ki call mardii uss node ke liyee or us se bolla ja dekh ke aa agge cycle present hai kya
            bool cycleDetected = isCyclicDFS(neighbour ,node ,visited ,adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour != parent ){        //agar visited true mark haii lekkin apnna jo neighbour haii uskka parent nahhi hai toh dost cycle present haiii
            //cycle present 
            return true;
        }
}
return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjacency list
    unordered_map<int, list<int> > adj;
    for(int i= 0;i <edges.size() ; i++){
        int u =edges[i][0];
        int v =edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int ,bool > visited;
    
    //to handel disconnected component
    for(int i =0 ;i < n;i++){
        if(!visited[i]){
            bool ans=isCyclicDFS(i ,-1 ,visited ,adj);
           if(ans==1){
               return "Yes";
           }
        }
    }
    return "No";
}


int main(){
    
    return 0;
}