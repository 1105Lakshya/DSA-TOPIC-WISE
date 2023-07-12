//DIJKSTAR's ALGO
//SHORTEST PATH IN UNDIRECTED WEIGHTED GRAPH FOR ALL NODES FROM THE SOURCE NODE 








/*
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.
Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.
Example:
Input:
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6

In the given input, the number of vertices is 4, and the number of edges is 5.

In the input, following the number of vertices and edges, three numbers are given. The first number denotes node ‘X’, the second number denotes node ‘Y’ and the third number denotes the distance between node ‘X’ and ‘Y’.

As per the input, there is an edge between node 0 and node 1 and the distance between them is 5.

The vertices 0 and 2 have an edge between them and the distance between them is 8.
The vertices 1 and 2 have an edge between them and the distance between them is 9.
The vertices 1 and 3 have an edge between them and the distance between them is 2.
The vertices 2 and 3 have an edge between them and the distance between them is 6.
Note:
1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.

2. There can be parallel edges i.e. two vertices can be directly connected by more than 1 edge.
Input format:
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two integers ‘V’ and ‘E', denoting the number of vertices in the undirected graph and the number of edges in the undirected graph respectively.

The next ‘E’ lines contain three space-separated integers ‘X’, ‘Y’, and ‘DISTANCE’, denoting a node ‘X’, a node ‘Y’, and the distance between nodes ‘X’ and ‘Y’ respectively.
Output format:
For each test case, print a single line containing ‘V’ space-separated integers that denote the shortest distance for each node from 0 to ‘V’-1, considering that we need the shortest distance from source node 0.

Print the maximum positive integer value, i.e 2147483647, for the disconnected graph.

Output for each test case will be printed in a separate line.
Note
You are not required to print the output, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 50
1 <= V <= 1000
1 <= E <= 3000
0 <= X, Y < V
1 <= DISTANCE[X][Y] <= 10^5


Time limit: 1 sec
Sample input 1
2
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
Sample output 1
0 4 1 2 5
0 5 8 7
Explanation For Sample Output 1
Test case 1:

The source node is node 0.

The shortest distance from node 0 to node 0 is 0.

The shortest distance from node 0 to node 1 is 4. In the above figure, the green path represents this distance. The path goes from node 0->2->1, giving distance = 1+3=4.

The shortest distance from node 0 to node 2 is 1. In the above figure, the red path represents this distance. The path goes from node 0->2, giving distance = 1

The shortest distance from node 0 to node 3 is 2. In the above figure, the pink path represents this distance. The path goes from node 0->3, giving distance = 2.

The shortest distance from node 0 to node 4 is 5. In the above figure, the yellow path represents this distance. The path goes from node 0->2->1->4, giving distance = 1+3+1=5.

Test case 2:

The source node is node 0.

The shortest distance from node 0 to node 0 is 0.

The shortest distance from node 0 to node 1 is 5. In the above figure, the green path represents this distance. The path goes from node 0->1, giving distance = 5.

The shortest distance from node 0 to node 2 is 8. In the above figure, the pink path represents this distance. The path goes from node 0->2, giving distance = 8.

The shortest distance from node 0 to node 3 is 7. In the above figure, the yellow path represents this distance. The path goes from node 0->1->3, giving distance = 7.
Sample input 2:
2
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2 
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6 
7  8 7
5 7
0 1 7
0 2 3
1 2 1
1 3 2
1 4 6
2 3 4
3 4 4 
Sample output 2:
0 4 12 19 21 11 9 8 14
0 4 3 6 10
*/




//ALGOO
/*
step 0 haii ki adjacency list prepare karrloooo with neighbours and weights of the edgges to reach them  unordered_map<node ,list < node ,weight >> 
shuruaat mei sabhhhi node ke liyyeee ek distance array bannnaaliii inititalized with infinity

ek set hum priority queue bhii use kar sakte hai set ki jagaaa  bannnayyya jo store karreegaa  ek pair<distance source node se current node ka , current node>

sabse pehllle initialize karddengeee source node ke liyye or distance walli array mei usske liye distance ko zerro mark krdeenge  or uskii entry set mei krdennge

Now just like we use to do in bfs we will pop the element from the set that will give us the node with minimum distace  then using adjacency list we will update
the distance array if  for the neighbours of the poped array also we will fill the entries  of the neighbours  in the set if they are updated otherwise skip.  repeate the above procedure

distance update karnne ki condition( agar current node tak jo pahuchne mei distance lagaa plus the distance from the adjacency list to the neighbours  cum hai jo value paddi hai in the distance array for that
neighbour node then update in the array otherwise not )



*/


// T.C  O(Elog(V))       E edges       V vertices


#include<bits/stdc++.h>
using namespace std;



//SOLUTION
#include <unordered_map>
#include <list> 
#include <set> 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   //create adjacency list
    unordered_map<int,list<pair<int,int>>>  adj;
    for(int i=0 ;i< edges;i++){
        int u =vec[i][0];
        int v =vec[i][1];
        int weight =vec[i][2];
        
        adj[u].push_back({v ,weight});
        adj[v].push_back({u, weight});
    }
    
    vector<int> dist(vertices , INT_MAX);
    
    set<pair<int ,int>> st;
    dist[source] =0;
    st.insert({0,source});
    
    while(!st.empty()){
        //fetch top node
        pair<int ,int> p =*(st.begin());
        int nodeDistance= p.first;
        int topNode =p.second;
        
        //removing top node
        st.erase(st.begin());
        
        
        //traverse all neighbours
        for(auto neighbour: adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record =st.find({dist[neighbour.first] ,neighbour.first});
                
                //if record found then erase it              //###############     NO NEED TO ERRASEE  khalli insert krnne se bhi sahi chal jayeegaa but just we have to process for some extra nodes     ##################
                // if(record!=st.end()){
                //     st.erase(record);
                // }
                
               // distance update
                dist[neighbour.first] =nodeDistance + neighbour.second;
                
                //record ko dallo
                st.insert({dist[neighbour.first] , neighbour.first});
            }
        }
    }
    return dist;
}


int main(){
    
    return 0;
}












//PRIORITY QUEUE IMPLEMENTATION PREFER THISSSSS

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends






//VISITED NODE IS TO REDUCE TIME COMPLEXITY ITS OPTIONALL

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int Src)
    {
        // Code here
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
        vector<int> mindist(V, INT_MAX);
        mindist[Src]=0;
        pq.push({0, Src});
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int node=p.second;
            int nodeDistance=p.first;
            if(nodeDistance>mindist[node])continue;  //instead of visited




            for(auto ad : adj[node])
            {
                int neighbour=ad[0];
                int weight=ad[1];
                if(nodeDistance+weight<mindist[neighbour])
                {
                    mindist[neighbour]=nodeDistance+weight;
                    pq.push({mindist[neighbour], neighbour});
                }
            }
        }
        return mindist;
    }
};








//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends






