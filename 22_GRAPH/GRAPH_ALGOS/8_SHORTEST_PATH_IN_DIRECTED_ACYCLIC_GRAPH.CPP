// WE CAN USE DIJKSTRAS ALGORITHM FOR DAG BUT ONLY IF NEGATIVE WEIGHTS ARE NOT GIVEN ON THE EDGES SINCE ITS A GREEDY ALGORITHM
//IF NEGATIVE WEIGHTS ARE GIVEN ON THE EDGES THEN USE THIS ALGOOOOO  and this algos time complexity is way better than bellman ford algooo
// infact it is better than dijkstras algoooo



//QUESTION

/*
A common prerequisite before any graph problem is the knowledge of graphs and related terminologies such as recursion, stacks, queues, trees, and the 2 standard algorithms DFS, BFS, and topological sorting. Without knowing these basic algorithms and data structures, jumping on to the shortest path problems in graphs is not recommended. Nevertheless, we’ll try to cover each point in-depth that is required to find the shortest path in a directed acyclic graph.

What do we mean by the Shortest Path in a directed acyclic graph?

Well, it’s a trivial question, but still, for the sake of clarity, we’ll define that let

G = (V, E) be a directed graph with E edges and V vertices.

Let T be the shortest path between any 2 vertices in the graph such that there is no other path in the graph between any 2 vertices whose sum of edge weights is less than T’s sum of edge weights. 

NOTE: shortest path between 2 vertices is defined only when the vertices are in the same graph, i.e., the graph should not be disconnected.

Let’s look at an example first.

Given a weighted DAG G,
 

Input:  Starting Node Src = 1 

Output: List of shortest distances denoting the shortest path from ‘Src’ to all other nodes in the DAG.

For the above DAG, we will return {INF, 0, 2, 6, 5, 3}

So the problem is to find the shortest path from a given source to All other nodes in the weighted DAG.
*/



//QUESTION KA SAAR

/*
SOURCE NODE SE SARII  NODES TAK JANNEE KA SHORTEST DISTANCE JO HOGAAA WO EK ARRAYY MEI STORE KARKKE DOOO
DISTANCE --->  DISTANCE EDGES PE JO WEIGHTS HAII UNKKA SUMM KARKKEE AYYYEEGGAAA  AGAR KOII TARIIKA NI HAII PAHUCHHNE KAA TOH MATLAN DISTANCE INFINITY HAII
*/

//Approach
/*
here adjcency list will have the following structure      unordered_map<node , list<neighbour, weight of edge betweeen node and neighbour>> 

first do topological sorting using dfs traversal and get the stack that we maintain in topological sorting
then make an array and intiallizeee it with infinityy  
mark the source node with 0.
Now start traversing the stack jab tak stack khalli ni ho jatta usmei se element utthaa te rahhoo 
check karoo ki jo stack ke top se uthhayyaa hai uskii distance ifinity haii kyyaaa
if distance is infinity skip it otherwise 
take the node for which the distance is not infnity and from the adjacency matrix deekhoo uss node se kahha kahha jaa sakktee hooo
jahhha jaa sakteee ho wahh present node kaa distanece plus jo distance wahh tak janne mei or laggegaa jo adjacency matrix se millegga wo add krkee dekkhoo 
agar uss address pe uss se chhottii valuue haii toh koii change krnne ki jruraat nii haiii agar uss address pe value baddii haii tohhh jo humaari value aaii hai
usse us se replace karrdooo after the traversal your anwer will be your arrayy
*/

#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int ,list< pair<int,int>> >adj;
    void addEdge(int u ,int v ,int weight){
        pair<int ,int> p =make_pair(v,weight) ;
        adj[u].push_back(p);

    }

    void printAdj();
    
    void dfs(int node ,unordered_map<int ,bool > &vis ,stack <int> &topo){
        vis[node]=true;

        for(auto neighbour : adj[node]){
            if(!vis[neighbour.first]){
                dfs(neighbour.first, vis ,topo);
            }
        }
        topo.push(node);
    }


    void getShortestPath(int src , vector<int>  &dist , stack<int> &topo){
        dist[src] = 0;

        while(!topo.empty()){
            int top = topo.top();
            topo.pop(); 

            if(dist[top]  !=INT_MAX){
                    for(auto i: adj[top]){
                        if(dist[top] + i.second < dist[i.first ]){
                            dist[i.first] = dist[top] +i.second;
                        }
                    }
            }
            }
    }
};


void graph :: printAdj(){
    for(auto i: adj){
        cout<<i.first<< " -> ";
        for(auto j: i.second){
            cout<<"["<<j.first<<","<<j.second<<"]"<< "  ";
        }cout<<endl;
    }
}


 
 
int main(){
    
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int n=6;
    unordered_map<int ,bool > visited;
    stack<int> s;

    for(int i=0 ;i< n;i++){
        if(!visited[i]){
            g.dfs(i ,visited ,s);
        }
    }



    int src=1;
    vector<int> dist(n ,INT_MAX);

    g.getShortestPath(src, dist ,s);

    cout<<"answer is "; 
    for(int i=0 ;i< n ;i++){
        cout<< dist[i]<< " ";
    }
    cout<<endl;
    return 0;
}